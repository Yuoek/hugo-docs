---
title: "2380_二进制字符串重新安排顺序需要的时间"
date: 2025-10-08T18:39:12+08:00
weight: 9
tags: [二分查找, 二叉树, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数据库, 数组, 有序集合, 树, 模拟, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2380_二进制字符串重新安排顺序需要的时间](#2380)
#### [字符串](#2380)
#### [动态规划](#2380)
#### [模拟](#2380)
### [2381_字母移位 II](#2381)
#### [数组](#2381)
#### [字符串](#2381)
#### [前缀和](#2381)
### [2382_删除操作后的最大子段和](#2382)
#### [并查集](#2382)
#### [数组](#2382)
#### [有序集合](#2382)
#### [前缀和](#2382)
### [2383_赢得比赛需要的最少训练时长](#2383)
#### [贪心](#2383)
#### [数组](#2383)
### [2384_最大回文数字](#2384)
#### [贪心](#2384)
#### [哈希表](#2384)
#### [字符串](#2384)
#### [计数](#2384)
### [2385_感染二叉树需要的总时间](#2385)
#### [树](#2385)
#### [深度优先搜索](#2385)
#### [广度优先搜索](#2385)
#### [哈希表](#2385)
#### [二叉树](#2385)
### [2386_找出数组的第 K 大和](#2386)
#### [数组](#2386)
#### [排序](#2386)
#### [堆（优先队列）](#2386)
### [2387_行排序矩阵的中位数 🔒](#2387)
#### [数组](#2387)
#### [二分查找](#2387)
#### [矩阵](#2387)
### [2388_将表中的空值更改为前一个值 🔒](#2388)
#### [数据库](#2388)
### [2389_和有限的最长子序列](#2389)
#### [贪心](#2389)
#### [数组](#2389)
#### [二分查找](#2389)
#### [前缀和](#2389)
#### [排序](#2389)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2380_二进制字符串重新安排顺序需要的时间
___
#### 字符串
___
#### 动态规划
___
#### 模拟
---
### 2381_字母移位 II
___
#### 数组
___
#### 字符串
___
#### 前缀和
---
### 2382_删除操作后的最大子段和
___
#### 并查集
___
#### 数组
___
#### 有序集合
___
#### 前缀和
---
### 2383_赢得比赛需要的最少训练时长
___
#### 贪心
___
#### 数组
---
### 2384_最大回文数字
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2385_感染二叉树需要的总时间
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 2386_找出数组的第 K 大和
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2387_行排序矩阵的中位数 🔒
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 2388_将表中的空值更改为前一个值 🔒
___
#### 数据库
---
### 2389_和有限的最长子序列
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数据库 | 数组 |
| 有序集合 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 计数 |
| 贪心 |  |  |

# [2380. 二进制字符串重新安排顺序需要的时间](https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string){#2380}

{{< tabs "2380" >}}

{{% tab "python" %}}
```python
class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == '0':
                cnt += 1
            elif cnt:
                ans = max(ans + 1, cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int secondsToRemoveOccurrences(String s) {
        int ans = 0, cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') {
                ++cnt;
            } else if (cnt > 0) {
                ans = Math.max(ans + 1, cnt);
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
    int secondsToRemoveOccurrences(string s) {
        int ans = 0, cnt = 0;
        for (char c : s) {
            if (c == '0') {
                ++cnt;
            } else if (cnt) {
                ans = max(ans + 1, cnt);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func secondsToRemoveOccurrences(s string) int {
	ans, cnt := 0, 0
	for _, c := range s {
		if c == '0' {
			cnt++
		} else if cnt > 0 {
			ans = max(ans+1, cnt)
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

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;。在一秒之中，<strong>所有</strong>&nbsp;子字符串&nbsp;<code>"01"</code> <strong>同时</strong>&nbsp;被替换成&nbsp;<code>"10"</code>&nbsp;。这个过程持续进行到没有&nbsp;<code>"01"</code>&nbsp;存在。</p>

<p>请你返回完成这个过程所需要的秒数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "0110101"
<b>输出：</b>4
<b>解释：</b>
一秒后，s 变成 "1011010" 。
再过 1 秒后，s 变成 "1101100" 。
第三秒过后，s 变成 "1110100" 。
第四秒后，s 变成 "1111000" 。
此时没有 "01" 存在，整个过程花费 4 秒。
所以我们返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "11100"
<b>输出：</b>0
<strong>解释：</strong>
s 中没有 "01" 存在，整个过程花费 0 秒。
所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你能以 O(n) 的时间复杂度解决这个问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力模拟

由于本题数据范围不大，所以可以暴力模拟，每一轮将字符串中所有 “01” 替换为 “10”，统计轮次作为答案。

时间复杂度 $O(n^2)$。每一轮时间复杂度 $O(n)$，最多进行 $n$ 轮操作。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        ans = 0
        while s.count('01'):
            s = s.replace('01', '10')
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int secondsToRemoveOccurrences(String s) {
        char[] cs = s.toCharArray();
        boolean find = true;
        int ans = 0;
        while (find) {
            find = false;
            for (int i = 0; i < cs.length - 1; ++i) {
                if (cs[i] == '0' && cs[i + 1] == '1') {
                    char t = cs[i];
                    cs[i] = cs[i + 1];
                    cs[i + 1] = t;
                    ++i;
                    find = true;
                }
            }
            if (find) {
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
    int secondsToRemoveOccurrences(string s) {
        bool find = true;
        int ans = 0;
        while (find) {
            find = false;
            for (int i = 0; i < s.size() - 1; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    ++i;
                    find = true;
                }
            }
            if (find) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func secondsToRemoveOccurrences(s string) int {
	cs := []byte(s)
	ans := 0
	find := true
	for find {
		find = false
		for i := 0; i < len(cs)-1; i++ {
			if cs[i] == '0' && cs[i+1] == '1' {
				cs[i], cs[i+1] = cs[i+1], cs[i]
				i++
				find = true
			}
		}
		if find {
			ans++
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

题目要把所有“01”串替换为“10”，实际上是将所有的“1”往左移动。操作过后，左侧均为“1”，而右侧均为“0”。

假如我们要把“0100010”重排为“1100000”，会出现两种情况：

1. 如果一个“1”左边有 $cnt$ 个“0”，那么将这个“1”移动到最左边的位置需要 $cnt$ 秒；
1. 如果有连续的“1”，则将这两个“1”移动到最左边的位置需要额外的 $1$ 秒。

看下面的示例：

| 时刻（秒） | 示例 1 | 示例 2 |
| ---------- | ------ | ------ |
| 0          | 0001   | 00011  |
| 1          | 0010   | 00101  |
| 2          | 0100   | 01010  |
| 3          | 1000   | 10100  |
| 4          | -      | 11000  |

我们可以看到，如果在 $cnt$ 个“0”之后只有一个“1”，那么只需要 $cnt$ 秒，如果有连续的“1”，则需要额外的 $1$ 秒。

因此，对于字符串中的每一个“1”，我们计算 $ans=max(ans+1, cnt)$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == '0':
                cnt += 1
            elif cnt:
                ans = max(ans + 1, cnt)
        return ans
```

#### Java

```java
class Solution {
    public int secondsToRemoveOccurrences(String s) {
        int ans = 0, cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') {
                ++cnt;
            } else if (cnt > 0) {
                ans = Math.max(ans + 1, cnt);
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
    int secondsToRemoveOccurrences(string s) {
        int ans = 0, cnt = 0;
        for (char c : s) {
            if (c == '0') {
                ++cnt;
            } else if (cnt) {
                ans = max(ans + 1, cnt);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func secondsToRemoveOccurrences(s string) int {
	ans, cnt := 0, 0
	for _, c := range s {
		if c == '0' {
			cnt++
		} else if cnt > 0 {
			ans = max(ans+1, cnt)
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

# [2381. 字母移位 II](https://leetcode.cn/problems/shifting-letters-ii){#2381}

{{< tabs "2381" >}}

{{% tab "python" %}}
```python
class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        d = [0] * (n + 1)
        for i, j, v in shifts:
            if v == 0:
                v = -1
            d[i] += v
            d[j + 1] -= v
        for i in range(1, n + 1):
            d[i] += d[i - 1]
        return ''.join(
            chr(ord('a') + (ord(s[i]) - ord('a') + d[i] + 26) % 26) for i in range(n)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] d = new int[n + 1];
        for (int[] e : shifts) {
            if (e[2] == 0) {
                e[2]--;
            }
            d[e[0]] += e[2];
            d[e[1] + 1] -= e[2];
        }
        for (int i = 1; i <= n; ++i) {
            d[i] += d[i - 1];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            int j = (s.charAt(i) - 'a' + d[i] % 26 + 26) % 26;
            ans.append((char) ('a' + j));
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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> d(n + 1);
        for (auto& e : shifts) {
            if (e[2] == 0) {
                e[2]--;
            }
            d[e[0]] += e[2];
            d[e[1] + 1] -= e[2];
        }
        for (int i = 1; i <= n; ++i) {
            d[i] += d[i - 1];
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            int j = (s[i] - 'a' + d[i] % 26 + 26) % 26;
            ans += ('a' + j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shiftingLetters(s string, shifts [][]int) string {
	n := len(s)
	d := make([]int, n+1)
	for _, e := range shifts {
		if e[2] == 0 {
			e[2]--
		}
		d[e[0]] += e[2]
		d[e[1]+1] -= e[2]
	}
	for i := 1; i <= n; i++ {
		d[i] += d[i-1]
	}
	ans := []byte{}
	for i, c := range s {
		j := (int(c-'a') + d[i]%26 + 26) % 26
		ans = append(ans, byte('a'+j))
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shiftingLetters(s: string, shifts: number[][]): string {
    const n: number = s.length;
    const d: number[] = new Array(n + 1).fill(0);

    for (let [i, j, v] of shifts) {
        if (v === 0) {
            v--;
        }
        d[i] += v;
        d[j + 1] -= v;
    }

    for (let i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
    }

    let ans: string = '';
    for (let i = 0; i < n; ++i) {
        const j = (s.charCodeAt(i) - 'a'.charCodeAt(0) + (d[i] % 26) + 26) % 26;
        ans += String.fromCharCode('a'.charCodeAt(0) + j);
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

<p>给你一个小写英文字母组成的字符串&nbsp;<code>s</code>&nbsp;和一个二维整数数组&nbsp;<code>shifts</code>&nbsp;，其中&nbsp;<code>shifts[i] = [start<sub>i</sub>, end<sub>i</sub>, direction<sub>i</sub>]</code>&nbsp;。对于每个&nbsp;<code>i</code>&nbsp;，将&nbsp;<code>s</code>&nbsp;中从下标&nbsp;<code>start<sub>i</sub></code>&nbsp;到下标&nbsp;<code>end<sub>i</sub></code>&nbsp;（两者都包含）所有字符都进行移位运算，如果&nbsp;<code>direction<sub>i</sub> = 1</code>&nbsp;将字符向后移位，如果&nbsp;<code>direction<sub>i</sub> = 0</code>&nbsp;将字符向前移位。</p>

<p>将一个字符 <strong>向后</strong>&nbsp;移位的意思是将这个字符用字母表中 <strong>下一个</strong>&nbsp;字母替换（字母表视为环绕的，所以&nbsp;<code>'z'</code>&nbsp;变成&nbsp;<code>'a'</code>）。类似的，将一个字符 <strong>向前</strong>&nbsp;移位的意思是将这个字符用字母表中 <strong>前一个</strong>&nbsp;字母替换（字母表是环绕的，所以&nbsp;<code>'a'</code>&nbsp;变成&nbsp;<code>'z'</code>&nbsp;）。</p>

<p>请你返回对 <code>s</code>&nbsp;进行所有移位操作以后得到的最终字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
<b>输出：</b>"ace"
<b>解释：</b>首先，将下标从 0 到 1 的字母向前移位，得到 s = "zac" 。
然后，将下标从 1 到 2 的字母向后移位，得到 s = "zbd" 。
最后，将下标从 0 到 2 的字符向后移位，得到 s = "ace" 。</pre>

<p><strong>示例 2:</strong></p>

<pre><b>输入：</b>s = "dztz", shifts = [[0,0,0],[1,1,1]]
<b>输出：</b>"catz"
<b>解释：</b>首先，将下标从 0 到 0 的字母向前移位，得到 s = "cztz" 。
最后，将下标从 1 到 1 的字符向后移位，得到 s = "catz" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, shifts.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>shifts[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt; s.length</code></li>
	<li><code>0 &lt;= direction<sub>i</sub> &lt;= 1</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

用差分数组 $d$ 记录区间的变化，然后对 $d$ 求前缀和，得到每个下标 $i$ 的变化量 $d[i]$。

然后将原字符串中每个字符加上对应的 $d[i]$，最终得到一个新的字符串。

时间复杂度 $O(n+m)$。其中 $n$ 是原字符串 $s$ 的长度，而 $m$ 是移位操作 $shifts$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        d = [0] * (n + 1)
        for i, j, v in shifts:
            if v == 0:
                v = -1
            d[i] += v
            d[j + 1] -= v
        for i in range(1, n + 1):
            d[i] += d[i - 1]
        return ''.join(
            chr(ord('a') + (ord(s[i]) - ord('a') + d[i] + 26) % 26) for i in range(n)
        )
```

#### Java

```java
class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] d = new int[n + 1];
        for (int[] e : shifts) {
            if (e[2] == 0) {
                e[2]--;
            }
            d[e[0]] += e[2];
            d[e[1] + 1] -= e[2];
        }
        for (int i = 1; i <= n; ++i) {
            d[i] += d[i - 1];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            int j = (s.charAt(i) - 'a' + d[i] % 26 + 26) % 26;
            ans.append((char) ('a' + j));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> d(n + 1);
        for (auto& e : shifts) {
            if (e[2] == 0) {
                e[2]--;
            }
            d[e[0]] += e[2];
            d[e[1] + 1] -= e[2];
        }
        for (int i = 1; i <= n; ++i) {
            d[i] += d[i - 1];
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            int j = (s[i] - 'a' + d[i] % 26 + 26) % 26;
            ans += ('a' + j);
        }
        return ans;
    }
};
```

#### Go

```go
func shiftingLetters(s string, shifts [][]int) string {
	n := len(s)
	d := make([]int, n+1)
	for _, e := range shifts {
		if e[2] == 0 {
			e[2]--
		}
		d[e[0]] += e[2]
		d[e[1]+1] -= e[2]
	}
	for i := 1; i <= n; i++ {
		d[i] += d[i-1]
	}
	ans := []byte{}
	for i, c := range s {
		j := (int(c-'a') + d[i]%26 + 26) % 26
		ans = append(ans, byte('a'+j))
	}
	return string(ans)
}
```

#### TypeScript

```ts
function shiftingLetters(s: string, shifts: number[][]): string {
    const n: number = s.length;
    const d: number[] = new Array(n + 1).fill(0);

    for (let [i, j, v] of shifts) {
        if (v === 0) {
            v--;
        }
        d[i] += v;
        d[j + 1] -= v;
    }

    for (let i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
    }

    let ans: string = '';
    for (let i = 0; i < n; ++i) {
        const j = (s.charCodeAt(i) - 'a'.charCodeAt(0) + (d[i] % 26) + 26) % 26;
        ans += String.fromCharCode('a'.charCodeAt(0) + j);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2382. 删除操作后的最大子段和](https://leetcode.cn/problems/maximum-segment-sum-after-removals){#2382}

{{< tabs "2382" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def merge(a, b):
            pa, pb = find(a), find(b)
            p[pa] = pb
            s[pb] += s[pa]

        n = len(nums)
        p = list(range(n))
        s = [0] * n
        ans = [0] * n
        mx = 0
        for j in range(n - 1, 0, -1):
            i = removeQueries[j]
            s[i] = nums[i]
            if i and s[find(i - 1)]:
                merge(i, i - 1)
            if i < n - 1 and s[find(i + 1)]:
                merge(i, i + 1)
            mx = max(mx, s[find(i)])
            ans[j - 1] = mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;
    private long[] s;

    public long[] maximumSegmentSum(int[] nums, int[] removeQueries) {
        int n = nums.length;
        p = new int[n];
        s = new long[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        long[] ans = new long[n];
        long mx = 0;
        for (int j = n - 1; j > 0; --j) {
            int i = removeQueries[j];
            s[i] = nums[i];
            if (i > 0 && s[find(i - 1)] > 0) {
                merge(i, i - 1);
            }
            if (i < n - 1 && s[find(i + 1)] > 0) {
                merge(i, i + 1);
            }
            mx = Math.max(mx, s[find(i)]);
            ans[j - 1] = mx;
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
        s[pb] += s[pa];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    vector<int> p;
    vector<ll> s;

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        s.assign(n, 0);
        vector<ll> ans(n);
        ll mx = 0;
        for (int j = n - 1; j; --j) {
            int i = removeQueries[j];
            s[i] = nums[i];
            if (i && s[find(i - 1)]) merge(i, i - 1);
            if (i < n - 1 && s[find(i + 1)]) merge(i, i + 1);
            mx = max(mx, s[find(i)]);
            ans[j - 1] = mx;
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
        s[pb] += s[pa];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSegmentSum(nums []int, removeQueries []int) []int64 {
	n := len(nums)
	p := make([]int, n)
	s := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	merge := func(a, b int) {
		pa, pb := find(a), find(b)
		p[pa] = pb
		s[pb] += s[pa]
	}
	mx := 0
	ans := make([]int64, n)
	for j := n - 1; j > 0; j-- {
		i := removeQueries[j]
		s[i] = nums[i]
		if i > 0 && s[find(i-1)] > 0 {
			merge(i, i-1)
		}
		if i < n-1 && s[find(i+1)] > 0 {
			merge(i, i+1)
		}
		mx = max(mx, s[find(i)])
		ans[j-1] = int64(mx)
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

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code> 和&nbsp;<code>removeQueries</code>&nbsp;，两者长度都为&nbsp;<code>n</code>&nbsp;。对于第&nbsp;<code>i</code>&nbsp;个查询，<code>nums</code>&nbsp;中位于下标&nbsp;<code>removeQueries[i]</code>&nbsp;处的元素被删除，将 <code>nums</code>&nbsp;分割成更小的子段。</p>

<p>一个 <strong>子段</strong>&nbsp;是 <code>nums</code>&nbsp;中连续 <strong>正</strong>&nbsp;整数形成的序列。<strong>子段和</strong>&nbsp;是子段中所有元素的和。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;次删除操作以后的&nbsp;<strong>最大</strong>&nbsp;子段和。</p>

<p><strong>注意：</strong>一个下标至多只会被删除一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
<b>输出：</b>[14,7,2,2,0]
<b>解释：</b>用 0 表示被删除的元素，答案如下所示：
查询 1 ：删除第 0 个元素，nums 变成 [0,2,5,6,1] ，最大子段和为子段 [2,5,6,1] 的和 14 。
查询 2 ：删除第 3 个元素，nums 变成 [0,2,5,0,1] ，最大子段和为子段 [2,5] 的和 7 。
查询 3 ：删除第 2 个元素，nums 变成 [0,2,0,0,1] ，最大子段和为子段 [2] 的和 2 。
查询 4 ：删除第 4 个元素，nums 变成 [0,2,0,0,0] ，最大子段和为子段 [2] 的和 2 。
查询 5 ：删除第 1 个元素，nums 变成 [0,0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [14,7,2,2,0] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,2,11,1], removeQueries = [3,2,1,0]
<b>输出：</b>[16,5,3,0]
<b>解释：</b>用 0 表示被删除的元素，答案如下所示：
查询 1 ：删除第 3 个元素，nums 变成 [3,2,11,0] ，最大子段和为子段 [3,2,11] 的和 16 。
查询 2 ：删除第 2 个元素，nums 变成 [3,2,0,0] ，最大子段和为子段 [3,2] 的和 5 。
查询 3 ：删除第 1 个元素，nums 变成 [3,0,0,0] ，最大子段和为子段 [3] 的和 3 。
查询 5 ：删除第 0 个元素，nums 变成 [0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [16,5,3,0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length == removeQueries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= removeQueries[i] &lt; n</code></li>
	<li><code>removeQueries</code>&nbsp;中所有数字 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向思维 + 并查集

考虑**从后往前遍历**数组 $removeQueries$ 中的每个元素 $i$，用并查集来维护以 $nums[i]$ 所在的连续子数组的和。

遍历过程中：

对于 $removeQueries$ 中的每一个 $i$，若下标 $i-1$ 对应的元素遍历过，可以将 $i-1$ 与 $i$ 进行合并，同理，若下标 $i+1$ 对应的元素也遍历过了，将 $i$ 与 $i+1$ 合并。合并过程中更新连通块的元素和。

时间复杂度 $O(nlogn)$。其中 $n$ 是 $nums$ 中的元素个数。

相似题目：

-   [2334. 元素值大于变化阈值的子数组](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2334.Subarray%20With%20Elements%20Greater%20Than%20Varying%20Threshold/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def merge(a, b):
            pa, pb = find(a), find(b)
            p[pa] = pb
            s[pb] += s[pa]

        n = len(nums)
        p = list(range(n))
        s = [0] * n
        ans = [0] * n
        mx = 0
        for j in range(n - 1, 0, -1):
            i = removeQueries[j]
            s[i] = nums[i]
            if i and s[find(i - 1)]:
                merge(i, i - 1)
            if i < n - 1 and s[find(i + 1)]:
                merge(i, i + 1)
            mx = max(mx, s[find(i)])
            ans[j - 1] = mx
        return ans
```

#### Java

```java
class Solution {
    private int[] p;
    private long[] s;

    public long[] maximumSegmentSum(int[] nums, int[] removeQueries) {
        int n = nums.length;
        p = new int[n];
        s = new long[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        long[] ans = new long[n];
        long mx = 0;
        for (int j = n - 1; j > 0; --j) {
            int i = removeQueries[j];
            s[i] = nums[i];
            if (i > 0 && s[find(i - 1)] > 0) {
                merge(i, i - 1);
            }
            if (i < n - 1 && s[find(i + 1)] > 0) {
                merge(i, i + 1);
            }
            mx = Math.max(mx, s[find(i)]);
            ans[j - 1] = mx;
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
        s[pb] += s[pa];
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    vector<int> p;
    vector<ll> s;

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        s.assign(n, 0);
        vector<ll> ans(n);
        ll mx = 0;
        for (int j = n - 1; j; --j) {
            int i = removeQueries[j];
            s[i] = nums[i];
            if (i && s[find(i - 1)]) merge(i, i - 1);
            if (i < n - 1 && s[find(i + 1)]) merge(i, i + 1);
            mx = max(mx, s[find(i)]);
            ans[j - 1] = mx;
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
        s[pb] += s[pa];
    }
};
```

#### Go

```go
func maximumSegmentSum(nums []int, removeQueries []int) []int64 {
	n := len(nums)
	p := make([]int, n)
	s := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	merge := func(a, b int) {
		pa, pb := find(a), find(b)
		p[pa] = pb
		s[pb] += s[pa]
	}
	mx := 0
	ans := make([]int64, n)
	for j := n - 1; j > 0; j-- {
		i := removeQueries[j]
		s[i] = nums[i]
		if i > 0 && s[find(i-1)] > 0 {
			merge(i, i-1)
		}
		if i < n-1 && s[find(i+1)] > 0 {
			merge(i, i+1)
		}
		mx = max(mx, s[find(i)])
		ans[j-1] = int64(mx)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2383. 赢得比赛需要的最少训练时长](https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition){#2383}

{{< tabs "2383" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumberOfHours(
        self, x: int, y: int, energy: List[int], experience: List[int]
    ) -> int:
        ans = 0
        for dx, dy in zip(energy, experience):
            if x <= dx:
                ans += dx + 1 - x
                x = dx + 1
            if y <= dy:
                ans += dy + 1 - y
                y = dy + 1
            x -= dx
            y += dy
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumberOfHours(int x, int y, int[] energy, int[] experience) {
        int ans = 0;
        for (int i = 0; i < energy.length; ++i) {
            int dx = energy[i], dy = experience[i];
            if (x <= dx) {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if (y <= dy) {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
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
    int minNumberOfHours(int x, int y, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < energy.size(); ++i) {
            int dx = energy[i], dy = experience[i];
            if (x <= dx) {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if (y <= dy) {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumberOfHours(x int, y int, energy []int, experience []int) (ans int) {
	for i, dx := range energy {
		dy := experience[i]
		if x <= dx {
			ans += dx + 1 - x
			x = dx + 1
		}
		if y <= dy {
			ans += dy + 1 - y
			y = dy + 1
		}
		x -= dx
		y += dy
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumberOfHours(x: number, y: number, energy: number[], experience: number[]): number {
    let ans = 0;
    for (let i = 0; i < energy.length; ++i) {
        const [dx, dy] = [energy[i], experience[i]];
        if (x <= dx) {
            ans += dx + 1 - x;
            x = dx + 1;
        }
        if (y <= dy) {
            ans += dy + 1 - y;
            y = dy + 1;
        }
        x -= dx;
        y += dy;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_number_of_hours(
        mut x: i32,
        mut y: i32,
        energy: Vec<i32>,
        experience: Vec<i32>,
    ) -> i32 {
        let mut ans = 0;

        for (&dx, &dy) in energy.iter().zip(experience.iter()) {
            if x <= dx {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if y <= dy {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minNumberOfHours(int x, int y, int* energy, int energySize, int* experience, int experienceSize) {
    int ans = 0;
    for (int i = 0; i < energySize; ++i) {
        int dx = energy[i], dy = experience[i];
        if (x <= dx) {
            ans += dx + 1 - x;
            x = dx + 1;
        }
        if (y <= dy) {
            ans += dy + 1 - y;
            y = dy + 1;
        }
        x -= dx;
        y += dy;
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

<p>你正在参加一场比赛，给你两个 <strong>正</strong> 整数 <code>initialEnergy</code> 和 <code>initialExperience</code> 分别表示你的初始精力和初始经验。</p>

<p>另给你两个下标从 <strong>0</strong> 开始的整数数组 <code>energy</code> 和 <code>experience</code>，长度均为 <code>n</code> 。</p>

<p>你将会 <strong>依次</strong> 对上 <code>n</code> 个对手。第 <code>i</code> 个对手的精力和经验分别用 <code>energy[i]</code> 和 <code>experience[i]</code> 表示。当你对上对手时，需要在经验和精力上都 <strong>严格</strong> 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。</p>

<p>击败第 <code>i</code> 个对手会使你的经验 <strong>增加</strong> <code>experience[i]</code>，但会将你的精力 <strong>减少</strong>&nbsp; <code>energy[i]</code> 。</p>

<p>在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 <strong>或者</strong> 将精力增加 1 。</p>

<p>返回击败全部 <code>n</code> 个对手需要训练的 <strong>最少</strong> 小时数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
<strong>输出：</strong>8
<strong>解释：</strong>在 6 小时训练后，你可以将精力提高到 11 ，并且再训练 2 个小时将经验提高到 5 。
按以下顺序与对手比赛：
- 你的精力与经验都超过第 0 个对手，所以获胜。
  精力变为：11 - 1 = 10 ，经验变为：5 + 2 = 7 。
- 你的精力与经验都超过第 1 个对手，所以获胜。
  精力变为：10 - 4 = 6 ，经验变为：7 + 6 = 13 。
- 你的精力与经验都超过第 2 个对手，所以获胜。
  精力变为：6 - 3 = 3 ，经验变为：13 + 3 = 16 。
- 你的精力与经验都超过第 3 个对手，所以获胜。
  精力变为：3 - 2 = 1 ，经验变为：16 + 1 = 17 。
在比赛前进行了 8 小时训练，所以返回 8 。
可以证明不存在更小的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
<strong>输出：</strong>0
<strong>解释：</strong>你不需要额外的精力和经验就可以赢得比赛，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == energy.length == experience.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= initialEnergy, initialExperience, energy[i], experience[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 模拟

我们不妨记当前的精力为 $x$，经验为 $y$。

接下来，我们遍历每个对手，对于第 $i$ 个对手，记其精力为 $dx$，经验为 $dy$。

-   如果 $x \leq dx$，那么我们需要训练 $dx + 1 - x$ 小时，将精力提升到 $dx + 1$；
-   如果 $y \leq dy$，那么我们需要训练 $dy + 1 - y$ 小时，将经验提升到 $dy + 1$；
-   然后我们将精力减去 $dx$，经验加上 $dy$。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为对手的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumberOfHours(
        self, x: int, y: int, energy: List[int], experience: List[int]
    ) -> int:
        ans = 0
        for dx, dy in zip(energy, experience):
            if x <= dx:
                ans += dx + 1 - x
                x = dx + 1
            if y <= dy:
                ans += dy + 1 - y
                y = dy + 1
            x -= dx
            y += dy
        return ans
```

#### Java

```java
class Solution {
    public int minNumberOfHours(int x, int y, int[] energy, int[] experience) {
        int ans = 0;
        for (int i = 0; i < energy.length; ++i) {
            int dx = energy[i], dy = experience[i];
            if (x <= dx) {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if (y <= dy) {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNumberOfHours(int x, int y, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < energy.size(); ++i) {
            int dx = energy[i], dy = experience[i];
            if (x <= dx) {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if (y <= dy) {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
        }
        return ans;
    }
};
```

#### Go

```go
func minNumberOfHours(x int, y int, energy []int, experience []int) (ans int) {
	for i, dx := range energy {
		dy := experience[i]
		if x <= dx {
			ans += dx + 1 - x
			x = dx + 1
		}
		if y <= dy {
			ans += dy + 1 - y
			y = dy + 1
		}
		x -= dx
		y += dy
	}
	return
}
```

#### TypeScript

```ts
function minNumberOfHours(x: number, y: number, energy: number[], experience: number[]): number {
    let ans = 0;
    for (let i = 0; i < energy.length; ++i) {
        const [dx, dy] = [energy[i], experience[i]];
        if (x <= dx) {
            ans += dx + 1 - x;
            x = dx + 1;
        }
        if (y <= dy) {
            ans += dy + 1 - y;
            y = dy + 1;
        }
        x -= dx;
        y += dy;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_number_of_hours(
        mut x: i32,
        mut y: i32,
        energy: Vec<i32>,
        experience: Vec<i32>,
    ) -> i32 {
        let mut ans = 0;

        for (&dx, &dy) in energy.iter().zip(experience.iter()) {
            if x <= dx {
                ans += dx + 1 - x;
                x = dx + 1;
            }
            if y <= dy {
                ans += dy + 1 - y;
                y = dy + 1;
            }
            x -= dx;
            y += dy;
        }

        ans
    }
}
```

#### C

```c
int minNumberOfHours(int x, int y, int* energy, int energySize, int* experience, int experienceSize) {
    int ans = 0;
    for (int i = 0; i < energySize; ++i) {
        int dx = energy[i], dy = experience[i];
        if (x <= dx) {
            ans += dx + 1 - x;
            x = dx + 1;
        }
        if (y <= dy) {
            ans += dy + 1 - y;
            y = dy + 1;
        }
        x -= dx;
        y += dy;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2384. 最大回文数字](https://leetcode.cn/problems/largest-palindromic-number){#2384}

{{< tabs "2384" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestPalindromic(self, num: str) -> str:
        cnt = Counter(num)
        ans = ''
        for i in range(9, -1, -1):
            v = str(i)
            if cnt[v] % 2:
                ans = v
                cnt[v] -= 1
                break
        for i in range(10):
            v = str(i)
            if cnt[v]:
                cnt[v] //= 2
                s = cnt[v] * v
                ans = s + ans + s
        return ans.strip('0') or '0'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestPalindromic(String num) {
        int[] cnt = new int[10];
        for (char c : num.toCharArray()) {
            ++cnt[c - '0'];
        }
        String mid = "";
        for (int i = 9; i >= 0; --i) {
            if (cnt[i] % 2 == 1) {
                mid += i;
                --cnt[i];
                break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] > 0) {
                cnt[i] >>= 1;
                sb.append(("" + i).repeat(cnt[i]));
            }
        }
        while (sb.length() > 0 && sb.charAt(sb.length() - 1) == '0') {
            sb.deleteCharAt(sb.length() - 1);
        }
        String t = sb.toString();
        String ans = sb.reverse().toString() + mid + t;
        return "".equals(ans) ? "0" : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c : num) ++cnt[c - '0'];
        string mid = "";
        for (int i = 9; ~i; --i) {
            if (cnt[i] % 2) {
                mid += (i + '0');
                --cnt[i];
                break;
            }
        }
        string t = "";
        for (int i = 0; i < 10; ++i) {
            if (cnt[i]) {
                cnt[i] >>= 1;
                while (cnt[i]--) {
                    t += (i + '0');
                }
            }
        }
        while (t.size() && t.back() == '0') {
            t.pop_back();
        }
        string ans = t;
        reverse(ans.begin(), ans.end());
        ans += mid + t;
        return ans == "" ? "0" : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestPalindromic(num string) string {
	cnt := make([]int, 10)
	for _, c := range num {
		cnt[c-'0']++
	}
	ans := ""
	for i := 9; i >= 0; i-- {
		if cnt[i]%2 == 1 {
			ans = strconv.Itoa(i)
			cnt[i]--
			break
		}
	}
	for i := 0; i < 10; i++ {
		if cnt[i] > 0 {
			cnt[i] >>= 1
			s := strings.Repeat(strconv.Itoa(i), cnt[i])
			ans = s + ans + s
		}
	}
	ans = strings.Trim(ans, "0")
	if ans == "" {
		return "0"
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestPalindromic(num: string): string {
    const count = new Array(10).fill(0);
    for (const c of num) {
        count[c]++;
    }
    while (count.reduce((r, v) => (v % 2 === 1 ? r + 1 : r), 0) > 1) {
        for (let i = 0; i < 10; i++) {
            if (count[i] % 2 === 1) {
                count[i]--;
                break;
            }
        }
    }

    let res = [];
    let oddIndex = -1;
    for (let i = 9; i >= 0; i--) {
        if (count[i] % 2 == 1) {
            oddIndex = i;
            count[i] -= 1;
        }
        res.push(...new Array(count[i] >> 1).fill(i));
    }
    if (oddIndex !== -1) {
        res.push(oddIndex);
    }
    const n = res.length;
    for (let i = 0; i < n; i++) {
        if (res[i] !== 0) {
            res = res.slice(i);
            if (oddIndex !== -1) {
                res.push(...[...res.slice(0, res.length - 1)].reverse());
            } else {
                res.push(...[...res].reverse());
            }
            return res.join('');
        }
    }

    return '0';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由数字（<code>0 - 9</code>）组成的字符串 <code>num</code> 。</p>

<p>请你找出能够使用 <code>num</code> 中数字形成的 <strong>最大回文</strong> 整数，并以字符串形式返回。该整数不含 <strong>前导零</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>你 <strong>无需</strong> 使用 <code>num</code> 中的所有数字，但你必须使用 <strong>至少</strong> 一个数字。</li>
	<li>数字可以重新排序。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "444947137"
<strong>输出：</strong>"7449447"
<strong>解释：</strong>
从 "<em><strong>44494</strong></em><em><strong>7</strong></em>13<em><strong>7</strong></em>" 中选用数字 "4449477"，可以形成回文整数 "7449447" 。
可以证明 "7449447" 是能够形成的最大回文整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "00009"
<strong>输出：</strong>"9"
<strong>解释：</strong>
可以证明 "9" 能够形成的最大回文整数。
注意返回的整数不应含前导零。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> 由数字（<code>0 - 9</code>）组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计 + 贪心

用 $cnt$ 数组记录每个数字出现的次数。

回文数字需要满足回文串中最多有一个数字出现了奇数次，因此我们先找最大的、出现了奇数次的数字 $v$（也可能不存在），作为回文数字的中间数字，对应的 $cnt$ 减 $1$。

接下来我们从回文数字中间，按数字从小到大的顺序，往左右两边扩散（也可以枚举回文串的右半部分，然后将右半部分反转，得到左半部分）。这样我们可以得到一个“可能”含有前导零的回文串。

我们去除回文串的前导零，若回文串为空，则返回“0”。否则返回该回文串。

时间复杂度 $O(n)$，其中 $n$ 为 $num$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestPalindromic(self, num: str) -> str:
        cnt = Counter(num)
        ans = ''
        for i in range(9, -1, -1):
            v = str(i)
            if cnt[v] % 2:
                ans = v
                cnt[v] -= 1
                break
        for i in range(10):
            v = str(i)
            if cnt[v]:
                cnt[v] //= 2
                s = cnt[v] * v
                ans = s + ans + s
        return ans.strip('0') or '0'
```

#### Java

```java
class Solution {
    public String largestPalindromic(String num) {
        int[] cnt = new int[10];
        for (char c : num.toCharArray()) {
            ++cnt[c - '0'];
        }
        String mid = "";
        for (int i = 9; i >= 0; --i) {
            if (cnt[i] % 2 == 1) {
                mid += i;
                --cnt[i];
                break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] > 0) {
                cnt[i] >>= 1;
                sb.append(("" + i).repeat(cnt[i]));
            }
        }
        while (sb.length() > 0 && sb.charAt(sb.length() - 1) == '0') {
            sb.deleteCharAt(sb.length() - 1);
        }
        String t = sb.toString();
        String ans = sb.reverse().toString() + mid + t;
        return "".equals(ans) ? "0" : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c : num) ++cnt[c - '0'];
        string mid = "";
        for (int i = 9; ~i; --i) {
            if (cnt[i] % 2) {
                mid += (i + '0');
                --cnt[i];
                break;
            }
        }
        string t = "";
        for (int i = 0; i < 10; ++i) {
            if (cnt[i]) {
                cnt[i] >>= 1;
                while (cnt[i]--) {
                    t += (i + '0');
                }
            }
        }
        while (t.size() && t.back() == '0') {
            t.pop_back();
        }
        string ans = t;
        reverse(ans.begin(), ans.end());
        ans += mid + t;
        return ans == "" ? "0" : ans;
    }
};
```

#### Go

```go
func largestPalindromic(num string) string {
	cnt := make([]int, 10)
	for _, c := range num {
		cnt[c-'0']++
	}
	ans := ""
	for i := 9; i >= 0; i-- {
		if cnt[i]%2 == 1 {
			ans = strconv.Itoa(i)
			cnt[i]--
			break
		}
	}
	for i := 0; i < 10; i++ {
		if cnt[i] > 0 {
			cnt[i] >>= 1
			s := strings.Repeat(strconv.Itoa(i), cnt[i])
			ans = s + ans + s
		}
	}
	ans = strings.Trim(ans, "0")
	if ans == "" {
		return "0"
	}
	return ans
}
```

#### TypeScript

```ts
function largestPalindromic(num: string): string {
    const count = new Array(10).fill(0);
    for (const c of num) {
        count[c]++;
    }
    while (count.reduce((r, v) => (v % 2 === 1 ? r + 1 : r), 0) > 1) {
        for (let i = 0; i < 10; i++) {
            if (count[i] % 2 === 1) {
                count[i]--;
                break;
            }
        }
    }

    let res = [];
    let oddIndex = -1;
    for (let i = 9; i >= 0; i--) {
        if (count[i] % 2 == 1) {
            oddIndex = i;
            count[i] -= 1;
        }
        res.push(...new Array(count[i] >> 1).fill(i));
    }
    if (oddIndex !== -1) {
        res.push(oddIndex);
    }
    const n = res.length;
    for (let i = 0; i < n; i++) {
        if (res[i] !== 0) {
            res = res.slice(i);
            if (oddIndex !== -1) {
                res.push(...[...res.slice(0, res.length - 1)].reverse());
            } else {
                res.push(...[...res].reverse());
            }
            return res.join('');
        }
    }

    return '0';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2385. 感染二叉树需要的总时间](https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected){#2385}

{{< tabs "2385" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def dfs(node: Optional[TreeNode], fa: Optional[TreeNode]):
            if node is None:
                return
            if fa:
                g[node.val].append(fa.val)
                g[fa.val].append(node.val)
            dfs(node.left, node)
            dfs(node.right, node)

        def dfs2(node: int, fa: int) -> int:
            ans = 0
            for nxt in g[node]:
                if nxt != fa:
                    ans = max(ans, 1 + dfs2(nxt, node))
            return ans

        g = defaultdict(list)
        dfs(root, None)
        return dfs2(start, -1)
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
    private Map<Integer, List<Integer>> g = new HashMap<>();

    public int amountOfTime(TreeNode root, int start) {
        dfs(root, null);
        return dfs2(start, -1);
    }

    private void dfs(TreeNode node, TreeNode fa) {
        if (node == null) {
            return;
        }
        if (fa != null) {
            g.computeIfAbsent(node.val, k -> new ArrayList<>()).add(fa.val);
            g.computeIfAbsent(fa.val, k -> new ArrayList<>()).add(node.val);
        }
        dfs(node.left, node);
        dfs(node.right, node);
    }

    private int dfs2(int node, int fa) {
        int ans = 0;
        for (int nxt : g.getOrDefault(node, List.of())) {
            if (nxt != fa) {
                ans = Math.max(ans, 1 + dfs2(nxt, node));
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> g;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* fa) {
            if (!node) {
                return;
            }
            if (fa) {
                g[node->val].push_back(fa->val);
                g[fa->val].push_back(node->val);
            }
            dfs(node->left, node);
            dfs(node->right, node);
        };
        function<int(int, int)> dfs2 = [&](int node, int fa) -> int {
            int ans = 0;
            for (int nxt : g[node]) {
                if (nxt != fa) {
                    ans = max(ans, 1 + dfs2(nxt, node));
                }
            }
            return ans;
        };
        dfs(root, nullptr);
        return dfs2(start, -1);
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
func amountOfTime(root *TreeNode, start int) int {
	g := map[int][]int{}
	var dfs func(*TreeNode, *TreeNode)
	dfs = func(node, fa *TreeNode) {
		if node == nil {
			return
		}
		if fa != nil {
			g[node.Val] = append(g[node.Val], fa.Val)
			g[fa.Val] = append(g[fa.Val], node.Val)
		}
		dfs(node.Left, node)
		dfs(node.Right, node)
	}
	var dfs2 func(int, int) int
	dfs2 = func(node, fa int) (ans int) {
		for _, nxt := range g[node] {
			if nxt != fa {
				ans = max(ans, 1+dfs2(nxt, node))
			}
		}
		return
	}
	dfs(root, nil)
	return dfs2(start, -1)
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

function amountOfTime(root: TreeNode | null, start: number): number {
    const g: Map<number, number[]> = new Map();
    const dfs = (node: TreeNode | null, fa: TreeNode | null) => {
        if (!node) {
            return;
        }
        if (fa) {
            if (!g.has(node.val)) {
                g.set(node.val, []);
            }
            g.get(node.val)!.push(fa.val);
            if (!g.has(fa.val)) {
                g.set(fa.val, []);
            }
            g.get(fa.val)!.push(node.val);
        }
        dfs(node.left, node);
        dfs(node.right, node);
    };
    const dfs2 = (node: number, fa: number): number => {
        let ans = 0;
        for (const nxt of g.get(node) || []) {
            if (nxt !== fa) {
                ans = Math.max(ans, 1 + dfs2(nxt, node));
            }
        }
        return ans;
    };
    dfs(root, null);
    return dfs2(start, -1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> ，二叉树中节点的值 <strong>互不相同</strong> 。另给你一个整数 <code>start</code> 。在第 <code>0</code> 分钟，<strong>感染</strong> 将会从值为 <code>start</code> 的节点开始爆发。</p>

<p>每分钟，如果节点满足以下全部条件，就会被感染：</p>

<ul>
	<li>节点此前还没有感染。</li>
	<li>节点与一个已感染节点相邻。</li>
</ul>

<p>返回感染整棵树需要的分钟数<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2385.Amount%20of%20Time%20for%20Binary%20Tree%20to%20Be%20Infected/images/image-20220625231744-1.png" style="width: 400px; height: 306px;">
<pre><strong>输入：</strong>root = [1,5,3,null,4,10,6,9,2], start = 3
<strong>输出：</strong>4
<strong>解释：</strong>节点按以下过程被感染：
- 第 0 分钟：节点 3
- 第 1 分钟：节点 1、10、6
- 第 2 分钟：节点5
- 第 3 分钟：节点 4
- 第 4 分钟：节点 9 和 2
感染整棵树需要 4 分钟，所以返回 4 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2385.Amount%20of%20Time%20for%20Binary%20Tree%20to%20Be%20Infected/images/image-20220625231812-2.png" style="width: 75px; height: 66px;">
<pre><strong>输入：</strong>root = [1], start = 1
<strong>输出：</strong>0
<strong>解释：</strong>第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>每个节点的值 <strong>互不相同</strong></li>
	<li>树中必定存在值为 <code>start</code> 的节点</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们先通过一次 $\textit{DFS}$ 建图，得到一个邻接表 $g$，其中 $g[node]$ 表示与节点 $node$ 相连的所有节点。

然后，我们以 $start$ 作为起点，通过 $\textit{DFS}$ 搜索整棵树，找到最远距离，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def dfs(node: Optional[TreeNode], fa: Optional[TreeNode]):
            if node is None:
                return
            if fa:
                g[node.val].append(fa.val)
                g[fa.val].append(node.val)
            dfs(node.left, node)
            dfs(node.right, node)

        def dfs2(node: int, fa: int) -> int:
            ans = 0
            for nxt in g[node]:
                if nxt != fa:
                    ans = max(ans, 1 + dfs2(nxt, node))
            return ans

        g = defaultdict(list)
        dfs(root, None)
        return dfs2(start, -1)
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
    private Map<Integer, List<Integer>> g = new HashMap<>();

    public int amountOfTime(TreeNode root, int start) {
        dfs(root, null);
        return dfs2(start, -1);
    }

    private void dfs(TreeNode node, TreeNode fa) {
        if (node == null) {
            return;
        }
        if (fa != null) {
            g.computeIfAbsent(node.val, k -> new ArrayList<>()).add(fa.val);
            g.computeIfAbsent(fa.val, k -> new ArrayList<>()).add(node.val);
        }
        dfs(node.left, node);
        dfs(node.right, node);
    }

    private int dfs2(int node, int fa) {
        int ans = 0;
        for (int nxt : g.getOrDefault(node, List.of())) {
            if (nxt != fa) {
                ans = Math.max(ans, 1 + dfs2(nxt, node));
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> g;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* fa) {
            if (!node) {
                return;
            }
            if (fa) {
                g[node->val].push_back(fa->val);
                g[fa->val].push_back(node->val);
            }
            dfs(node->left, node);
            dfs(node->right, node);
        };
        function<int(int, int)> dfs2 = [&](int node, int fa) -> int {
            int ans = 0;
            for (int nxt : g[node]) {
                if (nxt != fa) {
                    ans = max(ans, 1 + dfs2(nxt, node));
                }
            }
            return ans;
        };
        dfs(root, nullptr);
        return dfs2(start, -1);
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
func amountOfTime(root *TreeNode, start int) int {
	g := map[int][]int{}
	var dfs func(*TreeNode, *TreeNode)
	dfs = func(node, fa *TreeNode) {
		if node == nil {
			return
		}
		if fa != nil {
			g[node.Val] = append(g[node.Val], fa.Val)
			g[fa.Val] = append(g[fa.Val], node.Val)
		}
		dfs(node.Left, node)
		dfs(node.Right, node)
	}
	var dfs2 func(int, int) int
	dfs2 = func(node, fa int) (ans int) {
		for _, nxt := range g[node] {
			if nxt != fa {
				ans = max(ans, 1+dfs2(nxt, node))
			}
		}
		return
	}
	dfs(root, nil)
	return dfs2(start, -1)
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

function amountOfTime(root: TreeNode | null, start: number): number {
    const g: Map<number, number[]> = new Map();
    const dfs = (node: TreeNode | null, fa: TreeNode | null) => {
        if (!node) {
            return;
        }
        if (fa) {
            if (!g.has(node.val)) {
                g.set(node.val, []);
            }
            g.get(node.val)!.push(fa.val);
            if (!g.has(fa.val)) {
                g.set(fa.val, []);
            }
            g.get(fa.val)!.push(node.val);
        }
        dfs(node.left, node);
        dfs(node.right, node);
    };
    const dfs2 = (node: number, fa: number): number => {
        let ans = 0;
        for (const nxt of g.get(node) || []) {
            if (nxt !== fa) {
                ans = Math.max(ans, 1 + dfs2(nxt, node));
            }
        }
        return ans;
    };
    dfs(root, null);
    return dfs2(start, -1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2386. 找出数组的第 K 大和](https://leetcode.cn/problems/find-the-k-sum-of-an-array){#2386}

{{< tabs "2386" >}}

{{% tab "python" %}}
```python
class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        mx = 0
        for i, x in enumerate(nums):
            if x > 0:
                mx += x
            else:
                nums[i] = -x
        nums.sort()
        h = [(0, 0)]
        for _ in range(k - 1):
            s, i = heappop(h)
            if i < len(nums):
                heappush(h, (s + nums[i], i + 1))
                if i:
                    heappush(h, (s + nums[i] - nums[i - 1], i + 1))
        return mx - h[0][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long kSum(int[] nums, int k) {
        long mx = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                mx += nums[i];
            } else {
                nums[i] *= -1;
            }
        }
        Arrays.sort(nums);
        PriorityQueue<Pair<Long, Integer>> pq
            = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        pq.offer(new Pair<>(0L, 0));
        while (--k > 0) {
            var p = pq.poll();
            long s = p.getKey();
            int i = p.getValue();
            if (i < n) {
                pq.offer(new Pair<>(s + nums[i], i + 1));
                if (i > 0) {
                    pq.offer(new Pair<>(s + nums[i] - nums[i - 1], i + 1));
                }
            }
        }
        return mx - pq.peek().getKey();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long mx = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                mx += nums[i];
            } else {
                nums[i] *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});
        while (--k) {
            auto p = pq.top();
            pq.pop();
            long long s = p.first;
            int i = p.second;
            if (i < n) {
                pq.push({s + nums[i], i + 1});
                if (i) {
                    pq.push({s + nums[i] - nums[i - 1], i + 1});
                }
            }
        }
        return mx - pq.top().first;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kSum(nums []int, k int) int64 {
	mx := 0
	for i, x := range nums {
		if x > 0 {
			mx += x
		} else {
			nums[i] *= -1
		}
	}
	sort.Ints(nums)
	h := &hp{{0, 0}}
	for k > 1 {
		k--
		p := heap.Pop(h).(pair)
		if p.i < len(nums) {
			heap.Push(h, pair{p.sum + nums[p.i], p.i + 1})
			if p.i > 0 {
				heap.Push(h, pair{p.sum + nums[p.i] - nums[p.i-1], p.i + 1})
			}
		}
	}
	return int64(mx) - int64((*h)[0].sum)
}

type pair struct{ sum, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].sum < h[j].sum }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。你可以选择数组的任一 <strong>子序列</strong> 并且对其全部元素求和。</p>

<p>数组的 <strong>第 k 大和</strong> 定义为：可以获得的第 <code>k</code> 个 <strong>最大</strong> 子序列和（子序列和允许出现重复）</p>

<p>返回数组的 <strong>第 k 大和</strong> 。</p>

<p>子序列是一个可以由其他数组删除某些或不删除元素派生而来的数组，且派生过程不改变剩余元素的顺序。</p>

<p><strong>注意：</strong>空子序列的和视作 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,-2], k = 5
<strong>输出：</strong>2
<strong>解释：</strong>所有可能获得的子序列和列出如下，按递减顺序排列：
6、4、4、2、<strong><em>2</em></strong>、0、0、-2
数组的第 5 大和是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,3,4,-10,12], k = 16
<strong>输出：</strong>10
<strong>解释：</strong>数组的第 16 大和是 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(2000, 2<sup>n</sup>)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

首先，我们找到最大的子序和 $mx$，即所有正数之和。

可以发现，其他子序列的和，都可以看成在这个最大子序列和之上，减去其他部分子序列之和得到。因此，我们可以将问题转换为求第 $k$ 小的子序列和。

只需要将所有数的绝对值升序排列，之后建立小根堆，存储二元组 $(s, i)$，表示当前和为 $s$，且下一个待选择的数字的下标为 $i$ 的子序列。

每次取出堆顶，并放入两种新情况：一是再选择下一位，二是选择下一位并且不选择本位。

由于数组是从小到大排序，这种方式能够不重不漏地按序遍历完所有的子序列和。

时间复杂度 $O(n \times \log n + k \times \log k)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        mx = 0
        for i, x in enumerate(nums):
            if x > 0:
                mx += x
            else:
                nums[i] = -x
        nums.sort()
        h = [(0, 0)]
        for _ in range(k - 1):
            s, i = heappop(h)
            if i < len(nums):
                heappush(h, (s + nums[i], i + 1))
                if i:
                    heappush(h, (s + nums[i] - nums[i - 1], i + 1))
        return mx - h[0][0]
```

#### Java

```java
class Solution {
    public long kSum(int[] nums, int k) {
        long mx = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                mx += nums[i];
            } else {
                nums[i] *= -1;
            }
        }
        Arrays.sort(nums);
        PriorityQueue<Pair<Long, Integer>> pq
            = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        pq.offer(new Pair<>(0L, 0));
        while (--k > 0) {
            var p = pq.poll();
            long s = p.getKey();
            int i = p.getValue();
            if (i < n) {
                pq.offer(new Pair<>(s + nums[i], i + 1));
                if (i > 0) {
                    pq.offer(new Pair<>(s + nums[i] - nums[i - 1], i + 1));
                }
            }
        }
        return mx - pq.peek().getKey();
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long mx = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                mx += nums[i];
            } else {
                nums[i] *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});
        while (--k) {
            auto p = pq.top();
            pq.pop();
            long long s = p.first;
            int i = p.second;
            if (i < n) {
                pq.push({s + nums[i], i + 1});
                if (i) {
                    pq.push({s + nums[i] - nums[i - 1], i + 1});
                }
            }
        }
        return mx - pq.top().first;
    }
};
```

#### Go

```go
func kSum(nums []int, k int) int64 {
	mx := 0
	for i, x := range nums {
		if x > 0 {
			mx += x
		} else {
			nums[i] *= -1
		}
	}
	sort.Ints(nums)
	h := &hp{{0, 0}}
	for k > 1 {
		k--
		p := heap.Pop(h).(pair)
		if p.i < len(nums) {
			heap.Push(h, pair{p.sum + nums[p.i], p.i + 1})
			if p.i > 0 {
				heap.Push(h, pair{p.sum + nums[p.i] - nums[p.i-1], p.i + 1})
			}
		}
	}
	return int64(mx) - int64((*h)[0].sum)
}

type pair struct{ sum, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].sum < h[j].sum }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2387. 行排序矩阵的中位数 🔒](https://leetcode.cn/problems/median-of-a-row-wise-sorted-matrix){#2387}

{{< tabs "2387" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixMedian(self, grid: List[List[int]]) -> int:
        def count(x):
            return sum(bisect_right(row, x) for row in grid)

        m, n = len(grid), len(grid[0])
        target = (m * n + 1) >> 1
        return bisect_left(range(10**6 + 1), target, key=count)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;

    public int matrixMedian(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        int target = (m * n + 1) >> 1;
        int left = 0, right = 1000010;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int count(int x) {
        int cnt = 0;
        for (var row : grid) {
            int left = 0, right = row.length;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] > x) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            cnt += left;
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
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = 0, right = 1e6 + 1;
        int target = (m * n + 1) >> 1;
        auto count = [&](int x) {
            int cnt = 0;
            for (auto& row : grid) {
                cnt += (upper_bound(row.begin(), row.end(), x) - row.begin());
            }
            return cnt;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matrixMedian(grid [][]int) int {
	m, n := len(grid), len(grid[0])

	count := func(x int) int {
		cnt := 0
		for _, row := range grid {
			left, right := 0, n
			for left < right {
				mid := (left + right) >> 1
				if row[mid] > x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			cnt += left
		}
		return cnt
	}
	left, right := 0, 1000010
	target := (m*n + 1) >> 1
	for left < right {
		mid := (left + right) >> 1
		if count(mid) >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含&nbsp;<strong>奇数&nbsp;</strong>个整数的&nbsp;<code>m x n</code> 矩阵&nbsp;<code>grid</code>，其中每一行按 <strong>非递减 </strong>的顺序排序，返回矩阵的&nbsp;<strong>中位数</strong>。</p>

<p>你必须以 <code>O(m * log(n))</code> 的时间复杂度来解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,1,2],[2,3,3],[1,3,4]]
<strong>输出:</strong> 2
<strong>解释:</strong> 矩阵的元素按顺序排列为 1,1,1,2,<u>2</u>,3,3,3,4。中位数是 2。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,1,3,3,4]]
<strong>输出:</strong> 3
<strong>解释:</strong> 矩阵的元素按顺序排列为 1,1,<u>3</u>,3,4。中位数是 3。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>m</code> 和&nbsp;<code>n</code>&nbsp;都是奇数。</li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>grid[i]</code> 按非递减顺序排序</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次二分查找

中位数实际上是排序后第 $target = \left \lceil \frac{m\times n}{2} \right \rceil$ 个数。

我们二分枚举矩阵的元素 $x$，统计网格中大于该元素的个数 $cnt$，如果 $cnt \ge target$，说明中位数在 $x$ 的左侧（包含 $x$），否则在右侧。

时间复杂度 $O(m\times \log n \times log M)$，其中 $m$ 和 $n$ 分别为网格的行数和列数，而 $M$ 为网格中的最大元素。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixMedian(self, grid: List[List[int]]) -> int:
        def count(x):
            return sum(bisect_right(row, x) for row in grid)

        m, n = len(grid), len(grid[0])
        target = (m * n + 1) >> 1
        return bisect_left(range(10**6 + 1), target, key=count)
```

#### Java

```java
class Solution {
    private int[][] grid;

    public int matrixMedian(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        int target = (m * n + 1) >> 1;
        int left = 0, right = 1000010;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int count(int x) {
        int cnt = 0;
        for (var row : grid) {
            int left = 0, right = row.length;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] > x) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            cnt += left;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = 0, right = 1e6 + 1;
        int target = (m * n + 1) >> 1;
        auto count = [&](int x) {
            int cnt = 0;
            for (auto& row : grid) {
                cnt += (upper_bound(row.begin(), row.end(), x) - row.begin());
            }
            return cnt;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func matrixMedian(grid [][]int) int {
	m, n := len(grid), len(grid[0])

	count := func(x int) int {
		cnt := 0
		for _, row := range grid {
			left, right := 0, n
			for left < right {
				mid := (left + right) >> 1
				if row[mid] > x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			cnt += left
		}
		return cnt
	}
	left, right := 0, 1000010
	target := (m*n + 1) >> 1
	for left < right {
		mid := (left + right) >> 1
		if count(mid) >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2388. 将表中的空值更改为前一个值 🔒](https://leetcode.cn/problems/change-null-values-in-a-table-to-the-previous-value){#2388}

{{< tabs "2388" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT *, ROW_NUMBER() OVER () AS rk
        FROM CoffeeShop
    ),
    T AS (
        SELECT
            *,
            SUM(
                CASE
                    WHEN drink IS NULL THEN 0
                    ELSE 1
                END
            ) OVER (ORDER BY rk) AS gid
        FROM S
    )
SELECT
    id,
    MAX(drink) OVER (
        PARTITION BY gid
        ORDER BY rk
    ) AS drink
FROM T;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>CoffeeShop</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| drink       | varchar |
+-------------+---------+
id 是该表的主键（具有唯一值的列）。
该表中的每一行都显示了订单 id 和所点饮料的名称。一些饮料行为 null。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案将 drink 的 <code>null</code>&nbsp;值替换为前面最近一行不为 <code>null</code>&nbsp;的 drink。保证表第一行的 drink 不为 <code>null</code>。</p>

<p>返回&nbsp;<strong>与输入顺序相同的&nbsp;</strong>结果表。</p>

<p>查询结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
CoffeeShop 表:
+----+-------------------+
| id | drink             |
+----+-------------------+
| 9  | Rum and Coke      |
| 6  | null              |
| 7  | null              |
| 3  | St Germain Spritz |
| 1  | Orange Margarita  |
| 2  | null              |
+----+-------------------+
<strong>输出:</strong> 
+----+-------------------+
| id | drink             |
+----+-------------------+
| 9  | Rum and Coke      |
| 6  | Rum and Coke      |
| 7  | Rum and Coke      |
| 3  | St Germain Spritz |
| 1  | Orange Margarita  |
| 2  | Orange Margarita  |
+----+-------------------+
<strong>解释:</strong> 
对于 ID 6，之前不为空的值来自 ID 9。我们将 null 替换为 "Rum and Coke"。
对于 ID 7，之前不为空的值来自 ID 9。我们将 null 替换为 "Rum and Coke"。
对于 ID 2，之前不为空的值来自 ID 1。我们将 null 替换为 "Orange Margarita"。
请注意，输出中的行与输入中的行相同。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：临时变量

我们可以使用一个临时变量 $cur$ 来记录上一个不为 $null$ 的值，如果当前值为 $null$，则将 $cur$ 的值赋给当前值，否则我们更新 $cur$ 的值为当前值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    id,
    CASE
        WHEN drink IS NOT NULL THEN @cur := drink
        ELSE @cur
    END AS drink
FROM CoffeeShop;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们先用窗口函数 `row_number()` 为每一行生成一个序号，然后使用 `sum()` 窗口函数来生成一个分组序号，分组序号的生成规则为：如果当前行的值为 $null$，则分组序号与上一行相同，否则分组序号加一。最后我们使用 `max()` 窗口函数来获取每一组唯一一个不为 $null$ 的值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT *, ROW_NUMBER() OVER () AS rk
        FROM CoffeeShop
    ),
    T AS (
        SELECT
            *,
            SUM(
                CASE
                    WHEN drink IS NULL THEN 0
                    ELSE 1
                END
            ) OVER (ORDER BY rk) AS gid
        FROM S
    )
SELECT
    id,
    MAX(drink) OVER (
        PARTITION BY gid
        ORDER BY rk
    ) AS drink
FROM T;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2389. 和有限的最长子序列](https://leetcode.cn/problems/longest-subsequence-with-limited-sum){#2389}

{{< tabs "2389" >}}

{{% tab "python" %}}
```python
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        m = len(queries)
        ans = [0] * m
        idx = sorted(range(m), key=lambda i: queries[i])
        s = j = 0
        for i in idx:
            while j < len(nums) and s + nums[j] <= queries[i]:
                s += nums[j]
                j += 1
            ans[i] = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int m = queries.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[i] - queries[j]);
        int[] ans = new int[m];
        int s = 0, j = 0;
        for (int i : idx) {
            while (j < nums.length && s + nums[j] <= queries[i]) {
                s += nums[j++];
            }
            ans[i] = j;
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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        vector<int> ans(m);
        int s = 0, j = 0;
        for (int i : idx) {
            while (j < nums.size() && s + nums[j] <= queries[i]) {
                s += nums[j++];
            }
            ans[i] = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func answerQueries(nums []int, queries []int) (ans []int) {
	sort.Ints(nums)
	m := len(queries)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[i]] < queries[idx[j]] })
	ans = make([]int, m)
	s, j := 0, 0
	for _, i := range idx {
		for j < len(nums) && s+nums[j] <= queries[i] {
			s += nums[j]
			j++
		}
		ans[i] = j
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function answerQueries(nums: number[], queries: number[]): number[] {
    nums.sort((a, b) => a - b);
    const m = queries.length;
    const idx: number[] = new Array(m);
    for (let i = 0; i < m; i++) {
        idx[i] = i;
    }
    idx.sort((i, j) => queries[i] - queries[j]);
    const ans: number[] = new Array(m);
    let s = 0;
    let j = 0;
    for (const i of idx) {
        while (j < nums.length && s + nums[j] <= queries[i]) {
            s += nums[j++];
        }
        ans[i] = j;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        nums.sort();

        for i in 1..nums.len() {
            nums[i] += nums[i - 1];
        }

        queries.iter().map(|&q| {
            match nums.binary_search(&q) {
                Ok(idx) => idx as i32 + 1,
                Err(idx) => idx as i32,
            }
        }).collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function (nums, queries) {
    nums.sort((a, b) => a - b);
    for (let i = 1; i < nums.length; i++) {
        nums[i] += nums[i - 1];
    }
    return queries.map(q => _.sortedIndex(nums, q + 1));
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] AnswerQueries(int[] nums, int[] queries) {
        Array.Sort(nums);
        for (int i = 1; i < nums.Length; ++i) {
            nums[i] += nums[i - 1];
        }
        int m = queries.Length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = Array.BinarySearch(nums, queries[i] + 1);
            ans[i] = j < 0 ? -j - 1 : j;
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组 <code>nums</code> ，和一个长度为 <code>m</code> 的整数数组 <code>queries</code> 。</p>

<p>返回一个长度为 <code>m</code> 的数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i]</code><em> </em>是 <code>nums</code> 中<span style=""> </span>元素之和小于等于 <code>queries[i]</code> 的 <strong>子序列</strong> 的 <strong>最大</strong> 长度<span style="">&nbsp;</span><span style=""> </span>。</p>

<p><strong>子序列</strong> 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,2,1], queries = [3,10,21]
<strong>输出：</strong>[2,3,4]
<strong>解释：</strong>queries 对应的 answer 如下：
- 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
- 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
- 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,4,5], queries = [1]
<strong>输出：</strong>[0]
<strong>解释：</strong>空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找

根据题目描述，对于每个 $\textit{queries[i]}$，我们需要找到一个子序列，使得该子序列的元素和不超过 $\textit{queries[i]}$，且该子序列的长度最大化。显然，我们应该选择尽可能小的元素，这样才能使得子序列的长度最大化。

因此，我们可以先将数组 $\textit{nums}$ 进行升序排序，然后对于每个 $\textit{queries[i]}$，我们可以使用二分查找，找到最小的下标 $j$，使得 $\textit{nums}[0] + \textit{nums}[1] + \cdots + \textit{nums}[j] > \textit{queries[i]}$。此时 $\textit{nums}[0] + \textit{nums}[1] + \cdots + \textit{nums}[j - 1]$ 就是满足条件的子序列的元素和，且该子序列的长度为 $j$。因此，我们可以将 $j$ 加入答案数组中。

时间复杂度 $O((n + m) \times \log n)$，空间复杂度 $O(n)$ 或 $O(\log n)$。其中 $n$ 和 $m$ 分别是数组 $\textit{nums}$ 和 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        s = list(accumulate(nums))
        return [bisect_right(s, q) for q in queries]
```

#### Java

```java
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; ++i) {
            nums[i] += nums[i - 1];
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = Arrays.binarySearch(nums, queries[i] + 1);
            ans[i] = j < 0 ? -j - 1 : j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        vector<int> ans;
        for (const auto& q : queries) {
            ans.emplace_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return ans;
    }
};
```

#### Go

```go
func answerQueries(nums []int, queries []int) (ans []int) {
	sort.Ints(nums)
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	for _, q := range queries {
		ans = append(ans, sort.SearchInts(nums, q+1))
	}
	return
}
```

#### TypeScript

```ts
function answerQueries(nums: number[], queries: number[]): number[] {
    nums.sort((a, b) => a - b);
    for (let i = 1; i < nums.length; i++) {
        nums[i] += nums[i - 1];
    }
    return queries.map(q => _.sortedIndex(nums, q + 1));
}
```

#### Rust

```rust
impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        nums.sort();

        for i in 1..nums.len() {
            nums[i] += nums[i - 1];
        }

        queries.iter().map(|&q| {
            match nums.binary_search(&q) {
                Ok(idx) => idx as i32 + 1,
                Err(idx) => idx as i32,
            }
        }).collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function (nums, queries) {
    nums.sort((a, b) => a - b);
    for (let i = 1; i < nums.length; i++) {
        nums[i] += nums[i - 1];
    }
    return queries.map(q => _.sortedIndex(nums, q + 1));
};
```

#### C#

```cs
public class Solution {
    public int[] AnswerQueries(int[] nums, int[] queries) {
        Array.Sort(nums);
        for (int i = 1; i < nums.Length; ++i) {
            nums[i] += nums[i - 1];
        }
        int m = queries.Length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = Array.BinarySearch(nums, queries[i] + 1);
            ans[i] = j < 0 ? -j - 1 : j;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 离线查询 + 双指针

与方法一类似，我们可以先对数组 $nums$ 进行升序排列。

接下来，我们定义一个长度与 $queries$ 相同的下标数组 $idx$，其中 $idx[i]=i$，然后我们对数组 $idx$ 按照 $queries$ 中的元素值进行升序排序。这样，我们就可以按照 $queries$ 中的元素值从小到大的顺序进行处理。

我们使用一个变量 $s$ 记录当前已经选择的元素的和，使用一个变量 $j$ 记录当前已经选择的元素的个数。初始时 $s = j = 0$。

我们遍历下标数组 $idx$，对于其中的每个下标 $i$，我们循环地将数组 $nums$ 中的元素加入到当前的子序列中，直到 $s + nums[j] \gt queries[i]$，此时 $j$ 即为满足条件的子序列的长度，我们将 $ans[i]$ 的值设为 $j$，然后继续处理下一个下标。

遍历完下标数组 $idx$ 后，我们即可得到答案数组 $ans$，其中 $ans[i]$ 即为满足 $queries[i]$ 的子序列的长度。

时间复杂度 $O(n \times \log n + m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别是数组 $nums$ 和 $queries$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        m = len(queries)
        ans = [0] * m
        idx = sorted(range(m), key=lambda i: queries[i])
        s = j = 0
        for i in idx:
            while j < len(nums) and s + nums[j] <= queries[i]:
                s += nums[j]
                j += 1
            ans[i] = j
        return ans
```

#### Java

```java
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int m = queries.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[i] - queries[j]);
        int[] ans = new int[m];
        int s = 0, j = 0;
        for (int i : idx) {
            while (j < nums.length && s + nums[j] <= queries[i]) {
                s += nums[j++];
            }
            ans[i] = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        vector<int> ans(m);
        int s = 0, j = 0;
        for (int i : idx) {
            while (j < nums.size() && s + nums[j] <= queries[i]) {
                s += nums[j++];
            }
            ans[i] = j;
        }
        return ans;
    }
};
```

#### Go

```go
func answerQueries(nums []int, queries []int) (ans []int) {
	sort.Ints(nums)
	m := len(queries)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[i]] < queries[idx[j]] })
	ans = make([]int, m)
	s, j := 0, 0
	for _, i := range idx {
		for j < len(nums) && s+nums[j] <= queries[i] {
			s += nums[j]
			j++
		}
		ans[i] = j
	}
	return
}
```

#### TypeScript

```ts
function answerQueries(nums: number[], queries: number[]): number[] {
    nums.sort((a, b) => a - b);
    const m = queries.length;
    const idx: number[] = new Array(m);
    for (let i = 0; i < m; i++) {
        idx[i] = i;
    }
    idx.sort((i, j) => queries[i] - queries[j]);
    const ans: number[] = new Array(m);
    let s = 0;
    let j = 0;
    for (const i of idx) {
        while (j < nums.length && s + nums[j] <= queries[i]) {
            s += nums[j++];
        }
        ans[i] = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
