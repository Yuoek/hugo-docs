---
title: "3120_统计特殊字母的数量 I"
date: 2025-10-08T18:40:09+08:00
weight: 3
tags: [前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 最短路, 枚举, 深度优先搜索, 矩阵, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [3120_统计特殊字母的数量 I](#3120)
#### [哈希表](#3120)
#### [字符串](#3120)
### [3121_统计特殊字母的数量 II](#3121)
#### [哈希表](#3121)
#### [字符串](#3121)
### [3122_使矩阵满足条件的最少操作次数](#3122)
#### [数组](#3122)
#### [动态规划](#3122)
#### [矩阵](#3122)
### [3123_最短路径中的边](#3123)
#### [深度优先搜索](#3123)
#### [广度优先搜索](#3123)
#### [图](#3123)
#### [最短路](#3123)
#### [堆（优先队列）](#3123)
### [3124_查找最长的电话 🔒](#3124)
#### [数据库](#3124)
### [3125_使得按位与结果为 0 的最大数字 🔒](#3125)
#### [贪心](#3125)
#### [字符串](#3125)
#### [排序](#3125)
### [3126_服务器利用时间 🔒](#3126)
#### [数据库](#3126)
### [3127_构造相同颜色的正方形](#3127)
#### [数组](#3127)
#### [枚举](#3127)
#### [矩阵](#3127)
### [3128_直角三角形](#3128)
#### [数组](#3128)
#### [哈希表](#3128)
#### [数学](#3128)
#### [组合数学](#3128)
#### [计数](#3128)
### [3129_找出所有稳定的二进制数组 I](#3129)
#### [动态规划](#3129)
#### [前缀和](#3129)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3120_统计特殊字母的数量 I
___
#### 哈希表
___
#### 字符串
---
### 3121_统计特殊字母的数量 II
___
#### 哈希表
___
#### 字符串
---
### 3122_使矩阵满足条件的最少操作次数
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 3123_最短路径中的边
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
---
### 3124_查找最长的电话 🔒
___
#### 数据库
---
### 3125_使得按位与结果为 0 的最大数字 🔒
___
#### 贪心
___
#### 字符串
___
#### 排序
---
### 3126_服务器利用时间 🔒
___
#### 数据库
---
### 3127_构造相同颜色的正方形
___
#### 数组
___
#### 枚举
___
#### 矩阵
---
### 3128_直角三角形
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 组合数学
___
#### 计数
---
### 3129_找出所有稳定的二进制数组 I
___
#### 动态规划
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 最短路 |
| 枚举 | 深度优先搜索 | 矩阵 |
| 组合数学 | 计数 | 贪心 |

# [3120. 统计特殊字母的数量 I](https://leetcode.cn/problems/count-the-number-of-special-characters-i){#3120}

{{< tabs "3120" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        s = set(word)
        return sum(a in s and b in s for a, b in zip(ascii_lowercase, ascii_uppercase))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] s = new boolean['z' + 1];
        for (int i = 0; i < word.length(); ++i) {
            s[word.charAt(i)] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (s['a' + i] && s['A' + i]) {
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
    int numberOfSpecialChars(string word) {
        vector<bool> s('z' + 1);
        for (char& c : word) {
            s[c] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += s['a' + i] && s['A' + i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSpecialChars(word string) (ans int) {
	s := make([]bool, 'z'+1)
	for _, c := range word {
		s[c] = true
	}
	for i := 0; i < 26; i++ {
		if s['a'+i] && s['A'+i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSpecialChars(word: string): number {
    const s: boolean[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => false);
    for (let i = 0; i < word.length; ++i) {
        s[word.charCodeAt(i)] = true;
    }
    let ans: number = 0;
    for (let i = 0; i < 26; ++i) {
        if (s['a'.charCodeAt(0) + i] && s['A'.charCodeAt(0) + i]) {
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

<p>给你一个字符串 <code>word</code>。如果 <code>word</code> 中同时存在某个字母的小写形式和大写形式，则称这个字母为 <strong>特殊字母</strong> 。</p>

<p>返回 <code>word</code> 中<strong> </strong><strong>特殊字母 </strong>的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaAbcBC"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中的特殊字母是 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abc"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在大小写形式同时出现的字母。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abBCab"</span></p>

<p><strong>输出：</strong>1</p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中唯一的特殊字母是 <code>'b'</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> 仅由小写和大写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们用一个哈希表或数组 $s$ 来记录字符串 $word$ 中出现的字符。然后遍历 $26$ 个字母，如果小写字母和大写字母都在 $s$ 中出现，则特殊字符的数量加一。

最后返回特殊字符的数量即可。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串 $word$ 的长度；而 $|\Sigma|$ 为字符集大小，本题中 $|\Sigma| \leq 128$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        s = set(word)
        return sum(a in s and b in s for a, b in zip(ascii_lowercase, ascii_uppercase))
```

#### Java

```java
class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] s = new boolean['z' + 1];
        for (int i = 0; i < word.length(); ++i) {
            s[word.charAt(i)] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (s['a' + i] && s['A' + i]) {
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
    int numberOfSpecialChars(string word) {
        vector<bool> s('z' + 1);
        for (char& c : word) {
            s[c] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += s['a' + i] && s['A' + i];
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSpecialChars(word string) (ans int) {
	s := make([]bool, 'z'+1)
	for _, c := range word {
		s[c] = true
	}
	for i := 0; i < 26; i++ {
		if s['a'+i] && s['A'+i] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfSpecialChars(word: string): number {
    const s: boolean[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => false);
    for (let i = 0; i < word.length; ++i) {
        s[word.charCodeAt(i)] = true;
    }
    let ans: number = 0;
    for (let i = 0; i < 26; ++i) {
        if (s['a'.charCodeAt(0) + i] && s['A'.charCodeAt(0) + i]) {
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

# [3121. 统计特殊字母的数量 II](https://leetcode.cn/problems/count-the-number-of-special-characters-ii){#3121}

{{< tabs "3121" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        first, last = {}, {}
        for i, c in enumerate(word):
            if c not in first:
                first[c] = i
            last[c] = i
        return sum(
            a in last and b in first and last[a] < first[b]
            for a, b in zip(ascii_lowercase, ascii_uppercase)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSpecialChars(String word) {
        int[] first = new int['z' + 1];
        int[] last = new int['z' + 1];
        for (int i = 1; i <= word.length(); ++i) {
            int j = word.charAt(i - 1);
            if (first[j] == 0) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last['a' + i] > 0 && first['A' + i] > 0 && last['a' + i] < first['A' + i]) {
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
    int numberOfSpecialChars(string word) {
        vector<int> first('z' + 1);
        vector<int> last('z' + 1);
        for (int i = 1; i <= word.size(); ++i) {
            int j = word[i - 1];
            if (first[j] == 0) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last['a' + i] && first['A' + i] && last['a' + i] < first['A' + i]) {
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
func numberOfSpecialChars(word string) (ans int) {
	first := make([]int, 'z'+1)
	last := make([]int, 'z'+1)
	for i, c := range word {
		if first[c] == 0 {
			first[c] = i + 1
		}
		last[c] = i + 1
	}
	for i := 0; i < 26; i++ {
		if last['a'+i] > 0 && first['A'+i] > 0 && last['a'+i] < first['A'+i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSpecialChars(word: string): number {
    const first: number[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => 0);
    const last: number[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => 0);
    for (let i = 0; i < word.length; ++i) {
        const j = word.charCodeAt(i);
        if (first[j] === 0) {
            first[j] = i + 1;
        }
        last[j] = i + 1;
    }
    let ans: number = 0;
    for (let i = 0; i < 26; ++i) {
        if (
            last['a'.charCodeAt(0) + i] &&
            first['A'.charCodeAt(0) + i] &&
            last['a'.charCodeAt(0) + i] < first['A'.charCodeAt(0) + i]
        ) {
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

<p>给你一个字符串 <code>word</code>。如果 <code>word</code> 中同时出现某个字母 <code>c</code> 的小写形式和大写形式，并且<strong> 每个 </strong>小写形式的 <code>c</code> 都出现在第一个大写形式的 <code>c</code> 之前，则称字母 <code>c</code> 是一个 <strong>特殊字母</strong> 。</p>

<p>返回 <code>word</code> 中 <strong>特殊字母</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaAbcBC"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>特殊字母是 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abc"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "AbBCab"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写和大写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们定义两个哈希表或数组 $\textit{first}$ 和 $\textit{last}$，用于存储每个字母第一次出现的位置和最后一次出现的位置。

然后我们遍历字符串 $\textit{word}$，更新 $\textit{first}$ 和 $\textit{last}$。

最后我们遍历所有的小写字母和大写字母，如果 $\textit{last}[a]$ 存在且 $\textit{first}[b]$ 存在且 $\textit{last}[a] < \textit{first}[b]$，则说明字母 $a$ 是一个特殊字母，将答案加一。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串 $\textit{word}$ 的长度；而 $|\Sigma|$ 为字符集大小，本题中 $|\Sigma| \leq 128$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        first, last = {}, {}
        for i, c in enumerate(word):
            if c not in first:
                first[c] = i
            last[c] = i
        return sum(
            a in last and b in first and last[a] < first[b]
            for a, b in zip(ascii_lowercase, ascii_uppercase)
        )
```

#### Java

```java
class Solution {
    public int numberOfSpecialChars(String word) {
        int[] first = new int['z' + 1];
        int[] last = new int['z' + 1];
        for (int i = 1; i <= word.length(); ++i) {
            int j = word.charAt(i - 1);
            if (first[j] == 0) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last['a' + i] > 0 && first['A' + i] > 0 && last['a' + i] < first['A' + i]) {
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
    int numberOfSpecialChars(string word) {
        vector<int> first('z' + 1);
        vector<int> last('z' + 1);
        for (int i = 1; i <= word.size(); ++i) {
            int j = word[i - 1];
            if (first[j] == 0) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last['a' + i] && first['A' + i] && last['a' + i] < first['A' + i]) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSpecialChars(word string) (ans int) {
	first := make([]int, 'z'+1)
	last := make([]int, 'z'+1)
	for i, c := range word {
		if first[c] == 0 {
			first[c] = i + 1
		}
		last[c] = i + 1
	}
	for i := 0; i < 26; i++ {
		if last['a'+i] > 0 && first['A'+i] > 0 && last['a'+i] < first['A'+i] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfSpecialChars(word: string): number {
    const first: number[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => 0);
    const last: number[] = Array.from({ length: 'z'.charCodeAt(0) + 1 }, () => 0);
    for (let i = 0; i < word.length; ++i) {
        const j = word.charCodeAt(i);
        if (first[j] === 0) {
            first[j] = i + 1;
        }
        last[j] = i + 1;
    }
    let ans: number = 0;
    for (let i = 0; i < 26; ++i) {
        if (
            last['a'.charCodeAt(0) + i] &&
            first['A'.charCodeAt(0) + i] &&
            last['a'.charCodeAt(0) + i] < first['A'.charCodeAt(0) + i]
        ) {
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

# [3122. 使矩阵满足条件的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-satisfy-conditions){#3122}

{{< tabs "3122" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[inf] * 10 for _ in range(n)]
        for i in range(n):
            cnt = [0] * 10
            for j in range(m):
                cnt[grid[j][i]] += 1
            if i == 0:
                for j in range(10):
                    f[i][j] = m - cnt[j]
            else:
                for j in range(10):
                    for k in range(10):
                        if k != j:
                            f[i][j] = min(f[i][j], f[i - 1][k] + m - cnt[j])
        return min(f[-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[n][10];
        final int inf = 1 << 29;
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[10];
            for (int j = 0; j < m; ++j) {
                ++cnt[grid[j][i]];
            }
            if (i == 0) {
                for (int j = 0; j < 10; ++j) {
                    f[i][j] = m - cnt[j];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 10; ++k) {
                        if (k != j) {
                            f[i][j] = Math.min(f[i][j], f[i - 1][k] + m - cnt[j]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 10; ++j) {
            ans = Math.min(ans, f[n - 1][j]);
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
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[n][10];
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            int cnt[10]{};
            for (int j = 0; j < m; ++j) {
                ++cnt[grid[j][i]];
            }
            if (i == 0) {
                for (int j = 0; j < 10; ++j) {
                    f[i][j] = m - cnt[j];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 10; ++k) {
                        if (k != j) {
                            f[i][j] = min(f[i][j], f[i - 1][k] + m - cnt[j]);
                        }
                    }
                }
            }
        }
        return *min_element(f[n - 1], f[n - 1] + 10);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 10)
		for j := range f[i] {
			f[i][j] = 1 << 29
		}
	}
	for i := 0; i < n; i++ {
		cnt := [10]int{}
		for j := 0; j < m; j++ {
			cnt[grid[j][i]]++
		}
		if i == 0 {
			for j := 0; j < 10; j++ {
				f[i][j] = m - cnt[j]
			}
		} else {
			for j := 0; j < 10; j++ {
				for k := 0; k < 10; k++ {
					if j != k {
						f[i][j] = min(f[i][j], f[i-1][k]+m-cnt[j])
					}
				}
			}
		}
	}
	return slices.Min(f[n-1])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f: number[][] = Array.from({ length: n }, () =>
        Array.from({ length: 10 }, () => Infinity),
    );
    for (let i = 0; i < n; ++i) {
        const cnt: number[] = Array(10).fill(0);
        for (let j = 0; j < m; ++j) {
            cnt[grid[j][i]]++;
        }
        if (i === 0) {
            for (let j = 0; j < 10; ++j) {
                f[i][j] = m - cnt[j];
            }
        } else {
            for (let j = 0; j < 10; ++j) {
                for (let k = 0; k < 10; ++k) {
                    if (j !== k) {
                        f[i][j] = Math.min(f[i][j], f[i - 1][k] + m - cnt[j]);
                    }
                }
            }
        }
    }
    return Math.min(...f[n - 1]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code>&nbsp;的二维矩形&nbsp;<code>grid</code>&nbsp;。每次 <strong>操作</strong>&nbsp;中，你可以将 <strong>任一</strong> 格子的值修改为 <strong>任意</strong>&nbsp;非负整数。完成所有操作后，你需要确保每个格子&nbsp;<code>grid[i][j]</code>&nbsp;的值满足：</p>

<ul>
	<li>如果下面相邻格子存在的话，它们的值相等，也就是&nbsp;<code>grid[i][j] == grid[i + 1][j]</code>（如果存在）。</li>
	<li>如果右边相邻格子存在的话，它们的值不相等，也就是&nbsp;<code>grid[i][j] != grid[i][j + 1]</code>（如果存在）。</li>
</ul>

<p>请你返回需要的 <strong>最少</strong>&nbsp;操作数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,2],[1,0,2]]</span></p>

<p><b>输出：</b>0</p>

<p><b>解释：</b></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3122.Minimum%20Number%20of%20Operations%20to%20Satisfy%20Conditions/images/examplechanged.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>矩阵中所有格子已经满足要求。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,1,1],[0,0,0]]</span></p>

<p><b>输出：</b>3</p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3122.Minimum%20Number%20of%20Operations%20to%20Satisfy%20Conditions/images/example21.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>将矩阵变成&nbsp;<code>[[1,0,1],[1,0,1]]</code>&nbsp;，它满足所有要求，需要 3 次操作：</p>

<ul>
	<li>将&nbsp;<code>grid[1][0]</code>&nbsp;变为 1 。</li>
	<li>将&nbsp;<code>grid[0][1]</code> 变为 0 。</li>
	<li>将&nbsp;<code>grid[1][2]</code>&nbsp;变为 1 。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[2],[3]]</span></p>

<p><b>输出：</b>2</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3122.Minimum%20Number%20of%20Operations%20to%20Satisfy%20Conditions/images/changed.png" style="width: 86px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>这个矩阵只有一列，我们可以通过 2 次操作将所有格子里的值变为 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们注意到，矩阵中格子的值只有 $10$ 种可能，题目需要我们求出每一列数字相同，且相邻列数字不同的最小操作次数。那么我们只需要考虑将数字修改为 $0$ 到 $9$ 的情况即可。

我们定义状态 $f[i][j]$ 表示前 $[0,..i]$ 列数字，且第 $i$ 列数字为 $j$ 的最小操作次数。那么我们可以得到状态转移方程：

$$
f[i][j] = \min_{k \neq j} f[i-1][k] + m - \textit{cnt}[j]
$$

其中 $\textit{cnt}[j]$ 表示第 $i$ 列数字为 $j$ 的个数。

最后我们只需要求出 $f[n-1][j]$ 的最小值即可。

时间复杂度 $O(n \times (m + C^2))$，空间复杂度 $O(n \times C)$。其中 $m$ 和 $n$ 分别表示矩阵的行数和列数；而 $C$ 表示数字的种类数，这里 $C = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[inf] * 10 for _ in range(n)]
        for i in range(n):
            cnt = [0] * 10
            for j in range(m):
                cnt[grid[j][i]] += 1
            if i == 0:
                for j in range(10):
                    f[i][j] = m - cnt[j]
            else:
                for j in range(10):
                    for k in range(10):
                        if k != j:
                            f[i][j] = min(f[i][j], f[i - 1][k] + m - cnt[j])
        return min(f[-1])
```

#### Java

```java
class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[n][10];
        final int inf = 1 << 29;
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[10];
            for (int j = 0; j < m; ++j) {
                ++cnt[grid[j][i]];
            }
            if (i == 0) {
                for (int j = 0; j < 10; ++j) {
                    f[i][j] = m - cnt[j];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 10; ++k) {
                        if (k != j) {
                            f[i][j] = Math.min(f[i][j], f[i - 1][k] + m - cnt[j]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 10; ++j) {
            ans = Math.min(ans, f[n - 1][j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[n][10];
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            int cnt[10]{};
            for (int j = 0; j < m; ++j) {
                ++cnt[grid[j][i]];
            }
            if (i == 0) {
                for (int j = 0; j < 10; ++j) {
                    f[i][j] = m - cnt[j];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 10; ++k) {
                        if (k != j) {
                            f[i][j] = min(f[i][j], f[i - 1][k] + m - cnt[j]);
                        }
                    }
                }
            }
        }
        return *min_element(f[n - 1], f[n - 1] + 10);
    }
};
```

#### Go

```go
func minimumOperations(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 10)
		for j := range f[i] {
			f[i][j] = 1 << 29
		}
	}
	for i := 0; i < n; i++ {
		cnt := [10]int{}
		for j := 0; j < m; j++ {
			cnt[grid[j][i]]++
		}
		if i == 0 {
			for j := 0; j < 10; j++ {
				f[i][j] = m - cnt[j]
			}
		} else {
			for j := 0; j < 10; j++ {
				for k := 0; k < 10; k++ {
					if j != k {
						f[i][j] = min(f[i][j], f[i-1][k]+m-cnt[j])
					}
				}
			}
		}
	}
	return slices.Min(f[n-1])
}
```

#### TypeScript

```ts
function minimumOperations(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f: number[][] = Array.from({ length: n }, () =>
        Array.from({ length: 10 }, () => Infinity),
    );
    for (let i = 0; i < n; ++i) {
        const cnt: number[] = Array(10).fill(0);
        for (let j = 0; j < m; ++j) {
            cnt[grid[j][i]]++;
        }
        if (i === 0) {
            for (let j = 0; j < 10; ++j) {
                f[i][j] = m - cnt[j];
            }
        } else {
            for (let j = 0; j < 10; ++j) {
                for (let k = 0; k < 10; ++k) {
                    if (j !== k) {
                        f[i][j] = Math.min(f[i][j], f[i - 1][k] + m - cnt[j]);
                    }
                }
            }
        }
    }
    return Math.min(...f[n - 1]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3123. 最短路径中的边](https://leetcode.cn/problems/find-edges-in-shortest-paths){#3123}

{{< tabs "3123" >}}

{{% tab "python" %}}
```python
class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        g = defaultdict(list)
        for i, (a, b, w) in enumerate(edges):
            g[a].append((b, w, i))
            g[b].append((a, w, i))
        dist = [inf] * n
        dist[0] = 0
        q = [(0, 0)]
        while q:
            da, a = heappop(q)
            if da > dist[a]:
                continue
            for b, w, _ in g[a]:
                if dist[b] > dist[a] + w:
                    dist[b] = dist[a] + w
                    heappush(q, (dist[b], b))
        m = len(edges)
        ans = [False] * m
        if dist[n - 1] == inf:
            return ans
        q = deque([n - 1])
        while q:
            a = q.popleft()
            for b, w, i in g[a]:
                if dist[a] == dist[b] + w:
                    ans[i] = True
                    q.append(b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean[] findAnswer(int n, int[][] edges) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int m = edges.length;
        for (int i = 0; i < m; ++i) {
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            g[a].add(new int[] {b, w, i});
            g[b].add(new int[] {a, w, i});
        }
        int[] dist = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(dist, inf);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int da = p[0], a = p[1];
            if (da > dist[a]) {
                continue;
            }
            for (var e : g[a]) {
                int b = e[0], w = e[1];
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    pq.offer(new int[] {dist[b], b});
                }
            }
        }
        boolean[] ans = new boolean[m];
        if (dist[n - 1] == inf) {
            return ans;
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(n - 1);
        while (!q.isEmpty()) {
            int a = q.poll();
            for (var e : g[a]) {
                int b = e[0], w = e[1], i = e[2];
                if (dist[a] == dist[b] + w) {
                    ans[i] = true;
                    q.offer(b);
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
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> g(n);
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            auto e = edges[i];
            int a = e[0], b = e[1], w = e[2];
            g[a].push_back({b, w, i});
            g[b].push_back({a, w, i});
        }
        const int inf = 1 << 30;
        vector<int> dist(n, inf);
        dist[0] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [da, a] = pq.top();
            pq.pop();
            if (da > dist[a]) {
                continue;
            }

            for (auto [b, w, _] : g[a]) {
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    pq.push({dist[b], b});
                }
            }
        }
        vector<bool> ans(m);
        if (dist[n - 1] == inf) {
            return ans;
        }
        queue<int> q{{n - 1}};
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (auto [b, w, i] : g[a]) {
                if (dist[a] == dist[b] + w) {
                    ans[i] = true;
                    q.push(b);
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
func findAnswer(n int, edges [][]int) []bool {
	g := make([][][3]int, n)
	for i, e := range edges {
		a, b, w := e[0], e[1], e[2]
		g[a] = append(g[a], [3]int{b, w, i})
		g[b] = append(g[b], [3]int{a, w, i})
	}
	dist := make([]int, n)
	const inf int = 1 << 30
	for i := range dist {
		dist[i] = inf
	}
	dist[0] = 0
	pq := hp{{0, 0}}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		da, a := p.dis, p.u
		if da > dist[a] {
			continue
		}
		for _, e := range g[a] {
			b, w := e[0], e[1]
			if dist[b] > dist[a]+w {
				dist[b] = dist[a] + w
				heap.Push(&pq, pair{dist[b], b})
			}
		}
	}
	ans := make([]bool, len(edges))
	if dist[n-1] == inf {
		return ans
	}
	q := []int{n - 1}
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		for _, e := range g[a] {
			b, w, i := e[0], e[1], e[2]
			if dist[a] == dist[b]+w {
				ans[i] = true
				q = append(q, b)
			}
		}
	}
	return ans
}

type pair struct{ dis, u int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
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

<p>给你一个 <code>n</code>&nbsp;个节点的无向带权图，节点编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。图中总共有 <code>m</code>&nbsp;条边，用二维数组&nbsp;<code>edges</code>&nbsp;表示，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, w<sub>i</sub>]</code>&nbsp;表示节点 <code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边权为&nbsp;<code>w<sub>i</sub></code>&nbsp;的边。</p>

<p>对于节点 <code>0</code>&nbsp;为出发点，节点 <code>n - 1</code>&nbsp;为结束点的所有最短路，你需要返回一个长度为 <code>m</code>&nbsp;的 <strong>boolean</strong>&nbsp;数组&nbsp;<code>answer</code>&nbsp;，如果&nbsp;<code>edges[i]</code>&nbsp;<strong>至少</strong>&nbsp;在其中一条最短路上，那么&nbsp;<code>answer[i]</code>&nbsp;为&nbsp;<code>true</code>&nbsp;，否则&nbsp;<code>answer[i]</code>&nbsp;为&nbsp;<code>false</code>&nbsp;。</p>

<p>请你返回数组&nbsp;<code>answer</code>&nbsp;。</p>

<p><b>注意</b>，图可能不连通。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3123.Find%20Edges%20in%20Shortest%20Paths/images/graph35drawio-1.png" style="height: 129px; width: 250px;" /></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]</span></p>

<p><span class="example-io"><b>输出：</b>[true,true,true,false,true,true,true,false]</span></p>

<p><strong>解释：</strong></p>

<p>以下为节点 0 出发到达节点 5 的 <strong>所有</strong>&nbsp;最短路：</p>

<ul>
	<li>路径&nbsp;<code>0 -&gt; 1 -&gt; 5</code>&nbsp;：边权和为&nbsp;<code>4 + 1 = 5</code>&nbsp;。</li>
	<li>路径&nbsp;<code>0 -&gt; 2 -&gt; 3 -&gt; 5</code>&nbsp;：边权和为&nbsp;<code>1 + 1 + 3 = 5</code>&nbsp;。</li>
	<li>路径&nbsp;<code>0 -&gt; 2 -&gt; 3 -&gt; 1 -&gt; 5</code>&nbsp;：边权和为&nbsp;<code>1 + 1 + 2 + 1 = 5</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3123.Find%20Edges%20in%20Shortest%20Paths/images/graphhhh.png" style="width: 185px; height: 136px;" /></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]</span></p>

<p><span class="example-io"><b>输出：</b>[true,false,false,true]</span></p>

<p><strong>解释：</strong></p>

<p>只有一条从节点 0 出发到达节点 3 的最短路&nbsp;<code>0 -&gt; 2 -&gt; 3</code>&nbsp;，边权和为&nbsp;<code>1 + 2 = 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= m &lt;= min(5 * 10<sup>4</sup>, n * (n - 1) / 2)</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li>图中没有重边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：堆优化的 Dijkstra

我们先创建一个邻接表 $g$，用于存储图的边。然后创建一个数组 $dist$，用于存储从节点 $0$ 到其他节点的最短距离。初始化 $dist[0] = 0$，其余节点的距离初始化为无穷大。

然后，我们使用 Dijkstra 算法计算从节点 $0$ 到其他节点的最短距离。具体步骤如下：

1. 创建一个优先队列 $q$，用于存储节点的距离和节点编号，初始时将节点 $0$ 加入队列，距离为 $0$。
2. 从队列中取出一个节点 $a$，如果 $a$ 的距离 $da$ 大于 $dist[a]$，说明 $a$ 已经被更新过了，直接跳过。
3. 遍历节点 $a$ 的所有邻居节点 $b$，如果 $dist[b] > dist[a] + w$，则更新 $dist[b] = dist[a] + w$，并将节点 $b$ 加入队列。
4. 重复步骤 2 和步骤 3，直到队列为空。

接着，我们创建一个长度为 $m$ 的答案数组 $ans$，初始时所有元素都为 $false$。如果 $dist[n - 1]$ 为无穷大，说明节点 $0$ 无法到达节点 $n - 1$，直接返回 $ans$。否则，我们从节点 $n - 1$ 开始，遍历所有的边，如果边 $(a, b, i)$ 满足 $dist[a] = dist[b] + w$，则将 $ans[i]$ 置为 $true$，并将节点 $b$ 加入队列。

最后，返回答案即可。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别为节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        g = defaultdict(list)
        for i, (a, b, w) in enumerate(edges):
            g[a].append((b, w, i))
            g[b].append((a, w, i))
        dist = [inf] * n
        dist[0] = 0
        q = [(0, 0)]
        while q:
            da, a = heappop(q)
            if da > dist[a]:
                continue
            for b, w, _ in g[a]:
                if dist[b] > dist[a] + w:
                    dist[b] = dist[a] + w
                    heappush(q, (dist[b], b))
        m = len(edges)
        ans = [False] * m
        if dist[n - 1] == inf:
            return ans
        q = deque([n - 1])
        while q:
            a = q.popleft()
            for b, w, i in g[a]:
                if dist[a] == dist[b] + w:
                    ans[i] = True
                    q.append(b)
        return ans
```

#### Java

```java
class Solution {
    public boolean[] findAnswer(int n, int[][] edges) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int m = edges.length;
        for (int i = 0; i < m; ++i) {
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            g[a].add(new int[] {b, w, i});
            g[b].add(new int[] {a, w, i});
        }
        int[] dist = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(dist, inf);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int da = p[0], a = p[1];
            if (da > dist[a]) {
                continue;
            }
            for (var e : g[a]) {
                int b = e[0], w = e[1];
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    pq.offer(new int[] {dist[b], b});
                }
            }
        }
        boolean[] ans = new boolean[m];
        if (dist[n - 1] == inf) {
            return ans;
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(n - 1);
        while (!q.isEmpty()) {
            int a = q.poll();
            for (var e : g[a]) {
                int b = e[0], w = e[1], i = e[2];
                if (dist[a] == dist[b] + w) {
                    ans[i] = true;
                    q.offer(b);
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
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> g(n);
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            auto e = edges[i];
            int a = e[0], b = e[1], w = e[2];
            g[a].push_back({b, w, i});
            g[b].push_back({a, w, i});
        }
        const int inf = 1 << 30;
        vector<int> dist(n, inf);
        dist[0] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [da, a] = pq.top();
            pq.pop();
            if (da > dist[a]) {
                continue;
            }

            for (auto [b, w, _] : g[a]) {
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    pq.push({dist[b], b});
                }
            }
        }
        vector<bool> ans(m);
        if (dist[n - 1] == inf) {
            return ans;
        }
        queue<int> q{{n - 1}};
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (auto [b, w, i] : g[a]) {
                if (dist[a] == dist[b] + w) {
                    ans[i] = true;
                    q.push(b);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findAnswer(n int, edges [][]int) []bool {
	g := make([][][3]int, n)
	for i, e := range edges {
		a, b, w := e[0], e[1], e[2]
		g[a] = append(g[a], [3]int{b, w, i})
		g[b] = append(g[b], [3]int{a, w, i})
	}
	dist := make([]int, n)
	const inf int = 1 << 30
	for i := range dist {
		dist[i] = inf
	}
	dist[0] = 0
	pq := hp{{0, 0}}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		da, a := p.dis, p.u
		if da > dist[a] {
			continue
		}
		for _, e := range g[a] {
			b, w := e[0], e[1]
			if dist[b] > dist[a]+w {
				dist[b] = dist[a] + w
				heap.Push(&pq, pair{dist[b], b})
			}
		}
	}
	ans := make([]bool, len(edges))
	if dist[n-1] == inf {
		return ans
	}
	q := []int{n - 1}
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		for _, e := range g[a] {
			b, w, i := e[0], e[1], e[2]
			if dist[a] == dist[b]+w {
				ans[i] = true
				q = append(q, b)
			}
		}
	}
	return ans
}

type pair struct{ dis, u int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3124. 查找最长的电话 🔒](https://leetcode.cn/problems/find-longest-calls){#3124}

{{< tabs "3124" >}}

{{% tab "sql" %}}
```sql
WITH
    T AS (
        SELECT
            first_name,
            type,
            DATE_FORMAT(SEC_TO_TIME(duration), "%H:%i:%s") AS duration_formatted,
            RANK() OVER (
                PARTITION BY type
                ORDER BY duration DESC
            ) AS rk
        FROM
            Calls AS c1
            JOIN Contacts AS c2 ON c1.contact_id = c2.id
    )
SELECT
    first_name,
    type,
    duration_formatted
FROM T
WHERE rk <= 3
ORDER BY 2, 3 DESC, 1 DESC;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_longest_calls(contacts: pd.DataFrame, calls: pd.DataFrame) -> pd.DataFrame:
    merged_data = calls.merge(contacts, left_on="contact_id", right_on="id")
    merged_data["duration_formatted"] = (
        merged_data["duration"] // 3600 * 10000
        + merged_data["duration"] % 3600 // 60 * 100
        + merged_data["duration"] % 60
    ).apply(lambda x: "{:02}:{:02}:{:02}".format(x // 10000, x // 100 % 100, x % 100))

    merged_data["rk"] = merged_data.groupby("type")["duration"].rank(
        method="dense", ascending=False
    )

    result = merged_data[merged_data["rk"] <= 3][
        ["first_name", "type", "duration_formatted"]
    ]
    result = result.sort_values(
        by=["type", "duration_formatted", "first_name"], ascending=[True, False, False]
    )
    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Contacts</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| first_name  | varchar |
| last_name   | varchar |
+-------------+---------+
id 是这张表的主键（有不同值的列）。
id 是 Calls 表的外键（引用列）。
这张表的每一行都包含 id，first_name 和 last_name。
</pre>

<p>表：<code>Calls</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| contact_id  | int  |
| type        | enum |
| duration    | int  |
+-------------+------+
(contact_id, type, duration) 是这张表的主键（有不同值的列）。
type 字段是 ('incoming', 'outgoing') 的 ENUM (category)。
这张表的每一行包含有 calls, 包括 contact_id，type 和以秒为单位的 duration 的信息。
</pre>

<p>编写一个解决方案来找到&nbsp;<strong>三个最长的呼入</strong>&nbsp;和&nbsp;<strong>呼出</strong>&nbsp;电话。</p>

<p>返回结果表，以&nbsp;<code>type</code>，<code>duration</code>&nbsp;和&nbsp;<code>first_name</code>&nbsp;<em><strong>降序排序</strong>&nbsp;，<code>duration</code>&nbsp;的格式必须为&nbsp;<strong>HH:MM:SS</strong>。</em></p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><b>输入：</b></p>

<p>Contacts 表：</p>

<pre class="example-io">
+----+------------+-----------+
| id | first_name | last_name |
+----+------------+-----------+
| 1  | John       | Doe       |
| 2  | Jane       | Smith     |
| 3  | Alice      | Johnson   |
| 4  | Michael    | Brown     |
| 5  | Emily      | Davis     |
+----+------------+-----------+        
</pre>

<p>Calls 表：</p>

<pre class="example-io">
+------------+----------+----------+
| contact_id | type     | duration |
+------------+----------+----------+
| 1          | incoming | 120      |
| 1          | outgoing | 180      |
| 2          | incoming | 300      |
| 2          | outgoing | 240      |
| 3          | incoming | 150      |
| 3          | outgoing | 360      |
| 4          | incoming | 420      |
| 4          | outgoing | 200      |
| 5          | incoming | 180      |
| 5          | outgoing | 280      |
+------------+----------+----------+
        </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-----------+----------+-------------------+
| first_name| type     | duration_formatted|
+-----------+----------+-------------------+
| Michael   | incoming | 00:07:00          |
| Jane      | incoming | 00:05:00          |
| Emily     | incoming | 00:03:00          |
| Alice     | outgoing | 00:06:00          |
| Emily     | outgoing | 00:04:40          |
| Jane      | outgoing | 00:04:00          |
+-----------+----------+-------------------+
        </pre>

<p><strong>解释:</strong></p>

<ul>
	<li>Michael 有一通长达 7 分钟的呼入电话。</li>
	<li>Jane 有一通长达 5&nbsp;分钟的呼入电话。</li>
	<li>Emily 有一通长达 3&nbsp;分钟的呼入电话。</li>
	<li>Alice 有一通长达 6&nbsp;分钟的呼出电话。</li>
	<li>Emily 有一通长达 4&nbsp;分 40 秒的呼出电话。</li>
	<li>Jane 有一通长达 4&nbsp;分钟的呼出电话。</li>
</ul>

<p><b>注意：</b>输出表以&nbsp;type，duration&nbsp;和 first_name 降序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 窗口函数

我们可以使用等值连接将两张表连接起来，然后使用窗口函数 `RANK()` 计算每个类型的电话的排名。最后，我们只需要筛选出排名前三的电话即可。

<!-- tabs:start -->

#### MySQL

```sql
WITH
    T AS (
        SELECT
            first_name,
            type,
            DATE_FORMAT(SEC_TO_TIME(duration), "%H:%i:%s") AS duration_formatted,
            RANK() OVER (
                PARTITION BY type
                ORDER BY duration DESC
            ) AS rk
        FROM
            Calls AS c1
            JOIN Contacts AS c2 ON c1.contact_id = c2.id
    )
SELECT
    first_name,
    type,
    duration_formatted
FROM T
WHERE rk <= 3
ORDER BY 2, 3 DESC, 1 DESC;
```

#### Python3

```python
import pandas as pd


def find_longest_calls(contacts: pd.DataFrame, calls: pd.DataFrame) -> pd.DataFrame:
    merged_data = calls.merge(contacts, left_on="contact_id", right_on="id")
    merged_data["duration_formatted"] = (
        merged_data["duration"] // 3600 * 10000
        + merged_data["duration"] % 3600 // 60 * 100
        + merged_data["duration"] % 60
    ).apply(lambda x: "{:02}:{:02}:{:02}".format(x // 10000, x // 100 % 100, x % 100))

    merged_data["rk"] = merged_data.groupby("type")["duration"].rank(
        method="dense", ascending=False
    )

    result = merged_data[merged_data["rk"] <= 3][
        ["first_name", "type", "duration_formatted"]
    ]
    result = result.sort_values(
        by=["type", "duration_formatted", "first_name"], ascending=[True, False, False]
    )
    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3125. 使得按位与结果为 0 的最大数字 🔒](https://leetcode.cn/problems/maximum-number-that-makes-result-of-bitwise-and-zero){#3125}

{{< tabs "3125" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumber(self, n: int) -> int:
        return (1 << (n.bit_length() - 1)) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxNumber(long n) {
        return (1L << (63 - Long.numberOfLeadingZeros(n))) - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxNumber(long long n) {
        return (1LL << (63 - __builtin_clzll(n))) - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumber(n int64) int64 {
	return int64(1<<(bits.Len64(uint64(n))-1)) - 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给定一个整数&nbsp;<code>n</code>，返回&nbsp;<strong>最大的</strong>&nbsp;整数&nbsp;<code>x</code> 使得&nbsp;<code>x &lt;= n</code>，并且所有在范围 <code>[x, n]</code>&nbsp;内的数字的按位&nbsp;<code>AND</code>&nbsp;为 0。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 7</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>[6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为&nbsp;6。</p>

<p><code>[5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 4。</p>

<p><code>[4, 5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 4。</p>

<p><code>[3, 4, 5, 6, 7]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 9</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<p><code>[7, 8, 9]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 17</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p><code>[15, 16, 17]</code>&nbsp;的按位&nbsp;<code>AND</code>&nbsp;为 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以找到 $n$ 的二进制表示中最高位的 $1$，那么最大的 $x$ 一定小于 $n$ 且该位为 $0$，其他低位均为 $1$，即 $x = 2^{\textit{最高位的位数} - 1} - 1$。这是因为 $x \textit{ and } (x + 1) = 0$ 一定成立。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumber(self, n: int) -> int:
        return (1 << (n.bit_length() - 1)) - 1
```

#### Java

```java
class Solution {
    public long maxNumber(long n) {
        return (1L << (63 - Long.numberOfLeadingZeros(n))) - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxNumber(long long n) {
        return (1LL << (63 - __builtin_clzll(n))) - 1;
    }
};
```

#### Go

```go
func maxNumber(n int64) int64 {
	return int64(1<<(bits.Len64(uint64(n))-1)) - 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3126. 服务器利用时间 🔒](https://leetcode.cn/problems/server-utilization-time){#3126}

{{< tabs "3126" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            session_status,
            status_time,
            LEAD(status_time) OVER (
                PARTITION BY server_id
                ORDER BY status_time
            ) AS next_status_time
        FROM Servers
    )
SELECT FLOOR(SUM(TIMESTAMPDIFF(SECOND, status_time, next_status_time)) / 86400) AS total_uptime_days
FROM T
WHERE session_status = 'start';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Servers</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| server_id      | int      |
| status_time    | datetime |
| session_status | enum     |
+----------------+----------+
(server_id, status_time, session_status) 是这张表的主键（有不同值的列的组合）。
session_status 是 ('start', 'stop') 的 ENUM (category)。
这张表的每一行包含 server_id, status_time 和 session_status。
</pre>

<p>编写一个解决方案来查找服务器 <strong>运行</strong> 的 <strong>总时间</strong>。输出应向下舍入为最接近的 <strong>整天数</strong>。</p>

<p>以 <strong>任意</strong> 顺序返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Servers 表：</p>

<pre class="example-io">
+-----------+---------------------+----------------+
| server_id | status_time         | session_status |
+-----------+---------------------+----------------+
| 3         | 2023-11-04 16:29:47 | start          |
| 3         | 2023-11-05 01:49:47 | stop           |
| 3         | 2023-11-25 01:37:08 | start          |
| 3         | 2023-11-25 03:50:08 | stop           |
| 1         | 2023-11-13 03:05:31 | start          |
| 1         | 2023-11-13 11:10:31 | stop           |
| 4         | 2023-11-29 15:11:17 | start          |
| 4         | 2023-11-29 15:42:17 | stop           |
| 4         | 2023-11-20 00:31:44 | start          |
| 4         | 2023-11-20 07:03:44 | stop           |
| 1         | 2023-11-20 00:27:11 | start          |
| 1         | 2023-11-20 01:41:11 | stop           |
| 3         | 2023-11-04 23:16:48 | start          |
| 3         | 2023-11-05 01:15:48 | stop           |
| 4         | 2023-11-30 15:09:18 | start          |
| 4         | 2023-11-30 20:48:18 | stop           |
| 4         | 2023-11-25 21:09:06 | start          |
| 4         | 2023-11-26 04:58:06 | stop           |
| 5         | 2023-11-16 19:42:22 | start          |
| 5         | 2023-11-16 21:08:22 | stop           |
+-----------+---------------------+----------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------------+
| total_uptime_days |
+-------------------+
| 1                 |
+-------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于 server ID 3：
	<ul>
		<li>从 2023-11-04 16:29:47 到 2023-11-05 01:49:47: ~9.3 小时</li>
		<li>从 2023-11-25 01:37:08 到 2023-11-25 03:50:08: ~2.2 小时</li>
		<li>从 2023-11-04 23:16:48 到 2023-11-05 01:15:48: ~1.98 小时</li>
	</ul>
	server 3 共计：~13.48 小时</li>
	<li>对于 server ID 1：
	<ul>
		<li>从 2023-11-13 03:05:31 到 2023-11-13 11:10:31: ~8 小时</li>
		<li>从 2023-11-20 00:27:11 到 2023-11-20 01:41:11: ~1.23 小时</li>
	</ul>
	server 1 共计：~9.23 小时</li>
	<li>对于 server ID 4:
	<ul>
		<li>从 2023-11-29 15:11:17 到 2023-11-29 15:42:17: ~0.52 小时</li>
		<li>从 2023-11-20 00:31:44 到 2023-11-20 07:03:44: ~6.53 小时</li>
		<li>从 2023-11-30 15:09:18 到 2023-11-30 20:48:18: ~5.65 小时</li>
		<li>从 2023-11-25 21:09:06 到 2023-11-26 04:58:06: ~7.82 小时</li>
	</ul>
	server 4 共计：~20.52 小时</li>
	<li>对于 server ID 5:
	<ul>
		<li>从 2023-11-16 19:42:22 到 2023-11-16 21:08:22: ~1.43 小时</li>
	</ul>
	server 5 共计：~1.43 小时</li>
</ul>
所有服务器的累积运行时间总计约为 44.46 小时，相当于一整天加上一些额外的小时。然而，由于我们只考虑整天，因此最终输出四舍五入为 1 整天。</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用窗口函数

我们可以使用窗口函数 `LEAD` 来获取每个服务器的下一个状态的时间，那么两个状态之间的时间差就是服务器的一次运行时间。最后我们将所有服务器的运行时间相加，然后除以一天的秒数，就得到了服务器的总运行天数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            session_status,
            status_time,
            LEAD(status_time) OVER (
                PARTITION BY server_id
                ORDER BY status_time
            ) AS next_status_time
        FROM Servers
    )
SELECT FLOOR(SUM(TIMESTAMPDIFF(SECOND, status_time, next_status_time)) / 86400) AS total_uptime_days
FROM T
WHERE session_status = 'start';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3127. 构造相同颜色的正方形](https://leetcode.cn/problems/make-a-square-with-the-same-color){#3127}

{{< tabs "3127" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(0, 2):
            for j in range(0, 2):
                cnt1 = cnt2 = 0
                for a, b in pairwise((0, 0, 1, 1, 0)):
                    x, y = i + a, j + b
                    cnt1 += grid[x][y] == "W"
                    cnt2 += grid[x][y] == "B"
                if cnt1 != cnt2:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canMakeSquare(char[][] grid) {
        final int[] dirs = {0, 0, 1, 1, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    cnt1 += grid[x][y] == 'W' ? 1 : 0;
                    cnt2 += grid[x][y] == 'B' ? 1 : 0;
                }
                if (cnt1 != cnt2) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int dirs[5] = {0, 0, 1, 1, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    cnt1 += grid[x][y] == 'W';
                    cnt2 += grid[x][y] == 'B';
                }
                if (cnt1 != cnt2) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMakeSquare(grid [][]byte) bool {
	dirs := [5]int{0, 0, 1, 1, 0}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			cnt1, cnt2 := 0, 0
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if grid[x][y] == 'W' {
					cnt1++
				} else {
					cnt2++
				}
			}
			if cnt1 != cnt2 {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canMakeSquare(grid: string[][]): boolean {
    const dirs: number[] = [0, 0, 1, 1, 0];
    for (let i = 0; i < 2; ++i) {
        for (let j = 0; j < 2; ++j) {
            let [cnt1, cnt2] = [0, 0];
            for (let k = 0; k < 4; ++k) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (grid[x][y] === 'W') {
                    ++cnt1;
                } else {
                    ++cnt2;
                }
            }
            if (cnt1 !== cnt2) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维 <code>3 x 3</code>&nbsp;的矩阵&nbsp;<code>grid</code>&nbsp;，每个格子都是一个字符，要么是&nbsp;<code>'B'</code>&nbsp;，要么是&nbsp;<code>'W'</code>&nbsp;。字符&nbsp;<code>'W'</code>&nbsp;表示白色，字符&nbsp;<code>'B'</code>&nbsp;表示黑色。</p>

<p>你的任务是改变 <strong>至多一个</strong>&nbsp;格子的颜色，使得矩阵中存在一个 <code>2 x 2</code>&nbsp;颜色完全相同的正方形。<!-- notionvc: adf957e1-fa0f-40e5-9a2e-933b95e276a7 --></p>

<p>如果可以得到一个相同颜色的 <code>2 x 2</code>&nbsp;正方形，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>
<style type="text/css">.grid-container {
  display: grid;
  grid-template-columns: 30px 30px 30px;
  padding: 10px;
}
.grid-item {
  background-color: black;
  border: 1px solid gray;
  height: 30px;
  font-size: 30px;
  text-align: center;
}
.grid-item-white {
  background-color: white;
}
</style>
<style class="darkreader darkreader--sync" media="screen" type="text/css">
</style>
<p><strong class="example">示例 1：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["B","W","W"],["B","W","B"]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p>修改&nbsp;<code>grid[0][2]</code> 的颜色，可以满足要求。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["W","B","W"],["B","W","B"]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p>只改变一个格子颜色无法满足要求。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="grid-container">
<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>

<div class="grid-item grid-item-white">&nbsp;</div>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [["B","W","B"],["B","W","W"],["B","W","W"]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><code>grid</code>&nbsp;已经包含一个&nbsp;<code>2 x 2</code>&nbsp;颜色相同的正方形了。<!-- notionvc: 9a8b2d3d-1e73-457a-abe0-c16af51ad5c2 --></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length == 3</code></li>
	<li><code>grid[i].length == 3</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;，要么是&nbsp;<code>'B'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每个 $2 \times 2$ 的正方形，统计黑色和白色的个数，如果两者个数不相等，那么就可以构造一个相同颜色的正方形，返回 `true`。

否则，遍历结束后返回 `false`。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(0, 2):
            for j in range(0, 2):
                cnt1 = cnt2 = 0
                for a, b in pairwise((0, 0, 1, 1, 0)):
                    x, y = i + a, j + b
                    cnt1 += grid[x][y] == "W"
                    cnt2 += grid[x][y] == "B"
                if cnt1 != cnt2:
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean canMakeSquare(char[][] grid) {
        final int[] dirs = {0, 0, 1, 1, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    cnt1 += grid[x][y] == 'W' ? 1 : 0;
                    cnt2 += grid[x][y] == 'B' ? 1 : 0;
                }
                if (cnt1 != cnt2) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int dirs[5] = {0, 0, 1, 1, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    cnt1 += grid[x][y] == 'W';
                    cnt2 += grid[x][y] == 'B';
                }
                if (cnt1 != cnt2) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func canMakeSquare(grid [][]byte) bool {
	dirs := [5]int{0, 0, 1, 1, 0}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			cnt1, cnt2 := 0, 0
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if grid[x][y] == 'W' {
					cnt1++
				} else {
					cnt2++
				}
			}
			if cnt1 != cnt2 {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function canMakeSquare(grid: string[][]): boolean {
    const dirs: number[] = [0, 0, 1, 1, 0];
    for (let i = 0; i < 2; ++i) {
        for (let j = 0; j < 2; ++j) {
            let [cnt1, cnt2] = [0, 0];
            for (let k = 0; k < 4; ++k) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (grid[x][y] === 'W') {
                    ++cnt1;
                } else {
                    ++cnt2;
                }
            }
            if (cnt1 !== cnt2) {
                return true;
            }
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3128. 直角三角形](https://leetcode.cn/problems/right-triangles){#3128}

{{< tabs "3128" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        rows = [0] * len(grid)
        cols = [0] * len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                rows[i] += x
                cols[j] += x
        ans = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x:
                    ans += (rows[i] - 1) * (cols[j] - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += (rows[i] - 1) * (cols[j] - 1);
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
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += (rows[i] - 1) * (cols[j] - 1);
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
func numberOfRightTriangles(grid [][]int) (ans int64) {
	m, n := len(grid), len(grid[0])
	rows := make([]int, m)
	cols := make([]int, n)
	for i, row := range grid {
		for j, x := range row {
			rows[i] += x
			cols[j] += x
		}
	}
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				ans += int64((rows[i] - 1) * (cols[j] - 1))
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfRightTriangles(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                ans += (rows[i] - 1) * (cols[j] - 1);
            }
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

<p>给你一个二维 boolean 矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>如果&nbsp;<code>grid</code> 的 3 个元素的集合中，一个元素与另一个元素在 <strong>同一行</strong>，并且与第三个元素在 <strong>同一列</strong>，则该集合是一个 <strong>直角三角形</strong>。3 个元素 <strong>不必</strong> 彼此相邻。</p>

<p>请你返回使用 <code>grid</code>&nbsp;中的 3 个元素可以构建的 <strong>直角三角形</strong> 数目，且满足 3 个元素值 <strong>都</strong>&nbsp;为 1 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div style="display:flex; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1,0],[0,1,1],[0,1,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<p>有 2 个值为 1 的直角三角形。注意蓝色的那个 <strong>没有&nbsp;</strong>组成直角三角形，因为 3 个元素在同一列。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div style="display:flex; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>没有值为 1 的直角三角形。注意蓝色的那个&nbsp;<strong>没有</strong> 组成直角三角形。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div style="display:flex; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,1],[1,0,0],[1,0,0]]</span></p>

<p><strong>输出：</strong>2</p>

<p><strong>解释：</strong></p>

<p>有两个值为 1 的直角三角形。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 1000</code></li>
	<li><code>1 &lt;= grid[i].length &lt;= 1000</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以先统计每一行和每一列的 $1$ 的个数，记录在数组 $rows$ 和 $cols$ 中。

然后我们枚举每一个 $1$，假设当前 $1$ 在第 $i$ 行第 $j$ 列，那么以当前 $1$ 为直角三角形的直角点，另外两个直角点分别在第 $i$ 行和第 $j$ 列，那么直角三角形的个数就是 $(rows[i] - 1) \times (cols[j] - 1)$，累加到答案中即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        rows = [0] * len(grid)
        cols = [0] * len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                rows[i] += x
                cols[j] += x
        ans = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x:
                    ans += (rows[i] - 1) * (cols[j] - 1)
        return ans
```

#### Java

```java
class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += (rows[i] - 1) * (cols[j] - 1);
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
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += (rows[i] - 1) * (cols[j] - 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfRightTriangles(grid [][]int) (ans int64) {
	m, n := len(grid), len(grid[0])
	rows := make([]int, m)
	cols := make([]int, n)
	for i, row := range grid {
		for j, x := range row {
			rows[i] += x
			cols[j] += x
		}
	}
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				ans += int64((rows[i] - 1) * (cols[j] - 1))
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfRightTriangles(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                ans += (rows[i] - 1) * (cols[j] - 1);
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

# [3129. 找出所有稳定的二进制数组 I](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i){#3129}

{{< tabs "3129" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7
        f = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        for i in range(1, min(limit, zero) + 1):
            f[i][0][0] = 1
        for j in range(1, min(limit, one) + 1):
            f[0][j][1] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                x = 0 if i - limit - 1 < 0 else f[i - limit - 1][j][1]
                y = 0 if j - limit - 1 < 0 else f[i][j - limit - 1][0]
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x) % mod
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y) % mod
        return sum(f[zero][one]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        final int mod = (int) 1e9 + 7;
        long[][][] f = new long[zero + 1][one + 1][2];
        for (int i = 1; i <= Math.min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= Math.min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                long x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                long y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (int) ((f[zero][one][0] + f[zero][one][1]) % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll f[zero + 1][one + 1][2];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                ll x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                ll y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
	}
	for i := 1; i <= min(zero, limit); i++ {
		f[i][0][0] = 1
	}
	for j := 1; j <= min(one, limit); j++ {
		f[0][j][1] = 1
	}
	for i := 1; i <= zero; i++ {
		for j := 1; j <= one; j++ {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) % mod
			if i-limit-1 >= 0 {
				f[i][j][0] = (f[i][j][0] - f[i-limit-1][j][1] + mod) % mod
			}
			f[i][j][1] = (f[i][j-1][0] + f[i][j-1][1]) % mod
			if j-limit-1 >= 0 {
				f[i][j][1] = (f[i][j][1] - f[i][j-limit-1][0] + mod) % mod
			}
		}
	}
	return (f[zero][one][0] + f[zero][one][1]) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1e9 + 7;
    const f: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) {
        f[i][0][0] = 1;
    }
    for (let j = 1; j <= Math.min(limit, one); j++) {
        f[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            const x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
            const y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
            f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
            f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
        }
    }

    return (f[zero][one][0] + f[zero][one][1]) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 3 个正整数&nbsp;<code>zero</code>&nbsp;，<code>one</code>&nbsp;和&nbsp;<code>limit</code>&nbsp;。</p>

<p>一个 <span data-keyword="binary-array">二进制数组</span> <code>arr</code> 如果满足以下条件，那么我们称它是 <strong>稳定的</strong> ：</p>

<ul>
	<li>0 在&nbsp;<code>arr</code>&nbsp;中出现次数 <strong>恰好</strong>&nbsp;为<strong>&nbsp;</strong><code>zero</code>&nbsp;。</li>
	<li>1 在&nbsp;<code>arr</code>&nbsp;中出现次数 <strong>恰好</strong>&nbsp;为&nbsp;<code>one</code>&nbsp;。</li>
	<li><code>arr</code> 中每个长度超过 <code>limit</code>&nbsp;的 <span data-keyword="subarray-nonempty">子数组</span> 都 <strong>同时</strong> 包含 0 和 1 。</li>
</ul>

<p>请你返回 <strong>稳定</strong>&nbsp;二进制数组的 <em>总</em> 数目。</p>

<p>由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>zero = 1, one = 1, limit = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>两个稳定的二进制数组为&nbsp;<code>[1,0]</code> 和&nbsp;<code>[0,1]</code>&nbsp;，两个数组都有一个 0 和一个 1 ，且没有子数组长度大于 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">zero = 1, one = 2, limit = 1</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一稳定的二进制数组是&nbsp;<code>[1,0,1]</code>&nbsp;。</p>

<p>二进制数组&nbsp;<code>[1,1,0]</code> 和&nbsp;<code>[0,1,1]</code>&nbsp;都有长度为 2 且元素全都相同的子数组，所以它们不稳定。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>zero = 3, one = 3, limit = 2</span></p>

<p><span class="example-io"><b>输出：</b>14</span></p>

<p><strong>解释：</strong></p>

<p>所有稳定的二进制数组包括&nbsp;<code>[0,0,1,0,1,1]</code>&nbsp;，<code>[0,0,1,1,0,1]</code>&nbsp;，<code>[0,1,0,0,1,1]</code>&nbsp;，<code>[0,1,0,1,0,1]</code>&nbsp;，<code>[0,1,0,1,1,0]</code>&nbsp;，<code>[0,1,1,0,0,1]</code>&nbsp;，<code>[0,1,1,0,1,0]</code>&nbsp;，<code>[1,0,0,1,0,1]</code>&nbsp;，<code>[1,0,0,1,1,0]</code>&nbsp;，<code>[1,0,1,0,0,1]</code>&nbsp;，<code>[1,0,1,0,1,0]</code>&nbsp;，<code>[1,0,1,1,0,0]</code>&nbsp;，<code>[1,1,0,0,1,0]</code>&nbsp;和&nbsp;<code>[1,1,0,1,0,0]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= zero, one, limit &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$ 表示还剩下 $i$ 个 $0$ 和 $j$ 个 $1$ 且接下来待填的数字是 $k$ 的情况下，满足题目条件的稳定二进制数组的个数。那么答案就是 $dfs(zero, one, 0) + dfs(zero, one, 1)$。

函数 $dfs(i, j, k)$ 的计算过程如下：

-   如果 $i \lt 0$ 或 $j \lt 0$，返回 $0$。
-   如果 $i = 0$，那么当 $k = 1$ 且 $j \leq \textit{limit}$ 时返回 $1$，否则返回 $0$。
-   如果 $j = 0$，那么当 $k = 0$ 且 $i \leq \textit{limit}$ 时返回 $1$，否则返回 $0$。
-   如果 $k = 0$，我们考虑前一个数字是 $0$ 的情况 $dfs(i - 1, j, 0)$ 和前一个数字是 $1$ 的情况 $dfs(i - 1, j, 1)$，如果前一个数是 $0$，那么有可能使得子数组中有超过 $\textit{limit}$ 个 $0$，即不允许出现倒数第 $\textit{limit} + 1$ 个数是 $1$ 的情况，所以我们要减去这种情况，即 $dfs(i - \textit{limit} - 1, j, 1)$。
-   如果 $k = 1$，我们考虑前一个数字是 $0$ 的情况 $dfs(i, j - 1, 0)$ 和前一个数字是 $1$ 的情况 $dfs(i, j - 1, 1)$，如果前一个数是 $1$，那么有可能使得子数组中有超过 $\textit{limit}$ 个 $1$，即不允许出现倒数第 $\textit{limit} + 1$ 个数是 $0$ 的情况，所以我们要减去这种情况，即 $dfs(i, j - \textit{limit} - 1, 0)$。

为了避免重复计算，我们使用记忆化搜索的方法。

时间复杂度 $O(zero \times one)$，空间复杂度 $O(zero \times one)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i == 0:
                return int(k == 1 and j <= limit)
            if j == 0:
                return int(k == 0 and i <= limit)
            if k == 0:
                return (
                    dfs(i - 1, j, 0)
                    + dfs(i - 1, j, 1)
                    - (0 if i - limit - 1 < 0 else dfs(i - limit - 1, j, 1))
                )
            return (
                dfs(i, j - 1, 0)
                + dfs(i, j - 1, 1)
                - (0 if j - limit - 1 < 0 else dfs(i, j - limit - 1, 0))
            )

        mod = 10**9 + 7
        ans = (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private Long[][][] f;
    private int limit;

    public int numberOfStableArrays(int zero, int one, int limit) {
        f = new Long[zero + 1][one + 1][2];
        this.limit = limit;
        return (int) ((dfs(zero, one, 0) + dfs(zero, one, 1)) % mod);
    }

    private long dfs(int i, int j, int k) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i == 0) {
            return k == 1 && j <= limit ? 1 : 0;
        }
        if (j == 0) {
            return k == 0 && i <= limit ? 1 : 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k == 0) {
            f[i][j][k]
                = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
        } else {
            f[i][j][k]
                = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
        }
        return f[i][j][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        vector<vector<array<ll, 2>>> f = vector<vector<array<ll, 2>>>(zero + 1, vector<array<ll, 2>>(one + 1, {-1, -1}));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> ll {
            if (i < 0 || j < 0) {
                return 0;
            }
            if (i == 0) {
                return k == 1 && j <= limit;
            }
            if (j == 0) {
                return k == 0 && i <= limit;
            }
            ll& res = f[i][j][k];
            if (res != -1) {
                return res;
            }
            if (k == 0) {
                res = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
            } else {
                res = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
            }
            return res;
        };
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod;
    }
};
```

#### Go

```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
		for j := range f[i] {
			f[i][j] = [2]int{-1, -1}
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i < 0 || j < 0 {
			return 0
		}
		if i == 0 {
			if k == 1 && j <= limit {
				return 1
			}
			return 0
		}
		if j == 0 {
			if k == 0 && i <= limit {
				return 1
			}
			return 0
		}
		res := &f[i][j][k]
		if *res != -1 {
			return *res
		}
		if k == 0 {
			*res = (dfs(i-1, j, 0) + dfs(i-1, j, 1) - dfs(i-limit-1, j, 1) + mod) % mod
		} else {
			*res = (dfs(i, j-1, 0) + dfs(i, j-1, 1) - dfs(i, j-limit-1, 0) + mod) % mod
		}
		return *res
	}
	return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod
}
```

#### TypeScript

```ts
function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1e9 + 7;
    const f: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [-1, -1]),
    );

    const dfs = (i: number, j: number, k: number): number => {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i === 0) {
            return k === 1 && j <= limit ? 1 : 0;
        }
        if (j === 0) {
            return k === 0 && i <= limit ? 1 : 0;
        }
        let res = f[i][j][k];
        if (res !== -1) {
            return res;
        }
        if (k === 0) {
            res = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1) - dfs(i - limit - 1, j, 1) + mod) % mod;
        } else {
            res = (dfs(i, j - 1, 0) + dfs(i, j - 1, 1) - dfs(i, j - limit - 1, 0) + mod) % mod;
        }
        return (f[i][j][k] = res);
    };

    return (dfs(zero, one, 0) + dfs(zero, one, 1)) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以将方法一的记忆化搜索转换为动态规划。

我们定义 $f[i][j][k]$ 表示使用 $i$ 个 $0$ 和 $j$ 个 $1$ 且最后一个数字是 $k$ 的稳定二进制数组的个数。那么答案就是 $f[zero][one][0] + f[zero][one][1]$。

初始时，我们有 $f[i][0][0] = 1$，其中 $1 \leq i \leq \min(\textit{limit}, \textit{zero})$；有 $f[0][j][1] = 1$，其中 $1 \leq j \leq \min(\textit{limit}, \textit{one})$。

状态转移方程如下：

-   $f[i][j][0] = f[i - 1][j][0] + f[i - 1][j][1] - f[i - \textit{limit} - 1][j][1]$。
-   $f[i][j][1] = f[i][j - 1][0] + f[i][j - 1][1] - f[i][j - \textit{limit} - 1][0]$。

时间复杂度 $O(zero \times one)$，空间复杂度 $O(zero \times one)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7
        f = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        for i in range(1, min(limit, zero) + 1):
            f[i][0][0] = 1
        for j in range(1, min(limit, one) + 1):
            f[0][j][1] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                x = 0 if i - limit - 1 < 0 else f[i - limit - 1][j][1]
                y = 0 if j - limit - 1 < 0 else f[i][j - limit - 1][0]
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x) % mod
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y) % mod
        return sum(f[zero][one]) % mod
```

#### Java

```java
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        final int mod = (int) 1e9 + 7;
        long[][][] f = new long[zero + 1][one + 1][2];
        for (int i = 1; i <= Math.min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= Math.min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                long x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                long y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (int) ((f[zero][one][0] + f[zero][one][1]) % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll f[zero + 1][one + 1][2];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= min(zero, limit); ++i) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); ++j) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                ll x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
                ll y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
                f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
                f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % mod;
    }
};
```

#### Go

```go
func numberOfStableArrays(zero int, one int, limit int) int {
	const mod int = 1e9 + 7
	f := make([][][2]int, zero+1)
	for i := range f {
		f[i] = make([][2]int, one+1)
	}
	for i := 1; i <= min(zero, limit); i++ {
		f[i][0][0] = 1
	}
	for j := 1; j <= min(one, limit); j++ {
		f[0][j][1] = 1
	}
	for i := 1; i <= zero; i++ {
		for j := 1; j <= one; j++ {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) % mod
			if i-limit-1 >= 0 {
				f[i][j][0] = (f[i][j][0] - f[i-limit-1][j][1] + mod) % mod
			}
			f[i][j][1] = (f[i][j-1][0] + f[i][j-1][1]) % mod
			if j-limit-1 >= 0 {
				f[i][j][1] = (f[i][j][1] - f[i][j-limit-1][0] + mod) % mod
			}
		}
	}
	return (f[zero][one][0] + f[zero][one][1]) % mod
}
```

#### TypeScript

```ts
function numberOfStableArrays(zero: number, one: number, limit: number): number {
    const mod = 1e9 + 7;
    const f: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) {
        f[i][0][0] = 1;
    }
    for (let j = 1; j <= Math.min(limit, one); j++) {
        f[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            const x = i - limit - 1 < 0 ? 0 : f[i - limit - 1][j][1];
            const y = j - limit - 1 < 0 ? 0 : f[i][j - limit - 1][0];
            f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] - x + mod) % mod;
            f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1] - y + mod) % mod;
        }
    }

    return (f[zero][one][0] + f[zero][one][1]) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
