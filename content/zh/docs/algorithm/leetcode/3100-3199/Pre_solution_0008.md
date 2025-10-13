---
title: "3170_删除星号以后字典序最小的字符串"
date: 2025-10-08T18:40:09+08:00
weight: 8
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 数学, 数据库, 数组, 栈, 模拟, 线段树, 组合数学, 贪心]
---

{{< markmap >}}
### [3170_删除星号以后字典序最小的字符串](#3170)
#### [栈](#3170)
#### [贪心](#3170)
#### [哈希表](#3170)
#### [字符串](#3170)
#### [堆（优先队列）](#3170)
### [3171_找到按位或最接近 K 的子数组](#3171)
#### [位运算](#3171)
#### [线段树](#3171)
#### [数组](#3171)
#### [二分查找](#3171)
### [3172_第二天验证 🔒](#3172)
#### [数据库](#3172)
### [3173_相邻元素的按位或 🔒](#3173)
#### [位运算](#3173)
#### [数组](#3173)
### [3174_清除数字](#3174)
#### [栈](#3174)
#### [字符串](#3174)
#### [模拟](#3174)
### [3175_找到连续赢 K 场比赛的第一位玩家](#3175)
#### [数组](#3175)
#### [模拟](#3175)
### [3176_求出最长好子序列 I](#3176)
#### [数组](#3176)
#### [哈希表](#3176)
#### [动态规划](#3176)
### [3177_求出最长好子序列 II](#3177)
#### [数组](#3177)
#### [哈希表](#3177)
#### [动态规划](#3177)
### [3178_找出 K 秒后拿着球的孩子](#3178)
#### [数学](#3178)
#### [模拟](#3178)
### [3179_K 秒后第 N 个元素的值](#3179)
#### [数组](#3179)
#### [数学](#3179)
#### [组合数学](#3179)
#### [前缀和](#3179)
#### [模拟](#3179)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3170_删除星号以后字典序最小的字符串
___
#### 栈
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 堆（优先队列）
---
### 3171_找到按位或最接近 K 的子数组
___
#### 位运算
___
#### 线段树
___
#### 数组
___
#### 二分查找
---
### 3172_第二天验证 🔒
___
#### 数据库
---
### 3173_相邻元素的按位或 🔒
___
#### 位运算
___
#### 数组
---
### 3174_清除数字
___
#### 栈
___
#### 字符串
___
#### 模拟
---
### 3175_找到连续赢 K 场比赛的第一位玩家
___
#### 数组
___
#### 模拟
---
### 3176_求出最长好子序列 I
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 3177_求出最长好子序列 II
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 3178_找出 K 秒后拿着球的孩子
___
#### 数学
___
#### 模拟
---
### 3179_K 秒后第 N 个元素的值
___
#### 数组
___
#### 数学
___
#### 组合数学
___
#### 前缀和
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字符串 | 数学 | 数据库 |
| 数组 | 栈 | 模拟 |
| 线段树 | 组合数学 | 贪心 |

# [3170. 删除星号以后字典序最小的字符串](https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars){#3170}

{{< tabs "3170" >}}

{{% tab "python" %}}
```python
class Solution:
    def clearStars(self, s: str) -> str:
        g = defaultdict(list)
        n = len(s)
        rem = [False] * n
        for i, c in enumerate(s):
            if c == "*":
                rem[i] = True
                for a in ascii_lowercase:
                    if g[a]:
                        rem[g[a].pop()] = True
                        break
            else:
                g[c].append(i)
        return "".join(c for i, c in enumerate(s) if not rem[i])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String clearStars(String s) {
        Deque<Integer>[] g = new Deque[26];
        Arrays.setAll(g, k -> new ArrayDeque<>());
        int n = s.length();
        boolean[] rem = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!g[j].isEmpty()) {
                        rem[g[j].pop()] = true;
                        break;
                    }
                }
            } else {
                g[s.charAt(i) - 'a'].push(i);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            if (!rem[i]) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string clearStars(string s) {
        stack<int> g[26];
        int n = s.length();
        vector<bool> rem(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!g[j].empty()) {
                        rem[g[j].top()] = true;
                        g[j].pop();
                        break;
                    }
                }
            } else {
                g[s[i] - 'a'].push(i);
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (!rem[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func clearStars(s string) string {
	g := make([][]int, 26)
	n := len(s)
	rem := make([]bool, n)
	for i, c := range s {
		if c == '*' {
			rem[i] = true
			for j := 0; j < 26; j++ {
				if len(g[j]) > 0 {
					rem[g[j][len(g[j])-1]] = true
					g[j] = g[j][:len(g[j])-1]
					break
				}
			}
		} else {
			g[c-'a'] = append(g[c-'a'], i)
		}
	}
	ans := []byte{}
	for i := range s {
		if !rem[i] {
			ans = append(ans, s[i])
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function clearStars(s: string): string {
    const g: number[][] = Array.from({ length: 26 }, () => []);
    const n = s.length;
    const rem: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        if (s[i] === '*') {
            rem[i] = true;
            for (let j = 0; j < 26; ++j) {
                if (g[j].length) {
                    rem[g[j].pop()!] = true;
                    break;
                }
            }
        } else {
            g[s.charCodeAt(i) - 97].push(i);
        }
    }
    return s
        .split('')
        .filter((_, i) => !rem[i])
        .join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn clear_stars(s: String) -> String {
        let n = s.len();
        let s_bytes = s.as_bytes();
        let mut g: Vec<Vec<usize>> = vec![vec![]; 26];
        let mut rem = vec![false; n];
        let chars: Vec<char> = s.chars().collect();

        for (i, &ch) in chars.iter().enumerate() {
            if ch == '*' {
                rem[i] = true;
                for j in 0..26 {
                    if let Some(idx) = g[j].pop() {
                        rem[idx] = true;
                        break;
                    }
                }
            } else {
                g[(ch as u8 - b'a') as usize].push(i);
            }
        }

        chars
            .into_iter()
            .enumerate()
            .filter_map(|(i, ch)| if !rem[i] { Some(ch) } else { None })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string ClearStars(string s) {
        int n = s.Length;
        List<int>[] g = new List<int>[26];
        for (int i = 0; i < 26; i++) {
            g[i] = new List<int>();
        }

        bool[] rem = new bool[n];
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; j++) {
                    if (g[j].Count > 0) {
                        int idx = g[j][g[j].Count - 1];
                        g[j].RemoveAt(g[j].Count - 1);
                        rem[idx] = true;
                        break;
                    }
                }
            } else {
                g[ch - 'a'].Add(i);
            }
        }

        var ans = new System.Text.StringBuilder();
        for (int i = 0; i < n; i++) {
            if (!rem[i]) {
                ans.Append(s[i]);
            }
        }

        return ans.ToString();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。它可能包含任意数量的&nbsp;<code>'*'</code>&nbsp;字符。你的任务是删除所有的&nbsp;<code>'*'</code>&nbsp;字符。</p>

<p>当字符串还存在至少一个&nbsp;<code>'*'</code>&nbsp;字符时，你可以执行以下操作：</p>

<ul>
	<li>删除最左边的&nbsp;<code>'*'</code>&nbsp;字符，同时删除该星号字符左边一个字典序 <strong>最小</strong>&nbsp;的字符。如果有多个字典序最小的字符，你可以删除它们中的任意一个。</li>
</ul>

<p>请你返回删除所有&nbsp;<code>'*'</code>&nbsp;字符以后，剩余字符连接而成的 <span data-keyword="lexicographically-smaller-string">字典序最小</span> 的字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "aaba*"</span></p>

<p><span class="example-io"><b>输出：</b>"aab"</span></p>

<p><strong>解释：</strong></p>

<p>删除 <code>'*'</code>&nbsp;号和它左边的其中一个&nbsp;<code>'a'</code>&nbsp;字符。如果我们选择删除&nbsp;<code>s[3]</code>&nbsp;，<code>s</code>&nbsp;字典序最小。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>"abc"</span></p>

<p><strong>解释：</strong></p>

<p>字符串中没有&nbsp;<code>'*'</code>&nbsp;字符。<!-- notionvc: ff07e34f-b1d6-41fb-9f83-5d0ba3c1ecde --></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只含有小写英文字母和&nbsp;<code>'*'</code>&nbsp;字符。</li>
	<li>输入保证操作可以删除所有的&nbsp;<code>'*'</code>&nbsp;字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：按字符记录下标

我们定义一个数组 $g$，用于记录每个字符的下标列表，定义一个长度为 $n$ 的布尔数组 $rem$，用于记录每个字符是否需要删除。

遍历字符串 $s$：

如果当前字符是星号，我们就需要删除它，因此我们将 $rem[i]$ 标记为已删除。同时，我们需要删除此时字典序最小且下标最大的字符。我们从小到大遍历 $26$ 个小写字母，如果 $g[a]$ 不为空，我们就删除 $g[a]$ 中的最后一个下标，并将 $rem$ 中对应的下标置为已删除。

如果当前字符不是星号，我们就将当前字符的下标加入 $g$ 中。

最后，我们遍历 $s$，将未删除的字符拼接起来即可。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 为字符集大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def clearStars(self, s: str) -> str:
        g = defaultdict(list)
        n = len(s)
        rem = [False] * n
        for i, c in enumerate(s):
            if c == "*":
                rem[i] = True
                for a in ascii_lowercase:
                    if g[a]:
                        rem[g[a].pop()] = True
                        break
            else:
                g[c].append(i)
        return "".join(c for i, c in enumerate(s) if not rem[i])
```

#### Java

```java
class Solution {
    public String clearStars(String s) {
        Deque<Integer>[] g = new Deque[26];
        Arrays.setAll(g, k -> new ArrayDeque<>());
        int n = s.length();
        boolean[] rem = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!g[j].isEmpty()) {
                        rem[g[j].pop()] = true;
                        break;
                    }
                }
            } else {
                g[s.charAt(i) - 'a'].push(i);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            if (!rem[i]) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string clearStars(string s) {
        stack<int> g[26];
        int n = s.length();
        vector<bool> rem(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!g[j].empty()) {
                        rem[g[j].top()] = true;
                        g[j].pop();
                        break;
                    }
                }
            } else {
                g[s[i] - 'a'].push(i);
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (!rem[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func clearStars(s string) string {
	g := make([][]int, 26)
	n := len(s)
	rem := make([]bool, n)
	for i, c := range s {
		if c == '*' {
			rem[i] = true
			for j := 0; j < 26; j++ {
				if len(g[j]) > 0 {
					rem[g[j][len(g[j])-1]] = true
					g[j] = g[j][:len(g[j])-1]
					break
				}
			}
		} else {
			g[c-'a'] = append(g[c-'a'], i)
		}
	}
	ans := []byte{}
	for i := range s {
		if !rem[i] {
			ans = append(ans, s[i])
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function clearStars(s: string): string {
    const g: number[][] = Array.from({ length: 26 }, () => []);
    const n = s.length;
    const rem: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        if (s[i] === '*') {
            rem[i] = true;
            for (let j = 0; j < 26; ++j) {
                if (g[j].length) {
                    rem[g[j].pop()!] = true;
                    break;
                }
            }
        } else {
            g[s.charCodeAt(i) - 97].push(i);
        }
    }
    return s
        .split('')
        .filter((_, i) => !rem[i])
        .join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn clear_stars(s: String) -> String {
        let n = s.len();
        let s_bytes = s.as_bytes();
        let mut g: Vec<Vec<usize>> = vec![vec![]; 26];
        let mut rem = vec![false; n];
        let chars: Vec<char> = s.chars().collect();

        for (i, &ch) in chars.iter().enumerate() {
            if ch == '*' {
                rem[i] = true;
                for j in 0..26 {
                    if let Some(idx) = g[j].pop() {
                        rem[idx] = true;
                        break;
                    }
                }
            } else {
                g[(ch as u8 - b'a') as usize].push(i);
            }
        }

        chars
            .into_iter()
            .enumerate()
            .filter_map(|(i, ch)| if !rem[i] { Some(ch) } else { None })
            .collect()
    }
}
```

#### C#

```cs
public class Solution {
    public string ClearStars(string s) {
        int n = s.Length;
        List<int>[] g = new List<int>[26];
        for (int i = 0; i < 26; i++) {
            g[i] = new List<int>();
        }

        bool[] rem = new bool[n];
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '*') {
                rem[i] = true;
                for (int j = 0; j < 26; j++) {
                    if (g[j].Count > 0) {
                        int idx = g[j][g[j].Count - 1];
                        g[j].RemoveAt(g[j].Count - 1);
                        rem[idx] = true;
                        break;
                    }
                }
            } else {
                g[ch - 'a'].Add(i);
            }
        }

        var ans = new System.Text.StringBuilder();
        for (int i = 0; i < n; i++) {
            if (!rem[i]) {
                ans.Append(s[i]);
            }
        }

        return ans.ToString();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3171. 找到按位或最接近 K 的子数组](https://leetcode.cn/problems/find-subarray-with-bitwise-or-closest-to-k){#3171}

{{< tabs "3171" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        ans = inf
        s = set()
        for x in nums:
            s = {x | y for y in s} | {x}
            ans = min(ans, min(abs(y - k) for y in s))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int ans = Integer.MAX_VALUE;
        Set<Integer> pre = new HashSet<>();
        for (int x : nums) {
            Set<Integer> cur = new HashSet<>();
            for (int y : pre) {
                cur.add(x | y);
            }
            cur.add(x);
            for (int y : cur) {
                ans = Math.min(ans, Math.abs(y - k));
            }
            pre = cur;
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
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        unordered_set<int> pre;
        for (int x : nums) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int y : pre) {
                cur.insert(x | y);
            }
            for (int y : cur) {
                ans = min(ans, abs(y - k));
            }
            pre = move(cur);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDifference(nums []int, k int) int {
	ans := math.MaxInt32
	pre := map[int]bool{}
	for _, x := range nums {
		cur := map[int]bool{x: true}
		for y := range pre {
			cur[x|y] = true
		}
		for y := range cur {
			ans = min(ans, max(y-k, k-y))
		}
		pre = cur
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDifference(nums: number[], k: number): number {
    let ans = Infinity;
    let pre = new Set<number>();
    for (const x of nums) {
        const cur = new Set<number>();
        cur.add(x);
        for (const y of pre) {
            cur.add(x | y);
        }
        for (const y of cur) {
            ans = Math.min(ans, Math.abs(y - k));
        }
        pre = cur;
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

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。你需要找到&nbsp;<code>nums</code>&nbsp;的一个&nbsp;<span data-keyword="subarray-nonempty">子数组</span>&nbsp;，满足子数组中所有元素按位或运算 <code>OR</code> 的值与 <code>k</code>&nbsp;的 <strong>绝对差</strong>&nbsp;尽可能 <strong>小</strong>&nbsp;。换言之，你需要选择一个子数组&nbsp;<code>nums[l..r]</code>&nbsp;满足 <code>|k - (nums[l] OR nums[l + 1] ... OR nums[r])|</code>&nbsp;最小。</p>

<p>请你返回 <strong>最小</strong>&nbsp;的绝对差值。</p>

<p><strong>子数组 </strong>是数组中连续的&nbsp;<strong>非空</strong>&nbsp;元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,4,5], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>nums[0..1]</code> 的按位 <code>OR</code> 运算值为 3 ，得到最小差值&nbsp;<code>|3 - 3| = 0</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,1,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>nums[1..1]</code> 的按位 <code>OR</code> 运算值为 3 ，得到最小差值&nbsp;<code>|3 - 2| = 1</code> 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1], k = 10</span></p>

<p><span class="example-io"><b>输出：</b>9</span></p>

<p><strong>解释：</strong></p>

<p>只有一个子数组，按位 <code>OR</code> 运算值为 1 ，得到最小差值&nbsp;<code>|10 - 1| = 9</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 位运算

根据题目描述，我们需要求出数组 $\textit{nums}$ 下标 $l$ 到 $r$ 的元素的按位或运算的结果，即 $\textit{nums}[l] \lor \textit{nums}[l + 1] \lor \cdots \lor \textit{nums}[r]$。其中 $\lor$ 表示按位或运算。

如果我们每次固定右端点 $r$，那么左端点 $l$ 的范围是 $[0, r]$。每次移动右端点 $r$，按位或的结果只会变大，我们用一个变量 $s$ 记录当前的按位或的结果，如果 $s$ 大于 $k$，我们就将左端点 $l$ 向右移动，直到 $s$ 小于等于 $k$。在移动左端点 $l$ 的过程中，我们需要维护一个数组 $cnt$，记录当前区间内每个二进制位上 $0$ 的个数，当 $cnt[h]$ 为 $0$ 时，说明当前区间内的元素在第 $h$ 位上都为 $0$，我们就可以将 $s$ 的第 $h$ 位设置为 $0$。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 和 $M$ 分别是数组 $\textit{nums}$ 的长度和数组 $\textit{nums}$ 中元素的最大值。

相似题目：

-   [3097. 或值至少为 K 的最短子数组 II](https://github.com/doocs/leetcode/blob/main/solution/3000-3099/3097.Shortest%20Subarray%20With%20OR%20at%20Least%20K%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        m = max(nums).bit_length()
        cnt = [0] * m
        s = i = 0
        ans = inf
        for j, x in enumerate(nums):
            s |= x
            ans = min(ans, abs(s - k))
            for h in range(m):
                if x >> h & 1:
                    cnt[h] += 1
            while i < j and s > k:
                y = nums[i]
                for h in range(m):
                    if y >> h & 1:
                        cnt[h] -= 1
                        if cnt[h] == 0:
                            s ^= 1 << h
                i += 1
                ans = min(ans, abs(s - k))
        return ans
```

#### Java

```java
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }
        int m = 32 - Integer.numberOfLeadingZeros(mx);
        int[] cnt = new int[m];
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            ans = Math.min(ans, Math.abs(s - k));
            for (int h = 0; h < m; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            while (i < j && s > k) {
                for (int h = 0; h < m; ++h) {
                    if ((nums[i] >> h & 1) == 1 && --cnt[h] == 0) {
                        s ^= 1 << h;
                    }
                }
                ++i;
                ans = Math.min(ans, Math.abs(s - k));
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
    int minimumDifference(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int m = 32 - __builtin_clz(mx);
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> cnt(m);
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            ans = min(ans, abs(s - k));
            for (int h = 0; h < m; ++h) {
                if (nums[j] >> h & 1) {
                    ++cnt[h];
                }
            }
            while (i < j && s > k) {
                for (int h = 0; h < m; ++h) {
                    if (nums[i] >> h & 1 && --cnt[h] == 0) {
                        s ^= 1 << h;
                    }
                }
                ans = min(ans, abs(s - k));
                ++i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDifference(nums []int, k int) int {
	m := bits.Len(uint(slices.Max(nums)))
	cnt := make([]int, m)
	ans := math.MaxInt32
	s, i := 0, 0
	for j, x := range nums {
		s |= x
		ans = min(ans, abs(s-k))
		for h := 0; h < m; h++ {
			if x>>h&1 == 1 {
				cnt[h]++
			}
		}
		for i < j && s > k {
			y := nums[i]
			for h := 0; h < m; h++ {
				if y>>h&1 == 1 {
					cnt[h]--
					if cnt[h] == 0 {
						s ^= 1 << h
					}
				}
			}
			ans = min(ans, abs(s-k))
			i++
		}
	}
	return ans
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
function minimumDifference(nums: number[], k: number): number {
    const m = Math.max(...nums).toString(2).length;
    const n = nums.length;
    const cnt: number[] = Array(m).fill(0);
    let ans = Infinity;
    for (let i = 0, j = 0, s = 0; j < n; ++j) {
        s |= nums[j];
        ans = Math.min(ans, Math.abs(s - k));
        for (let h = 0; h < m; ++h) {
            if ((nums[j] >> h) & 1) {
                ++cnt[h];
            }
        }
        while (i < j && s > k) {
            for (let h = 0; h < m; ++h) {
                if ((nums[i] >> h) & 1 && --cnt[h] === 0) {
                    s ^= 1 << h;
                }
            }
            ans = Math.min(ans, Math.abs(s - k));
            ++i;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 枚举

根据题目描述，我们需要求出数组 $nums$ 下标 $l$ 到 $r$ 的元素的按位或运算的结果，即 $nums[l] \lor nums[l + 1] \lor \cdots \lor nums[r]$。其中 $\lor$ 表示按位或运算。

如果我们每次固定右端点 $r$，那么左端点 $l$ 的范围是 $[0, r]$。由于按位或之和随着 $l$ 的减小而单调递增，并且 $\textit{nums}[i]$ 的值不超过 $10^9$，因此区间 $[0, r]$ 最多只有 $30$ 种不同的值。因此，我们可以用一个集合来维护所有的 $nums[l] \lor nums[l + 1] \lor \cdots \lor nums[r]$ 的值。当我们从 $r$ 遍历到 $r+1$ 时，以 $r+1$ 为右端点的值，就是集合中每个值与 $nums[r + 1]$ 进行按位或运算得到的值，再加上 $nums[r + 1]$ 本身。因此，我们只需要枚举集合中的每个值，与 $nums[r]$ 进行按位或运算，就可以得到以 $r$ 为右端点的所有值，将每个值与 $k$ 相减后取绝对值，就可以得到以 $r$ 为右端点的所有值与 $k$ 的差的绝对值，其中的最小值就是答案。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和数组 $nums$ 中的最大值。

相似题目：

-   [1521. 找到最接近目标值的函数值](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1521.Find%20a%20Value%20of%20a%20Mysterious%20Function%20Closest%20to%20Target/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        ans = inf
        s = set()
        for x in nums:
            s = {x | y for y in s} | {x}
            ans = min(ans, min(abs(y - k) for y in s))
        return ans
```

#### Java

```java
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int ans = Integer.MAX_VALUE;
        Set<Integer> pre = new HashSet<>();
        for (int x : nums) {
            Set<Integer> cur = new HashSet<>();
            for (int y : pre) {
                cur.add(x | y);
            }
            cur.add(x);
            for (int y : cur) {
                ans = Math.min(ans, Math.abs(y - k));
            }
            pre = cur;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        unordered_set<int> pre;
        for (int x : nums) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int y : pre) {
                cur.insert(x | y);
            }
            for (int y : cur) {
                ans = min(ans, abs(y - k));
            }
            pre = move(cur);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDifference(nums []int, k int) int {
	ans := math.MaxInt32
	pre := map[int]bool{}
	for _, x := range nums {
		cur := map[int]bool{x: true}
		for y := range pre {
			cur[x|y] = true
		}
		for y := range cur {
			ans = min(ans, max(y-k, k-y))
		}
		pre = cur
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDifference(nums: number[], k: number): number {
    let ans = Infinity;
    let pre = new Set<number>();
    for (const x of nums) {
        const cur = new Set<number>();
        cur.add(x);
        for (const y of pre) {
            cur.add(x | y);
        }
        for (const y of cur) {
            ans = Math.min(ans, Math.abs(y - k));
        }
        pre = cur;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3172. 第二天验证 🔒](https://leetcode.cn/problems/second-day-verification){#3172}

{{< tabs "3172" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id
FROM
    Emails AS e
    JOIN texts AS t
        ON e.email_id = t.email_id
        AND DATEDIFF(action_date, signup_date) = 1
        AND signup_action = 'Verified'
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>emails</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| email_id    | int      |
| user_id     | int      |
| signup_date | datetime |
+-------------+----------+
(email_id, user_id) 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含 email ID，user ID 和注册日期。
</pre>

<p>表：<code>texts</code></p>

<pre>
+---------------+----------+
| Column Name   | Type     | 
+---------------+----------+
| text_id       | int      |
| email_id      | int      |
| signup_action | enum     |
| action_date   | datetime |
+---------------+----------+
(text_id, email_id) 是这张表的主键（有不同值的列的组合）。
signup_action 是 ('Verified', 'Not Verified') 的枚举类型。
这张表的每一行包含 text ID，email ID，注册操作和操作日期。
</pre>

<p>编写一个解决方案来找到&nbsp;<strong>第二天验证注册</strong>&nbsp;的用户 ID。</p>

<p>返回结果表以&nbsp;<code>user_id</code> <strong>升序&nbsp;</strong>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><b>输入：</b></p>

<p>emails 表：</p>

<pre class="example-io">
+----------+---------+---------------------+
| email_id | user_id | signup_date         |
+----------+---------+---------------------+
| 125      | 7771    | 2022-06-14 09:30:00|
| 433      | 1052    | 2022-07-09 08:15:00|
| 234      | 7005    | 2022-08-20 10:00:00|
+----------+---------+---------------------+
</pre>

<p>texts 表：</p>

<pre class="example-io">
+---------+----------+--------------+---------------------+
| text_id | email_id | signup_action| action_date         |
+---------+----------+--------------+---------------------+
| 1       | 125      | Verified     | 2022-06-15 08:30:00|
| 2       | 433      | Not Verified | 2022-07-10 10:45:00|
| 4       | 234      | Verified     | 2022-08-21 09:30:00|
+---------+----------+--------------+---------------------+
    </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+---------+
| user_id |
+---------+
| 7005    |
| 7771    |
+---------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>user_id 为 7005 的用户在 2022-08-20 10:00:00 注册并且在第二天验证。</li>
	<li>user_id 为 7771 的用户在 2022-06-14 09:30:00 注册并且在第二天验证。</li>
</ul>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双表关联

我们可以通过内连接两个表，然后根据 `DATEDIFF` 函数计算出注册日期和操作日期的差值是否等于 1，以及注册操作是否为 `Verified`，来筛选出满足条件的用户 ID。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT user_id
FROM
    Emails AS e
    JOIN texts AS t
        ON e.email_id = t.email_id
        AND DATEDIFF(action_date, signup_date) = 1
        AND signup_action = 'Verified'
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3173. 相邻元素的按位或 🔒](https://leetcode.cn/problems/bitwise-or-of-adjacent-elements){#3173}

{{< tabs "3173" >}}

{{% tab "python" %}}
```python
class Solution:
    def orArray(self, nums: List[int]) -> List[int]:
        return [a | b for a, b in pairwise(nums)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] orArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            ans[i] = nums[i] | nums[i + 1];
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
    vector<int> orArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            ans[i] = nums[i] | nums[i + 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func orArray(nums []int) (ans []int) {
	for i, x := range nums[1:] {
		ans = append(ans, x|nums[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function orArray(nums: number[]): number[] {
    return nums.slice(0, -1).map((v, i) => v | nums[i + 1]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>nums</code>，返回一个长度为 <code>n - 1</code>&nbsp;的数组&nbsp;<code>answer</code>&nbsp;使得&nbsp;<code>answer[i] = nums[i] | nums[i + 1]</code>，其中&nbsp;<code>|</code>&nbsp;表示按位&nbsp;<code>OR</code>&nbsp;操作。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,3,7,15]</span></p>

<p><strong>输出：</strong><span class="example-io">[3,7,15]</span></p>

<p>&nbsp;</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [8,4,2]</span></p>

<p><strong>输出：</strong><span class="example-io">[12,6]</span></p>

<p>&nbsp;</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [5,4,9,11]</span></p>

<p><strong>输出：</strong><span class="example-io">[5,13,11]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们遍历数组的前 $n - 1$ 个元素，对于每个元素，计算它和它的下一个元素的按位或值，将结果存入答案数组中。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def orArray(self, nums: List[int]) -> List[int]:
        return [a | b for a, b in pairwise(nums)]
```

#### Java

```java
class Solution {
    public int[] orArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            ans[i] = nums[i] | nums[i + 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            ans[i] = nums[i] | nums[i + 1];
        }
        return ans;
    }
};
```

#### Go

```go
func orArray(nums []int) (ans []int) {
	for i, x := range nums[1:] {
		ans = append(ans, x|nums[i])
	}
	return
}
```

#### TypeScript

```ts
function orArray(nums: number[]): number[] {
    return nums.slice(0, -1).map((v, i) => v | nums[i + 1]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3174. 清除数字](https://leetcode.cn/problems/clear-digits){#3174}

{{< tabs "3174" >}}

{{% tab "python" %}}
```python
class Solution:
    def clearDigits(self, s: str) -> str:
        stk = []
        for c in s:
            if c.isdigit():
                stk.pop()
            else:
                stk.append(c)
        return "".join(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String clearDigits(String s) {
        StringBuilder stk = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                stk.deleteCharAt(stk.length() - 1);
            } else {
                stk.append(c);
            }
        }
        return stk.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string clearDigits(string s) {
        string stk;
        for (char c : s) {
            if (isdigit(c)) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func clearDigits(s string) string {
	stk := []byte{}
	for i := range s {
		if s[i] >= '0' && s[i] <= '9' {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, s[i])
		}
	}
	return string(stk)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function clearDigits(s: string): string {
    const stk: string[] = [];
    for (const c of s) {
        if (!isNaN(parseInt(c))) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>你的任务是重复以下操作删除 <strong>所有</strong>&nbsp;数字字符：</p>

<ul>
	<li>删除 <strong>第一个数字字符</strong>&nbsp;以及它左边 <strong>最近</strong>&nbsp;的 <strong>非数字</strong>&nbsp;字符。</li>
</ul>

<p>请你返回删除所有数字字符以后剩下的字符串。</p>

<p><strong>注意</strong>，该操作不能对左侧没有任何非数字字符的数字执行。</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>"abc"</span></p>

<p><strong>解释：</strong></p>

<p>字符串中没有数字。<!-- notionvc: ff07e34f-b1d6-41fb-9f83-5d0ba3c1ecde --></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "cb34"</span></p>

<p><span class="example-io"><b>输出：</b>""</span></p>

<p><b>解释：</b></p>

<p>一开始，我们对&nbsp;<code>s[2]</code>&nbsp;执行操作，<code>s</code>&nbsp;变为&nbsp;<code>"c4"</code>&nbsp;。</p>

<p>然后对&nbsp;<code>s[1]</code>&nbsp;执行操作，<code>s</code>&nbsp;变为&nbsp;<code>""</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和数字字符。</li>
	<li>输入保证所有数字都可以按以上操作被删除。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈 + 模拟

我们用一个栈 `stk` 来模拟这个过程，遍历字符串 `s`，如果当前字符是数字，就弹出栈顶元素，否则将当前字符入栈。

最后将栈中的元素拼接成字符串返回。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def clearDigits(self, s: str) -> str:
        stk = []
        for c in s:
            if c.isdigit():
                stk.pop()
            else:
                stk.append(c)
        return "".join(stk)
```

#### Java

```java
class Solution {
    public String clearDigits(String s) {
        StringBuilder stk = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                stk.deleteCharAt(stk.length() - 1);
            } else {
                stk.append(c);
            }
        }
        return stk.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string clearDigits(string s) {
        string stk;
        for (char c : s) {
            if (isdigit(c)) {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk;
    }
};
```

#### Go

```go
func clearDigits(s string) string {
	stk := []byte{}
	for i := range s {
		if s[i] >= '0' && s[i] <= '9' {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, s[i])
		}
	}
	return string(stk)
}
```

#### TypeScript

```ts
function clearDigits(s: string): string {
    const stk: string[] = [];
    for (const c of s) {
        if (!isNaN(parseInt(c))) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3175. 找到连续赢 K 场比赛的第一位玩家](https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row){#3175}

{{< tabs "3175" >}}

{{% tab "python" %}}
```python
class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        n = len(skills)
        k = min(k, n - 1)
        i = cnt = 0
        for j in range(1, n):
            if skills[i] < skills[j]:
                i = j
                cnt = 1
            else:
                cnt += 1
            if cnt == k:
                break
        return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        int n = skills.length;
        k = Math.min(k, n - 1);
        int i = 0, cnt = 0;
        for (int j = 1; j < n; ++j) {
            if (skills[i] < skills[j]) {
                i = j;
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        k = min(k, n - 1);
        int i = 0, cnt = 0;
        for (int j = 1; j < n; ++j) {
            if (skills[i] < skills[j]) {
                i = j;
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return i;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findWinningPlayer(skills []int, k int) int {
	n := len(skills)
	k = min(k, n-1)
	i, cnt := 0, 0
	for j := 1; j < n; j++ {
		if skills[i] < skills[j] {
			i = j
			cnt = 1
		} else {
			cnt++
		}
		if cnt == k {
			break
		}
	}
	return i
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findWinningPlayer(skills: number[], k: number): number {
    const n = skills.length;
    k = Math.min(k, n - 1);
    let [i, cnt] = [0, 0];
    for (let j = 1; j < n; ++j) {
        if (skills[i] < skills[j]) {
            i = j;
            cnt = 1;
        } else {
            ++cnt;
        }
        if (cnt === k) {
            break;
        }
    }
    return i;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有&nbsp;<code>n</code>&nbsp;位玩家在进行比赛，玩家编号依次为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>skills</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>skills[i]</code>&nbsp;是第 <code>i</code>&nbsp;位玩家的技能等级。<code>skills</code>&nbsp;中所有整数 <strong>互不相同</strong>&nbsp;。</p>

<p>所有玩家从编号 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;排成一列。</p>

<p>比赛进行方式如下：</p>

<ul>
	<li>队列中最前面两名玩家进行一场比赛，技能等级 <strong>更高</strong>&nbsp;的玩家胜出。</li>
	<li>比赛后，获胜者保持在队列的开头，而失败者排到队列的末尾。</li>
</ul>

<p>这个比赛的赢家是 <strong>第一位连续</strong>&nbsp;赢下&nbsp;<code>k</code>&nbsp;场比赛的玩家。</p>

<p>请你返回这个比赛的赢家编号。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>skills = [4,2,6,3,9], k = 2</span></p>

<p><b>输出：</b>2</p>

<p><strong>解释：</strong></p>

<p>一开始，队列里的玩家为&nbsp;<code>[0,1,2,3,4]</code>&nbsp;。比赛过程如下：</p>

<ul>
	<li>玩家 0 和 1 进行一场比赛，玩家 0 的技能等级高于玩家 1 ，玩家 0 胜出，队列变为&nbsp;<code>[0,2,3,4,1]</code>&nbsp;。</li>
	<li>玩家 0 和 2 进行一场比赛，玩家 2 的技能等级高于玩家 0 ，玩家 2 胜出，队列变为&nbsp;<code>[2,3,4,1,0]</code>&nbsp;。</li>
	<li>玩家 2 和 3 进行一场比赛，玩家 2 的技能等级高于玩家 3 ，玩家 2 胜出，队列变为&nbsp;<code>[2,4,1,0,3]</code>&nbsp;。</li>
</ul>

<p>玩家 2 连续赢了&nbsp;<code>k = 2</code>&nbsp;场比赛，所以赢家是玩家 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>skills = [2,5,4], k = 3</span></p>

<p><b>输出：</b>1</p>

<p><strong>解释：</strong></p>

<p>一开始，队列里的玩家为&nbsp;<code>[0,1,2]</code>&nbsp;。比赛过程如下：</p>

<ul>
	<li>玩家 0 和 1 进行一场比赛，玩家 1 的技能等级高于玩家 0 ，玩家 1 胜出，队列变为&nbsp;<code>[1,2,0]</code>&nbsp;。</li>
	<li>玩家 1&nbsp;和 2&nbsp;进行一场比赛，玩家 1 的技能等级高于玩家 2&nbsp;，玩家 1 胜出，队列变为&nbsp;<code>[1,0,2]</code>&nbsp;。</li>
	<li>玩家 1&nbsp;和 0&nbsp;进行一场比赛，玩家 1 的技能等级高于玩家 0&nbsp;，玩家 1 胜出，队列变为&nbsp;<code>[1,2,0]</code>&nbsp;。</li>
</ul>

<p>玩家 1 连续赢了&nbsp;<code>k = 3</code>&nbsp;场比赛，所以赢家是玩家 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == skills.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= skills[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>skills</code>&nbsp;中的整数互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到，每次会比较数组的前两个元素，不管结果怎么样，下一次的比较，一定是轮到了数组中的下一个元素和当前的胜者进行比较。因此，如果循环了 $n-1$ 次，那么最后的胜者一定是数组中的最大元素。否则，如果某个元素连续胜出了 $k$ 次，那么这个元素就是最后的胜者。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

相似题目：

-   [1535. 找到数组中的赢家](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1535.Find%20the%20Winner%20of%20an%20Array%20Game/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        n = len(skills)
        k = min(k, n - 1)
        i = cnt = 0
        for j in range(1, n):
            if skills[i] < skills[j]:
                i = j
                cnt = 1
            else:
                cnt += 1
            if cnt == k:
                break
        return i
```

#### Java

```java
class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        int n = skills.length;
        k = Math.min(k, n - 1);
        int i = 0, cnt = 0;
        for (int j = 1; j < n; ++j) {
            if (skills[i] < skills[j]) {
                i = j;
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        k = min(k, n - 1);
        int i = 0, cnt = 0;
        for (int j = 1; j < n; ++j) {
            if (skills[i] < skills[j]) {
                i = j;
                cnt = 1;
            } else {
                ++cnt;
            }
            if (cnt == k) {
                break;
            }
        }
        return i;
    }
};
```

#### Go

```go
func findWinningPlayer(skills []int, k int) int {
	n := len(skills)
	k = min(k, n-1)
	i, cnt := 0, 0
	for j := 1; j < n; j++ {
		if skills[i] < skills[j] {
			i = j
			cnt = 1
		} else {
			cnt++
		}
		if cnt == k {
			break
		}
	}
	return i
}
```

#### TypeScript

```ts
function findWinningPlayer(skills: number[], k: number): number {
    const n = skills.length;
    k = Math.min(k, n - 1);
    let [i, cnt] = [0, 0];
    for (let j = 1; j < n; ++j) {
        if (skills[i] < skills[j]) {
            i = j;
            cnt = 1;
        } else {
            ++cnt;
        }
        if (cnt === k) {
            break;
        }
    }
    return i;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3176. 求出最长好子序列 I](https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i){#3176}

{{< tabs "3176" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n)]
        mp = [defaultdict(int) for _ in range(k + 1)]
        g = [[0] * 3 for _ in range(k + 1)]
        ans = 0
        for i, x in enumerate(nums):
            for h in range(k + 1):
                f[i][h] = mp[h][x]
                if h:
                    if g[h - 1][0] != nums[i]:
                        f[i][h] = max(f[i][h], g[h - 1][1])
                    else:
                        f[i][h] = max(f[i][h], g[h - 1][2])
                f[i][h] += 1
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h])
                if g[h][0] != x:
                    if f[i][h] >= g[h][1]:
                        g[h][2] = g[h][1]
                        g[h][1] = f[i][h]
                        g[h][0] = x
                    else:
                        g[h][2] = max(g[h][2], f[i][h])
                else:
                    g[h][1] = max(g[h][1], f[i][h])
                ans = max(ans, f[i][h])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] f = new int[n][k + 1];
        Map<Integer, Integer>[] mp = new HashMap[k + 1];
        Arrays.setAll(mp, i -> new HashMap<>());
        int[][] g = new int[k + 1][3];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h].getOrDefault(nums[i], 0);
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h].merge(nums[i], f[i][h], Integer::max);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = Math.max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = Math.max(g[h][1], f[i][h]);
                }
                ans = Math.max(ans, f[i][h]);
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
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(k + 1));
        vector<unordered_map<int, int>> mp(k + 1);
        vector<vector<int>> g(k + 1, vector<int>(3));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h][nums[i]];
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h]);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = max(g[h][1], f[i][h]);
                }
                ans = max(ans, f[i][h]);
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(nums []int, k int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	mp := make([]map[int]int, k+1)
	for i := range mp {
		mp[i] = make(map[int]int)
	}
	g := make([][3]int, k+1)
	ans := 0

	for i := 0; i < n; i++ {
		for h := 0; h <= k; h++ {
			f[i][h] = mp[h][nums[i]]
			if h > 0 {
				if g[h-1][0] != nums[i] {
					if g[h-1][1] > f[i][h] {
						f[i][h] = g[h-1][1]
					}
				} else {
					if g[h-1][2] > f[i][h] {
						f[i][h] = g[h-1][2]
					}
				}
			}
			f[i][h]++
			if f[i][h] > mp[h][nums[i]] {
				mp[h][nums[i]] = f[i][h]
			}
			if g[h][0] != nums[i] {
				if f[i][h] >= g[h][1] {
					g[h][2] = g[h][1]
					g[h][1] = f[i][h]
					g[h][0] = nums[i]
				} else if f[i][h] > g[h][2] {
					g[h][2] = f[i][h]
				}
			} else {
				if f[i][h] > g[h][1] {
					g[h][1] = f[i][h]
				}
			}
			if f[i][h] > ans {
				ans = f[i][h]
			}
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    const mp: Map<number, number>[] = Array.from({ length: k + 1 }, () => new Map());
    const g: number[][] = Array.from({ length: k + 1 }, () => Array(3).fill(0));
    let ans = 0;

    for (let i = 0; i < n; i++) {
        for (let h = 0; h <= k; h++) {
            f[i][h] = mp[h].get(nums[i]) || 0;
            if (h > 0) {
                if (g[h - 1][0] !== nums[i]) {
                    f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                } else {
                    f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                }
            }
            f[i][h]++;
            mp[h].set(nums[i], Math.max(mp[h].get(nums[i]) || 0, f[i][h]));
            if (g[h][0] !== nums[i]) {
                if (f[i][h] >= g[h][1]) {
                    g[h][2] = g[h][1];
                    g[h][1] = f[i][h];
                    g[h][0] = nums[i];
                } else {
                    g[h][2] = Math.max(g[h][2], f[i][h]);
                }
            } else {
                g[h][1] = Math.max(g[h][1], f[i][h]);
            }
            ans = Math.max(ans, f[i][h]);
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>非负</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。如果一个整数序列&nbsp;<code>seq</code>&nbsp;满足在下标范围&nbsp;<code>[0, seq.length - 2]</code>&nbsp;中&nbsp;<strong>最多只有</strong>&nbsp;<code>k</code>&nbsp;个下标 <code>i</code>&nbsp;满足&nbsp;<code>seq[i] != seq[i + 1]</code>&nbsp;，那么我们称这个整数序列为&nbsp;<strong>好</strong>&nbsp;序列。</p>

<p>请你返回 <code>nums</code>&nbsp;中&nbsp;<strong>好</strong> <span data-keyword="subsequence-array">子序列</span>&nbsp;的最长长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,1,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<u>1</u>,<u>2</u>,<u>1</u>,<u>1</u>,3]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5,1], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<u>1</u>,2,3,4,5,<u>1</u>]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= min(nums.length, 25)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][h]$ 表示以 $nums[i]$ 结尾，且有不超过 $h$ 个下标满足条件的最长好子序列的长度。初始时 $f[i][h] = 1$。答案为 $\max(f[i][k])$，其中 $0 \le i < n$。

我们考虑如何计算 $f[i][h]$。我们可以枚举 $0 \le j < i$，如果 $nums[i] = nums[j]$，那么 $f[i][h] = \max(f[i][h], f[j][h] + 1)$；否则如果 $h > 0$，那么 $f[i][h] = \max(f[i][h], f[j][h - 1] + 1)$。即：

$$
f[i][h]=
\begin{cases}
\max(f[i][h], f[j][h] + 1), & \textit{if } nums[i] = nums[j], \\
\max(f[i][h], f[j][h - 1] + 1), & \textit{if } h > 0.
\end{cases}
$$

最终答案为 $\max(f[i][k])$，其中 $0 \le i < n$。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[1] * (k + 1) for _ in range(n)]
        ans = 0
        for i, x in enumerate(nums):
            for h in range(k + 1):
                for j, y in enumerate(nums[:i]):
                    if x == y:
                        f[i][h] = max(f[i][h], f[j][h] + 1)
                    elif h:
                        f[i][h] = max(f[i][h], f[j][h - 1] + 1)
            ans = max(ans, f[i][k])
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] f = new int[n][k + 1];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] == nums[j]) {
                        f[i][h] = Math.max(f[i][h], f[j][h]);
                    } else if (h > 0) {
                        f[i][h] = Math.max(f[i][h], f[j][h - 1]);
                    }
                }
                ++f[i][h];
            }
            ans = Math.max(ans, f[i][k]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n][k + 1];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] == nums[j]) {
                        f[i][h] = max(f[i][h], f[j][h]);
                    } else if (h) {
                        f[i][h] = max(f[i][h], f[j][h - 1]);
                    }
                }
                ++f[i][h];
            }
            ans = max(ans, f[i][k]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int, k int) (ans int) {
	f := make([][]int, len(nums))
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i, x := range nums {
		for h := 0; h <= k; h++ {
			for j, y := range nums[:i] {
				if x == y {
					f[i][h] = max(f[i][h], f[j][h])
				} else if h > 0 {
					f[i][h] = max(f[i][h], f[j][h-1])
				}
			}
			f[i][h]++
		}
		ans = max(ans, f[i][k])
	}
	return
}
```

#### TypeScript

```ts
function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let h = 0; h <= k; ++h) {
            for (let j = 0; j < i; ++j) {
                if (nums[i] === nums[j]) {
                    f[i][h] = Math.max(f[i][h], f[j][h]);
                } else if (h) {
                    f[i][h] = Math.max(f[i][h], f[j][h - 1]);
                }
            }
            ++f[i][h];
        }
        ans = Math.max(ans, f[i][k]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划优化

根据方法一的状态转移方程，如果 $nums[i] = nums[j]$，那么我们只需要获取 $f[j][h]$ 的最大值，我们可以用一个长度为 $k + 1$ 的数组 $mp$ 来维护。如果 $nums[i] \neq nums[j]$，我们需要记录 $f[j][h - 1]$ 的最大值对应的 $nums[j]$，最大值和次大值，我们可以用一个长度为 $k + 1$ 的数组 $g$ 来维护。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n)]
        mp = [defaultdict(int) for _ in range(k + 1)]
        g = [[0] * 3 for _ in range(k + 1)]
        ans = 0
        for i, x in enumerate(nums):
            for h in range(k + 1):
                f[i][h] = mp[h][x]
                if h:
                    if g[h - 1][0] != nums[i]:
                        f[i][h] = max(f[i][h], g[h - 1][1])
                    else:
                        f[i][h] = max(f[i][h], g[h - 1][2])
                f[i][h] += 1
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h])
                if g[h][0] != x:
                    if f[i][h] >= g[h][1]:
                        g[h][2] = g[h][1]
                        g[h][1] = f[i][h]
                        g[h][0] = x
                    else:
                        g[h][2] = max(g[h][2], f[i][h])
                else:
                    g[h][1] = max(g[h][1], f[i][h])
                ans = max(ans, f[i][h])
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] f = new int[n][k + 1];
        Map<Integer, Integer>[] mp = new HashMap[k + 1];
        Arrays.setAll(mp, i -> new HashMap<>());
        int[][] g = new int[k + 1][3];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h].getOrDefault(nums[i], 0);
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h].merge(nums[i], f[i][h], Integer::max);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = Math.max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = Math.max(g[h][1], f[i][h]);
                }
                ans = Math.max(ans, f[i][h]);
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
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(k + 1));
        vector<unordered_map<int, int>> mp(k + 1);
        vector<vector<int>> g(k + 1, vector<int>(3));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h][nums[i]];
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h]);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = max(g[h][1], f[i][h]);
                }
                ans = max(ans, f[i][h]);
            }
        }

        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int, k int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	mp := make([]map[int]int, k+1)
	for i := range mp {
		mp[i] = make(map[int]int)
	}
	g := make([][3]int, k+1)
	ans := 0

	for i := 0; i < n; i++ {
		for h := 0; h <= k; h++ {
			f[i][h] = mp[h][nums[i]]
			if h > 0 {
				if g[h-1][0] != nums[i] {
					if g[h-1][1] > f[i][h] {
						f[i][h] = g[h-1][1]
					}
				} else {
					if g[h-1][2] > f[i][h] {
						f[i][h] = g[h-1][2]
					}
				}
			}
			f[i][h]++
			if f[i][h] > mp[h][nums[i]] {
				mp[h][nums[i]] = f[i][h]
			}
			if g[h][0] != nums[i] {
				if f[i][h] >= g[h][1] {
					g[h][2] = g[h][1]
					g[h][1] = f[i][h]
					g[h][0] = nums[i]
				} else if f[i][h] > g[h][2] {
					g[h][2] = f[i][h]
				}
			} else {
				if f[i][h] > g[h][1] {
					g[h][1] = f[i][h]
				}
			}
			if f[i][h] > ans {
				ans = f[i][h]
			}
		}
	}

	return ans
}
```

#### TypeScript

```ts
function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    const mp: Map<number, number>[] = Array.from({ length: k + 1 }, () => new Map());
    const g: number[][] = Array.from({ length: k + 1 }, () => Array(3).fill(0));
    let ans = 0;

    for (let i = 0; i < n; i++) {
        for (let h = 0; h <= k; h++) {
            f[i][h] = mp[h].get(nums[i]) || 0;
            if (h > 0) {
                if (g[h - 1][0] !== nums[i]) {
                    f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                } else {
                    f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                }
            }
            f[i][h]++;
            mp[h].set(nums[i], Math.max(mp[h].get(nums[i]) || 0, f[i][h]));
            if (g[h][0] !== nums[i]) {
                if (f[i][h] >= g[h][1]) {
                    g[h][2] = g[h][1];
                    g[h][1] = f[i][h];
                    g[h][0] = nums[i];
                } else {
                    g[h][2] = Math.max(g[h][2], f[i][h]);
                }
            } else {
                g[h][1] = Math.max(g[h][1], f[i][h]);
            }
            ans = Math.max(ans, f[i][h]);
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

# [3177. 求出最长好子序列 II](https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii){#3177}

{{< tabs "3177" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n)]
        mp = [defaultdict(int) for _ in range(k + 1)]
        g = [[0] * 3 for _ in range(k + 1)]
        ans = 0
        for i, x in enumerate(nums):
            for h in range(k + 1):
                f[i][h] = mp[h][x]
                if h:
                    if g[h - 1][0] != nums[i]:
                        f[i][h] = max(f[i][h], g[h - 1][1])
                    else:
                        f[i][h] = max(f[i][h], g[h - 1][2])
                f[i][h] += 1
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h])
                if g[h][0] != x:
                    if f[i][h] >= g[h][1]:
                        g[h][2] = g[h][1]
                        g[h][1] = f[i][h]
                        g[h][0] = x
                    else:
                        g[h][2] = max(g[h][2], f[i][h])
                else:
                    g[h][1] = max(g[h][1], f[i][h])
                ans = max(ans, f[i][h])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] f = new int[n][k + 1];
        Map<Integer, Integer>[] mp = new HashMap[k + 1];
        Arrays.setAll(mp, i -> new HashMap<>());
        int[][] g = new int[k + 1][3];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h].getOrDefault(nums[i], 0);
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h].merge(nums[i], f[i][h], Integer::max);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = Math.max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = Math.max(g[h][1], f[i][h]);
                }
                ans = Math.max(ans, f[i][h]);
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
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(k + 1));
        vector<unordered_map<int, int>> mp(k + 1);
        vector<vector<int>> g(k + 1, vector<int>(3));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h][nums[i]];
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h]);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = max(g[h][1], f[i][h]);
                }
                ans = max(ans, f[i][h]);
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(nums []int, k int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	mp := make([]map[int]int, k+1)
	for i := range mp {
		mp[i] = make(map[int]int)
	}
	g := make([][3]int, k+1)
	ans := 0

	for i := 0; i < n; i++ {
		for h := 0; h <= k; h++ {
			f[i][h] = mp[h][nums[i]]
			if h > 0 {
				if g[h-1][0] != nums[i] {
					if g[h-1][1] > f[i][h] {
						f[i][h] = g[h-1][1]
					}
				} else {
					if g[h-1][2] > f[i][h] {
						f[i][h] = g[h-1][2]
					}
				}
			}
			f[i][h]++
			if f[i][h] > mp[h][nums[i]] {
				mp[h][nums[i]] = f[i][h]
			}
			if g[h][0] != nums[i] {
				if f[i][h] >= g[h][1] {
					g[h][2] = g[h][1]
					g[h][1] = f[i][h]
					g[h][0] = nums[i]
				} else if f[i][h] > g[h][2] {
					g[h][2] = f[i][h]
				}
			} else {
				if f[i][h] > g[h][1] {
					g[h][1] = f[i][h]
				}
			}
			if f[i][h] > ans {
				ans = f[i][h]
			}
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    const mp: Map<number, number>[] = Array.from({ length: k + 1 }, () => new Map());
    const g: number[][] = Array.from({ length: k + 1 }, () => Array(3).fill(0));
    let ans = 0;

    for (let i = 0; i < n; i++) {
        for (let h = 0; h <= k; h++) {
            f[i][h] = mp[h].get(nums[i]) || 0;
            if (h > 0) {
                if (g[h - 1][0] !== nums[i]) {
                    f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                } else {
                    f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                }
            }
            f[i][h]++;
            mp[h].set(nums[i], Math.max(mp[h].get(nums[i]) || 0, f[i][h]));
            if (g[h][0] !== nums[i]) {
                if (f[i][h] >= g[h][1]) {
                    g[h][2] = g[h][1];
                    g[h][1] = f[i][h];
                    g[h][0] = nums[i];
                } else {
                    g[h][2] = Math.max(g[h][2], f[i][h]);
                }
            } else {
                g[h][1] = Math.max(g[h][1], f[i][h]);
            }
            ans = Math.max(ans, f[i][h]);
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>非负</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。如果一个整数序列&nbsp;<code>seq</code>&nbsp;满足在范围下标范围&nbsp;<code>[0, seq.length - 2]</code>&nbsp;中存在 <strong>不超过</strong>&nbsp;<code>k</code>&nbsp;个下标 <code>i</code>&nbsp;满足&nbsp;<code>seq[i] != seq[i + 1]</code>&nbsp;，那么我们称这个整数序列为&nbsp;<strong>好</strong>&nbsp;序列。</p>

<p>请你返回 <code>nums</code>&nbsp;中&nbsp;<strong>好</strong> <span data-keyword="subsequence-array">子序列</span>&nbsp;的最长长度</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,1,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<em><strong>1</strong></em>,<em><strong>2</strong></em>,<strong><em>1</em></strong>,<em><strong>1</strong></em>,3]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5,1], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>最长好子序列为&nbsp;<code>[<strong><em>1</em></strong>,2,3,4,5,<strong><em>1</em></strong>]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= min(50, nums.length)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][h]$ 表示以 $nums[i]$ 结尾，且有不超过 $h$ 个下标满足条件的最长好子序列的长度。初始时 $f[i][h] = 1$。答案为 $\max(f[i][k])$，其中 $0 \le i < n$。

我们考虑如何计算 $f[i][h]$。我们可以枚举 $0 \le j < i$，如果 $nums[i] = nums[j]$，那么 $f[i][h] = \max(f[i][h], f[j][h] + 1)$；否则如果 $h > 0$，那么 $f[i][h] = \max(f[i][h], f[j][h - 1] + 1)$。即：

$$
f[i][h]=
\begin{cases}
\max(f[i][h], f[j][h] + 1), & \textit{if } nums[i] = nums[j], \\
\max(f[i][h], f[j][h - 1] + 1), & \textit{if } h > 0.
\end{cases}
$$

最终答案为 $\max(f[i][k])$，其中 $0 \le i < n$。

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 是数组 `nums` 的长度。

由于本题数据范围较大，上述解法会超时，需要进行优化。

根据状态转移方程，如果 $nums[i] = nums[j]$，那么我们只需要获取 $f[j][h]$ 的最大值，我们可以用一个长度为 $k + 1$ 的数组 $mp$ 来维护。如果 $nums[i] \neq nums[j]$，我们需要记录 $f[j][h - 1]$ 的最大值对应的 $nums[j]$，最大值和次大值，我们可以用一个长度为 $k + 1$ 的数组 $g$ 来维护。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n)]
        mp = [defaultdict(int) for _ in range(k + 1)]
        g = [[0] * 3 for _ in range(k + 1)]
        ans = 0
        for i, x in enumerate(nums):
            for h in range(k + 1):
                f[i][h] = mp[h][x]
                if h:
                    if g[h - 1][0] != nums[i]:
                        f[i][h] = max(f[i][h], g[h - 1][1])
                    else:
                        f[i][h] = max(f[i][h], g[h - 1][2])
                f[i][h] += 1
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h])
                if g[h][0] != x:
                    if f[i][h] >= g[h][1]:
                        g[h][2] = g[h][1]
                        g[h][1] = f[i][h]
                        g[h][0] = x
                    else:
                        g[h][2] = max(g[h][2], f[i][h])
                else:
                    g[h][1] = max(g[h][1], f[i][h])
                ans = max(ans, f[i][h])
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] f = new int[n][k + 1];
        Map<Integer, Integer>[] mp = new HashMap[k + 1];
        Arrays.setAll(mp, i -> new HashMap<>());
        int[][] g = new int[k + 1][3];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h].getOrDefault(nums[i], 0);
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h].merge(nums[i], f[i][h], Integer::max);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = Math.max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = Math.max(g[h][1], f[i][h]);
                }
                ans = Math.max(ans, f[i][h]);
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
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(k + 1));
        vector<unordered_map<int, int>> mp(k + 1);
        vector<vector<int>> g(k + 1, vector<int>(3));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 0; h <= k; ++h) {
                f[i][h] = mp[h][nums[i]];
                if (h > 0) {
                    if (g[h - 1][0] != nums[i]) {
                        f[i][h] = max(f[i][h], g[h - 1][1]);
                    } else {
                        f[i][h] = max(f[i][h], g[h - 1][2]);
                    }
                }
                ++f[i][h];
                mp[h][nums[i]] = max(mp[h][nums[i]], f[i][h]);
                if (g[h][0] != nums[i]) {
                    if (f[i][h] >= g[h][1]) {
                        g[h][2] = g[h][1];
                        g[h][1] = f[i][h];
                        g[h][0] = nums[i];
                    } else {
                        g[h][2] = max(g[h][2], f[i][h]);
                    }
                } else {
                    g[h][1] = max(g[h][1], f[i][h]);
                }
                ans = max(ans, f[i][h]);
            }
        }

        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int, k int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	mp := make([]map[int]int, k+1)
	for i := range mp {
		mp[i] = make(map[int]int)
	}
	g := make([][3]int, k+1)
	ans := 0

	for i := 0; i < n; i++ {
		for h := 0; h <= k; h++ {
			f[i][h] = mp[h][nums[i]]
			if h > 0 {
				if g[h-1][0] != nums[i] {
					if g[h-1][1] > f[i][h] {
						f[i][h] = g[h-1][1]
					}
				} else {
					if g[h-1][2] > f[i][h] {
						f[i][h] = g[h-1][2]
					}
				}
			}
			f[i][h]++
			if f[i][h] > mp[h][nums[i]] {
				mp[h][nums[i]] = f[i][h]
			}
			if g[h][0] != nums[i] {
				if f[i][h] >= g[h][1] {
					g[h][2] = g[h][1]
					g[h][1] = f[i][h]
					g[h][0] = nums[i]
				} else if f[i][h] > g[h][2] {
					g[h][2] = f[i][h]
				}
			} else {
				if f[i][h] > g[h][1] {
					g[h][1] = f[i][h]
				}
			}
			if f[i][h] > ans {
				ans = f[i][h]
			}
		}
	}

	return ans
}
```

#### TypeScript

```ts
function maximumLength(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));
    const mp: Map<number, number>[] = Array.from({ length: k + 1 }, () => new Map());
    const g: number[][] = Array.from({ length: k + 1 }, () => Array(3).fill(0));
    let ans = 0;

    for (let i = 0; i < n; i++) {
        for (let h = 0; h <= k; h++) {
            f[i][h] = mp[h].get(nums[i]) || 0;
            if (h > 0) {
                if (g[h - 1][0] !== nums[i]) {
                    f[i][h] = Math.max(f[i][h], g[h - 1][1]);
                } else {
                    f[i][h] = Math.max(f[i][h], g[h - 1][2]);
                }
            }
            f[i][h]++;
            mp[h].set(nums[i], Math.max(mp[h].get(nums[i]) || 0, f[i][h]));
            if (g[h][0] !== nums[i]) {
                if (f[i][h] >= g[h][1]) {
                    g[h][2] = g[h][1];
                    g[h][1] = f[i][h];
                    g[h][0] = nums[i];
                } else {
                    g[h][2] = Math.max(g[h][2], f[i][h]);
                }
            } else {
                g[h][1] = Math.max(g[h][1], f[i][h]);
            }
            ans = Math.max(ans, f[i][h]);
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

# [3178. 找出 K 秒后拿着球的孩子](https://leetcode.cn/problems/find-the-child-who-has-the-ball-after-k-seconds){#3178}

{{< tabs "3178" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        k, mod = divmod(k, n - 1)
        return n - mod - 1 if k & 1 else mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfChild(int n, int k) {
        int mod = k % (n - 1);
        k /= (n - 1);
        return k % 2 == 1 ? n - mod - 1 : mod;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfChild(int n, int k) {
        int mod = k % (n - 1);
        k /= (n - 1);
        return k % 2 == 1 ? n - mod - 1 : mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfChild(n int, k int) int {
	mod := k % (n - 1)
	k /= (n - 1)
	if k%2 == 1 {
		return n - mod - 1
	}
	return mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfChild(n: number, k: number): number {
    const mod = k % (n - 1);
    k = (k / (n - 1)) | 0;
    return k % 2 ? n - mod - 1 : mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>正整数 </strong><code>n</code> 和 <code>k</code>。有 <code>n</code> 个编号从 <code>0</code> 到 <code>n - 1</code> 的孩子按顺序从左到右站成一队。</p>

<p>最初，编号为 0 的孩子拿着一个球，并且向右传球。每过一秒，拿着球的孩子就会将球传给他旁边的孩子。一旦球到达队列的 <strong>任一端 </strong>，即编号为 0 的孩子或编号为 <code>n - 1</code> 的孩子处，传球方向就会<strong> 反转 </strong>。</p>

<p>返回 <code>k</code> 秒后接到球的孩子的编号。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 3, k = 5</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>经过的时间</th>
			<th>孩子队列</th>
		</tr>
		<tr>
			<td><code>0</code></td>
			<td><code>[<u>0</u>, 1, 2]</code></td>
		</tr>
		<tr>
			<td><code>1</code></td>
			<td><code>[0, <u>1</u>, 2]</code></td>
		</tr>
		<tr>
			<td><code>2</code></td>
			<td><code>[0, 1, <u>2</u>]</code></td>
		</tr>
		<tr>
			<td><code>3</code></td>
			<td><code>[0, <u>1</u>, 2]</code></td>
		</tr>
		<tr>
			<td><code>4</code></td>
			<td><code>[<u>0</u>, 1, 2]</code></td>
		</tr>
		<tr>
			<td><code>5</code></td>
			<td><code>[0, <u>1</u>, 2]</code></td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 5, k = 6</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>经过的时间</th>
			<th>孩子队列</th>
		</tr>
		<tr>
			<td><code>0</code></td>
			<td><code>[<u>0</u>, 1, 2, 3, 4]</code></td>
		</tr>
		<tr>
			<td><code>1</code></td>
			<td><code>[0, <u>1</u>, 2, 3, 4]</code></td>
		</tr>
		<tr>
			<td><code>2</code></td>
			<td><code>[0, 1, <u>2</u>, 3, 4]</code></td>
		</tr>
		<tr>
			<td><code>3</code></td>
			<td><code>[0, 1, 2, <u>3</u>, 4]</code></td>
		</tr>
		<tr>
			<td><code>4</code></td>
			<td><code>[0, 1, 2, 3, <u>4</u>]</code></td>
		</tr>
		<tr>
			<td><code>5</code></td>
			<td><code>[0, 1, 2, <u>3</u>, 4]</code></td>
		</tr>
		<tr>
			<td><code>6</code></td>
			<td><code>[0, 1, <u>2</u>, 3, 4]</code></td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 4, k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>经过的时间</th>
			<th>孩子队列</th>
		</tr>
		<tr>
			<td><code>0</code></td>
			<td><code>[<u>0</u>, 1, 2, 3]</code></td>
		</tr>
		<tr>
			<td><code>1</code></td>
			<td><code>[0, <u>1</u>, 2, 3]</code></td>
		</tr>
		<tr>
			<td><code>2</code></td>
			<td><code>[0, 1, <u>2</u>, 3]</code></td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>此问题与 <a href="https://leetcode.cn/problems/pass-the-pillow/">2582. 递枕头</a>&nbsp;一致。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们注意到，每一轮有 $n - 1$ 次传递，因此我们可以将 $k$ 对 $n - 1$ 取模，得到 $k$ 在当前轮的传递次数 $mod$，然后我们将 $k$ 除以 $n - 1$，得到当前的轮数 $k$。

接下来我们判断当前的轮数 $k$：

-   如果 $k$ 为奇数，那么当前的传递方向是从队尾到队首，因此会传递到编号为 $n - mod - 1$ 的人手中；
-   如果 $k$ 为偶数，那么当前的传递方向是从队首到队尾，因此会传递到编号为 $mod$ 的人手中。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        k, mod = divmod(k, n - 1)
        return n - mod - 1 if k & 1 else mod
```

#### Java

```java
class Solution {
    public int numberOfChild(int n, int k) {
        int mod = k % (n - 1);
        k /= (n - 1);
        return k % 2 == 1 ? n - mod - 1 : mod;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfChild(int n, int k) {
        int mod = k % (n - 1);
        k /= (n - 1);
        return k % 2 == 1 ? n - mod - 1 : mod;
    }
};
```

#### Go

```go
func numberOfChild(n int, k int) int {
	mod := k % (n - 1)
	k /= (n - 1)
	if k%2 == 1 {
		return n - mod - 1
	}
	return mod
}
```

#### TypeScript

```ts
function numberOfChild(n: number, k: number): number {
    const mod = k % (n - 1);
    k = (k / (n - 1)) | 0;
    return k % 2 ? n - mod - 1 : mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3179. K 秒后第 N 个元素的值](https://leetcode.cn/problems/find-the-n-th-value-after-k-seconds){#3179}

{{< tabs "3179" >}}

{{% tab "python" %}}
```python
class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        a = [1] * n
        mod = 10**9 + 7
        for _ in range(k):
            for i in range(1, n):
                a[i] = (a[i] + a[i - 1]) % mod
        return a[n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int valueAfterKSeconds(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] a = new int[n];
        Arrays.fill(a, 1);
        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                a[i] = (a[i] + a[i - 1]) % mod;
            }
        }
        return a[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod = 1e9 + 7;
        vector<int> a(n, 1);
        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                a[i] = (a[i] + a[i - 1]) % mod;
            }
        }
        return a[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func valueAfterKSeconds(n int, k int) int {
	const mod int = 1e9 + 7
	a := make([]int, n)
	for i := range a {
		a[i] = 1
	}
	for ; k > 0; k-- {
		for i := 1; i < n; i++ {
			a[i] = (a[i] + a[i-1]) % mod
		}
	}
	return a[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function valueAfterKSeconds(n: number, k: number): number {
    const a: number[] = Array(n).fill(1);
    const mod: number = 10 ** 9 + 7;
    while (k--) {
        for (let i = 1; i < n; ++i) {
            a[i] = (a[i] + a[i - 1]) % mod;
        }
    }
    return a[n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>n</code> 和 <code>k</code>。</p>

<p>最初，你有一个长度为 <code>n</code> 的整数数组 <code>a</code>，对所有 <code>0 &lt;= i &lt;= n - 1</code>，都有 <code>a[i] = 1</code> 。每过一秒，你会同时更新每个元素为其前面所有元素的和加上该元素本身。例如，一秒后，<code>a[0]</code> 保持不变，<code>a[1]</code> 变为 <code>a[0] + a[1]</code>，<code>a[2]</code> 变为 <code>a[0] + a[1] + a[2]</code>，以此类推。</p>

<p>返回 <code>k</code> 秒后 <code>a[n - 1]</code> 的<strong>值</strong>。</p>

<p>由于答案可能非常大，返回其对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后的结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 4, k = 5</span></p>

<p><strong>输出：</strong><span class="example-io">56</span></p>

<p><strong>解释：</strong></p>

<table border="1">
	<tbody>
		<tr>
			<th>时间（秒）</th>
			<th>数组状态</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,1,1,1]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[1,2,3,4]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[1,3,6,10]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[1,4,10,20]</td>
		</tr>
		<tr>
			<td>4</td>
			<td>[1,5,15,35]</td>
		</tr>
		<tr>
			<td>5</td>
			<td>[1,6,21,56]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 5, k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">35</span></p>

<p><strong>解释：</strong></p>

<table border="1">
	<tbody>
		<tr>
			<th>时间（秒）</th>
			<th>数组状态</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,1,1,1,1]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[1,2,3,4,5]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[1,3,6,10,15]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[1,4,10,20,35]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们注意到，整数 $n$ 的范围是 $1 \leq n \leq 1000$，因此我们可以直接模拟这个过程。

我们定义一个长度为 $n$ 的数组 $a$，并初始化所有元素为 $1$。然后我们模拟 $k$ 秒的过程，每一秒我们都更新数组 $a$ 的元素，直到 $k$ 秒结束。

最后，我们返回 $a[n - 1]$ 即可。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $a$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        a = [1] * n
        mod = 10**9 + 7
        for _ in range(k):
            for i in range(1, n):
                a[i] = (a[i] + a[i - 1]) % mod
        return a[n - 1]
```

#### Java

```java
class Solution {
    public int valueAfterKSeconds(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] a = new int[n];
        Arrays.fill(a, 1);
        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                a[i] = (a[i] + a[i - 1]) % mod;
            }
        }
        return a[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod = 1e9 + 7;
        vector<int> a(n, 1);
        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                a[i] = (a[i] + a[i - 1]) % mod;
            }
        }
        return a[n - 1];
    }
};
```

#### Go

```go
func valueAfterKSeconds(n int, k int) int {
	const mod int = 1e9 + 7
	a := make([]int, n)
	for i := range a {
		a[i] = 1
	}
	for ; k > 0; k-- {
		for i := 1; i < n; i++ {
			a[i] = (a[i] + a[i-1]) % mod
		}
	}
	return a[n-1]
}
```

#### TypeScript

```ts
function valueAfterKSeconds(n: number, k: number): number {
    const a: number[] = Array(n).fill(1);
    const mod: number = 10 ** 9 + 7;
    while (k--) {
        for (let i = 1; i < n; ++i) {
            a[i] = (a[i] + a[i - 1]) % mod;
        }
    }
    return a[n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
