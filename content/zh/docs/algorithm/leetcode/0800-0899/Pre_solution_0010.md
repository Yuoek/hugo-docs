---
title: "0890_查找和替换模式"
date: 2025-10-08T18:36:34+08:00
weight: 10
tags: [二叉搜索树, 二叉树, 位运算, 几何, 动态规划, 哈希表, 字符串, 排序, 数学, 数组, 有序集合, 栈, 树, 深度优先搜索, 矩阵, 记忆化搜索, 设计, 递归]
---

{{< markmap >}}
### [0890_查找和替换模式](#890)
#### [数组](#890)
#### [哈希表](#890)
#### [字符串](#890)
### [0891_子序列宽度之和](#891)
#### [数组](#891)
#### [数学](#891)
#### [排序](#891)
### [0892_三维形体的表面积](#892)
#### [几何](#892)
#### [数组](#892)
#### [数学](#892)
#### [矩阵](#892)
### [0893_特殊等价字符串组](#893)
#### [数组](#893)
#### [哈希表](#893)
#### [字符串](#893)
#### [排序](#893)
### [0894_所有可能的真二叉树](#894)
#### [树](#894)
#### [递归](#894)
#### [记忆化搜索](#894)
#### [动态规划](#894)
#### [二叉树](#894)
### [0895_最大频率栈](#895)
#### [栈](#895)
#### [设计](#895)
#### [哈希表](#895)
#### [有序集合](#895)
### [0896_单调数列](#896)
#### [数组](#896)
### [0897_递增顺序搜索树](#897)
#### [栈](#897)
#### [树](#897)
#### [深度优先搜索](#897)
#### [二叉搜索树](#897)
#### [二叉树](#897)
### [0898_子数组按位或操作](#898)
#### [位运算](#898)
#### [数组](#898)
#### [动态规划](#898)
### [0899_有序队列](#899)
#### [数学](#899)
#### [字符串](#899)
#### [排序](#899)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0890_查找和替换模式
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0891_子序列宽度之和
___
#### 数组
___
#### 数学
___
#### 排序
---
### 0892_三维形体的表面积
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 矩阵
---
### 0893_特殊等价字符串组
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0894_所有可能的真二叉树
___
#### 树
___
#### 递归
___
#### 记忆化搜索
___
#### 动态规划
___
#### 二叉树
---
### 0895_最大频率栈
___
#### 栈
___
#### 设计
___
#### 哈希表
___
#### 有序集合
---
### 0896_单调数列
___
#### 数组
---
### 0897_递增顺序搜索树
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0898_子数组按位或操作
___
#### 位运算
___
#### 数组
___
#### 动态规划
---
### 0899_有序队列
___
#### 数学
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 位运算 |
| 几何 | 动态规划 | 哈希表 |
| 字符串 | 排序 | 数学 |
| 数组 | 有序集合 | 栈 |
| 树 | 深度优先搜索 | 矩阵 |
| 记忆化搜索 | 设计 | 递归 |

# [890. 查找和替换模式](https://leetcode.cn/problems/find-and-replace-pattern){#890}

{{< tabs "890" >}}

{{% tab "python" %}}
```python
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(s, t):
            m1, m2 = [0] * 128, [0] * 128
            for i, (a, b) in enumerate(zip(s, t), 1):
                if m1[ord(a)] != m2[ord(b)]:
                    return False
                m1[ord(a)] = m2[ord(b)] = i
            return True

        return [word for word in words if match(word, pattern)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            if (match(word, pattern)) {
                ans.add(word);
            }
        }
        return ans;
    }

    private boolean match(String s, String t) {
        int[] m1 = new int[128];
        int[] m2 = new int[128];
        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if (m1[c1] != m2[c2]) {
                return false;
            }
            m1[c1] = i + 1;
            m2[c2] = i + 1;
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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto match = [](string& s, string& t) {
            int m1[128] = {0};
            int m2[128] = {0};
            for (int i = 0; i < s.size(); ++i) {
                if (m1[s[i]] != m2[t[i]]) return 0;
                m1[s[i]] = i + 1;
                m2[t[i]] = i + 1;
            }
            return 1;
        };
        for (auto& word : words)
            if (match(word, pattern)) ans.emplace_back(word);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findAndReplacePattern(words []string, pattern string) []string {
	match := func(s, t string) bool {
		m1, m2 := make([]int, 128), make([]int, 128)
		for i := 0; i < len(s); i++ {
			if m1[s[i]] != m2[t[i]] {
				return false
			}
			m1[s[i]] = i + 1
			m2[t[i]] = i + 1
		}
		return true
	}
	var ans []string
	for _, word := range words {
		if match(word, pattern) {
			ans = append(ans, word)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findAndReplacePattern(words: string[], pattern: string): string[] {
    return words.filter(word => {
        const map1 = new Map<string, number>();
        const map2 = new Map<string, number>();
        for (let i = 0; i < word.length; i++) {
            if (map1.get(word[i]) !== map2.get(pattern[i])) {
                return false;
            }
            map1.set(word[i], i);
            map2.set(pattern[i], i);
        }
        return true;
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let pattern = pattern.as_bytes();
        let n = pattern.len();
        words
            .into_iter()
            .filter(|word| {
                let word = word.as_bytes();
                let mut map1 = HashMap::new();
                let mut map2 = HashMap::new();
                for i in 0..n {
                    if map1.get(&word[i]).unwrap_or(&n) != map2.get(&pattern[i]).unwrap_or(&n) {
                        return false;
                    }
                    map1.insert(word[i], i);
                    map2.insert(pattern[i], i);
                }
                true
            })
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个单词列表&nbsp;<code>words</code>&nbsp;和一个模式&nbsp;&nbsp;<code>pattern</code>，你想知道 <code>words</code> 中的哪些单词与模式匹配。</p>

<p>如果存在字母的排列 <code>p</code>&nbsp;，使得将模式中的每个字母 <code>x</code> 替换为 <code>p(x)</code> 之后，我们就得到了所需的单词，那么单词与模式是匹配的。</p>

<p><em>（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）</em></p>

<p>返回 <code>words</code> 中与给定模式匹配的单词列表。</p>

<p>你可以按任何顺序返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>words = [&quot;abc&quot;,&quot;deq&quot;,&quot;mee&quot;,&quot;aqq&quot;,&quot;dkd&quot;,&quot;ccc&quot;], pattern = &quot;abb&quot;
<strong>输出：</strong>[&quot;mee&quot;,&quot;aqq&quot;]
<strong>解释：
</strong>&quot;mee&quot; 与模式匹配，因为存在排列 {a -&gt; m, b -&gt; e, ...}。
&quot;ccc&quot; 与模式不匹配，因为 {a -&gt; c, b -&gt; c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= pattern.length = words[i].length&nbsp;&lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def match(s, t):
            m1, m2 = [0] * 128, [0] * 128
            for i, (a, b) in enumerate(zip(s, t), 1):
                if m1[ord(a)] != m2[ord(b)]:
                    return False
                m1[ord(a)] = m2[ord(b)] = i
            return True

        return [word for word in words if match(word, pattern)]
```

#### Java

```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            if (match(word, pattern)) {
                ans.add(word);
            }
        }
        return ans;
    }

    private boolean match(String s, String t) {
        int[] m1 = new int[128];
        int[] m2 = new int[128];
        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if (m1[c1] != m2[c2]) {
                return false;
            }
            m1[c1] = i + 1;
            m2[c2] = i + 1;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto match = [](string& s, string& t) {
            int m1[128] = {0};
            int m2[128] = {0};
            for (int i = 0; i < s.size(); ++i) {
                if (m1[s[i]] != m2[t[i]]) return 0;
                m1[s[i]] = i + 1;
                m2[t[i]] = i + 1;
            }
            return 1;
        };
        for (auto& word : words)
            if (match(word, pattern)) ans.emplace_back(word);
        return ans;
    }
};
```

#### Go

```go
func findAndReplacePattern(words []string, pattern string) []string {
	match := func(s, t string) bool {
		m1, m2 := make([]int, 128), make([]int, 128)
		for i := 0; i < len(s); i++ {
			if m1[s[i]] != m2[t[i]] {
				return false
			}
			m1[s[i]] = i + 1
			m2[t[i]] = i + 1
		}
		return true
	}
	var ans []string
	for _, word := range words {
		if match(word, pattern) {
			ans = append(ans, word)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findAndReplacePattern(words: string[], pattern: string): string[] {
    return words.filter(word => {
        const map1 = new Map<string, number>();
        const map2 = new Map<string, number>();
        for (let i = 0; i < word.length; i++) {
            if (map1.get(word[i]) !== map2.get(pattern[i])) {
                return false;
            }
            map1.set(word[i], i);
            map2.set(pattern[i], i);
        }
        return true;
    });
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let pattern = pattern.as_bytes();
        let n = pattern.len();
        words
            .into_iter()
            .filter(|word| {
                let word = word.as_bytes();
                let mut map1 = HashMap::new();
                let mut map2 = HashMap::new();
                for i in 0..n {
                    if map1.get(&word[i]).unwrap_or(&n) != map2.get(&pattern[i]).unwrap_or(&n) {
                        return false;
                    }
                    map1.insert(word[i], i);
                    map2.insert(pattern[i], i);
                }
                true
            })
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [891. 子序列宽度之和](https://leetcode.cn/problems/sum-of-subsequence-widths){#891}

{{< tabs "891" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        nums.sort()
        ans, p = 0, 1
        for i, v in enumerate(nums):
            ans = (ans + (v - nums[-i - 1]) * p) % mod
            p = (p << 1) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int sumSubseqWidths(int[] nums) {
        Arrays.sort(nums);
        long ans = 0, p = 1;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (nums[i] - nums[n - i - 1]) * p + MOD) % MOD;
            p = (p << 1) % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long ans = 0, p = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans = (ans + (nums[i] - nums[n - i - 1]) * p + mod) % mod;
            p = (p << 1) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumSubseqWidths(nums []int) (ans int) {
	const mod int = 1e9 + 7
	sort.Ints(nums)
	p, n := 1, len(nums)
	for i, v := range nums {
		ans = (ans + (v-nums[n-i-1])*p + mod) % mod
		p = (p << 1) % mod
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

<p>一个序列的 <strong>宽度</strong> 定义为该序列中最大元素和最小元素的差值。</p>

<p>给你一个整数数组 <code>nums</code> ，返回 <code>nums</code> 的所有非空 <strong>子序列</strong> 的 <strong>宽度之和</strong> 。由于答案可能非常大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p><strong>子序列</strong> 定义为从一个数组里删除一些（或者不删除）元素，但不改变剩下元素的顺序得到的数组。例如，<code>[3,6,2,7]</code> 就是数组 <code>[0,3,1,6,2,2,7]</code> 的一个子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>6
<strong>解释：</strong>子序列为 [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3] 。
相应的宽度是 0, 0, 0, 1, 1, 2, 2 。
宽度之和是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

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

### 方法一：排序 + 枚举元素计算贡献

题目求解的是数组 `nums` 中所有子序列中最大值与最小值差值之和，注意到“子序列”，并且涉及到“最大值”与“最小值”，我们考虑先对数组 `nums` 进行排序。

然后我们枚举数组 `nums` 中的每个元素 $nums[i]$，该元素左侧的元素个数为 $i$，右侧的元素个数为 $n-i-1$。

如果我们将元素 $nums[i]$ 作为子序列的最大值，总共有多少个满足条件的子序列呢？显然，子序列的其他元素应该从左侧的 $i$ 个元素中选取，每个元素有两种选择，即选或不选，因此总共有 $2^i$ 个子序列。同理，如果我们将元素 $nums[i]$ 作为子序列的最小值，那么总共有 $2^{n-i-1}$ 个满足条件的子序列。因此 $nums[i]$ 对答案的贡献为：

$$
\begin{aligned}
nums[i] \times (2^i - 2^{n-i-1})
\end{aligned}
$$

我们将数组 `nums` 中所有元素的贡献累加，即为答案：

$$
\begin{aligned}
\sum_{i=0}^{n-1} nums[i] \times (2^i - 2^{n-i-1})
\end{aligned}
$$

我们将上式展开，可以得到：

$$
\begin{aligned}
nums[0] \times (2^0 - 2^{n-1}) + nums[1] \times (2^1 - 2^{n-2}) + ... + nums[n-1] \times (2^{n-1} - 2^0)
\end{aligned}
$$

再将式子中相同的幂次项合并，可以得到：

$$
\begin{aligned}
(nums[0] - nums[n-1]) \times 2^0 + (nums[1] - nums[n-2]) \times 2^1 + ... + (nums[n-1] - nums[0]) \times 2^{n-1}
\end{aligned}
$$

即：

$$
\begin{aligned}
\sum_{i=0}^{n-1} (nums[i] - nums[n-i-1]) \times 2^i
\end{aligned}
$$

因此我们只需要对数组 `nums` 进行排序，然后计算上述的贡献即可。注意答案的取模操作。

时间复杂度 $O(n\times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        nums.sort()
        ans, p = 0, 1
        for i, v in enumerate(nums):
            ans = (ans + (v - nums[-i - 1]) * p) % mod
            p = (p << 1) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int sumSubseqWidths(int[] nums) {
        Arrays.sort(nums);
        long ans = 0, p = 1;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (nums[i] - nums[n - i - 1]) * p + MOD) % MOD;
            p = (p << 1) % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long ans = 0, p = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans = (ans + (nums[i] - nums[n - i - 1]) * p + mod) % mod;
            p = (p << 1) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func sumSubseqWidths(nums []int) (ans int) {
	const mod int = 1e9 + 7
	sort.Ints(nums)
	p, n := 1, len(nums)
	for i, v := range nums {
		ans = (ans + (v-nums[n-i-1])*p + mod) % mod
		p = (p << 1) % mod
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [892. 三维形体的表面积](https://leetcode.cn/problems/surface-area-of-3d-shapes){#892}

{{< tabs "892" >}}

{{% tab "python" %}}
```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    ans += 2 + v * 4
                    if i:
                        ans -= min(v, grid[i - 1][j]) * 2
                    if j:
                        ans -= min(v, grid[i][j - 1]) * 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans += 2 + grid[i][j] * 4;
                    if (i > 0) {
                        ans -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
                    }
                    if (j > 0) {
                        ans -= Math.min(grid[i][j], grid[i][j - 1]) * 2;
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
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans += 2 + grid[i][j] * 4;
                    if (i) ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                    if (j) ans -= min(grid[i][j], grid[i][j - 1]) * 2;
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
func surfaceArea(grid [][]int) int {
	ans := 0
	for i, row := range grid {
		for j, v := range row {
			if v > 0 {
				ans += 2 + v*4
				if i > 0 {
					ans -= min(v, grid[i-1][j]) * 2
				}
				if j > 0 {
					ans -= min(v, grid[i][j-1]) * 2
				}
			}
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

<p>给你一个 <code>n * n</code> 的网格&nbsp;<code>grid</code> ，上面放置着一些&nbsp;<code>1 x 1 x 1</code>&nbsp;的正方体。每个值&nbsp;<code>v = grid[i][j]</code>&nbsp;表示&nbsp;<code>v</code>&nbsp;个正方体叠放在对应单元格&nbsp;<code>(i, j)</code>&nbsp;上。</p>

<p>放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。</p>

<p>请你返回最终这些形体的总表面积。</p>

<p><strong>注意：</strong>每个形体的底面也需要计入表面积中。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0892.Surface%20Area%20of%203D%20Shapes/images/tmp-grid2.jpg" style="height: 80px; width: 80px;" />
<pre>
<strong>输入：</strong>grid = [[1,2],[3,4]]
<strong>输出：</strong>34
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0892.Surface%20Area%20of%203D%20Shapes/images/tmp-grid4.jpg" style="height: 100px; width: 100px;" />
<pre>
<strong>输入：</strong>grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出：</strong>32
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0892.Surface%20Area%20of%203D%20Shapes/images/tmp-grid5.jpg" style="height: 100px; width: 100px;" />
<pre>
<strong>输入：</strong>grid = [[2,2,2],[2,1,2],[2,2,2]]
<strong>输出：</strong>46
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历，逐个累加

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    ans += 2 + v * 4
                    if i:
                        ans -= min(v, grid[i - 1][j]) * 2
                    if j:
                        ans -= min(v, grid[i][j - 1]) * 2
        return ans
```

#### Java

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans += 2 + grid[i][j] * 4;
                    if (i > 0) {
                        ans -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
                    }
                    if (j > 0) {
                        ans -= Math.min(grid[i][j], grid[i][j - 1]) * 2;
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
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans += 2 + grid[i][j] * 4;
                    if (i) ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                    if (j) ans -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func surfaceArea(grid [][]int) int {
	ans := 0
	for i, row := range grid {
		for j, v := range row {
			if v > 0 {
				ans += 2 + v*4
				if i > 0 {
					ans -= min(v, grid[i-1][j]) * 2
				}
				if j > 0 {
					ans -= min(v, grid[i][j-1]) * 2
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

# [893. 特殊等价字符串组](https://leetcode.cn/problems/groups-of-special-equivalent-strings){#893}

{{< tabs "893" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSpecialEquivGroups(self, words: List[str]) -> int:
        s = {''.join(sorted(word[::2]) + sorted(word[1::2])) for word in words}
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSpecialEquivGroups(String[] words) {
        Set<String> s = new HashSet<>();
        for (String word : words) {
            s.add(convert(word));
        }
        return s.size();
    }

    private String convert(String word) {
        List<Character> a = new ArrayList<>();
        List<Character> b = new ArrayList<>();
        for (int i = 0; i < word.length(); ++i) {
            char ch = word.charAt(i);
            if (i % 2 == 0) {
                a.add(ch);
            } else {
                b.add(ch);
            }
        }
        Collections.sort(a);
        Collections.sort(b);
        StringBuilder sb = new StringBuilder();
        for (char c : a) {
            sb.append(c);
        }
        for (char c : b) {
            sb.append(c);
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
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> s;
        for (auto& word : words) {
            string a = "", b = "";
            for (int i = 0; i < word.size(); ++i) {
                if (i & 1)
                    a += word[i];
                else
                    b += word[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            s.insert(a + b);
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSpecialEquivGroups(words []string) int {
	s := map[string]bool{}
	for _, word := range words {
		a, b := []rune{}, []rune{}
		for i, c := range word {
			if i&1 == 1 {
				a = append(a, c)
			} else {
				b = append(b, c)
			}
		}
		sort.Slice(a, func(i, j int) bool {
			return a[i] < a[j]
		})
		sort.Slice(b, func(i, j int) bool {
			return b[i] < b[j]
		})
		s[string(a)+string(b)] = true
	}
	return len(s)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code>。</p>

<p>一步操作中，你可以交换字符串 <code>words[i]</code> 的任意两个偶数下标对应的字符或任意两个奇数下标对应的字符。</p>

<p>对两个字符串&nbsp;<code>words[i]</code> 和 <code>words[j]</code> 而言，如果经过任意次数的操作，<code>words[i] == words[j]</code> ，那么这两个字符串是 <strong>特殊等价 </strong>的。</p>

<ul>
	<li>例如，<code>words[i] = "zzxy"</code> 和 <code>words[j] = "xyzz"</code> 是一对 <strong>特殊等价</strong> 字符串，因为可以按 <code>"zzxy" -&gt; "xzzy" -&gt; "xyzz"</code> 的操作路径使&nbsp;<code>words[i] == words[j]</code> 。</li>
</ul>

<p>现在规定，<strong><code>words</code> </strong>的 <strong>一组特殊等价字符串 </strong>就是 <code>words</code> 的一个同时满足下述条件的非空子集：</p>

<ul>
	<li>该组中的每一对字符串都是<strong> 特殊等价 </strong>的</li>
	<li>该组字符串已经涵盖了该类别中的所有特殊等价字符串，容量达到理论上的最大值（也就是说，如果一个字符串不在该组中，那么这个字符串就 <strong>不会</strong> 与该组内任何字符串特殊等价）</li>
</ul>

<p>返回 <code>words</code> 中 <strong>特殊等价字符串组</strong> 的数量。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
<strong>输出：</strong>3
<strong>解释：</strong>
其中一组为 ["abcd", "cdab", "cbad"]，因为它们是成对的特殊等价字符串，且没有其他字符串与这些字符串特殊等价。
另外两组分别是 ["xyzz", "zzxy"] 和 ["zzyx"]。特别需要注意的是，"zzxy" 不与 "zzyx" 特殊等价。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["abc","acb","bac","bca","cab","cba"]
<strong>输出：</strong>3
<strong>解释：</strong>3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li>所有 <code>words[i]</code>&nbsp;都只由小写字母组成。</li>
	<li>所有 <code>words[i]</code>&nbsp;都具有相同的长度。</li>
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
    def numSpecialEquivGroups(self, words: List[str]) -> int:
        s = {''.join(sorted(word[::2]) + sorted(word[1::2])) for word in words}
        return len(s)
```

#### Java

```java
class Solution {
    public int numSpecialEquivGroups(String[] words) {
        Set<String> s = new HashSet<>();
        for (String word : words) {
            s.add(convert(word));
        }
        return s.size();
    }

    private String convert(String word) {
        List<Character> a = new ArrayList<>();
        List<Character> b = new ArrayList<>();
        for (int i = 0; i < word.length(); ++i) {
            char ch = word.charAt(i);
            if (i % 2 == 0) {
                a.add(ch);
            } else {
                b.add(ch);
            }
        }
        Collections.sort(a);
        Collections.sort(b);
        StringBuilder sb = new StringBuilder();
        for (char c : a) {
            sb.append(c);
        }
        for (char c : b) {
            sb.append(c);
        }
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> s;
        for (auto& word : words) {
            string a = "", b = "";
            for (int i = 0; i < word.size(); ++i) {
                if (i & 1)
                    a += word[i];
                else
                    b += word[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            s.insert(a + b);
        }
        return s.size();
    }
};
```

#### Go

```go
func numSpecialEquivGroups(words []string) int {
	s := map[string]bool{}
	for _, word := range words {
		a, b := []rune{}, []rune{}
		for i, c := range word {
			if i&1 == 1 {
				a = append(a, c)
			} else {
				b = append(b, c)
			}
		}
		sort.Slice(a, func(i, j int) bool {
			return a[i] < a[j]
		})
		sort.Slice(b, func(i, j int) bool {
			return b[i] < b[j]
		})
		s[string(a)+string(b)] = true
	}
	return len(s)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [894. 所有可能的真二叉树](https://leetcode.cn/problems/all-possible-full-binary-trees){#894}

{{< tabs "894" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        @cache
        def dfs(n: int) -> List[Optional[TreeNode]]:
            if n == 1:
                return [TreeNode()]
            ans = []
            for i in range(n - 1):
                j = n - 1 - i
                for left in dfs(i):
                    for right in dfs(j):
                        ans.append(TreeNode(0, left, right))
            return ans

        return dfs(n)
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
    private List<TreeNode>[] f;

    public List<TreeNode> allPossibleFBT(int n) {
        f = new List[n + 1];
        return dfs(n);
    }

    private List<TreeNode> dfs(int n) {
        if (f[n] != null) {
            return f[n];
        }
        if (n == 1) {
            return List.of(new TreeNode());
        }
        List<TreeNode> ans = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            int j = n - 1 - i;
            for (var left : dfs(i)) {
                for (var right : dfs(j)) {
                    ans.add(new TreeNode(0, left, right));
                }
            }
        }
        return f[n] = ans;
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> f(n + 1);
        function<vector<TreeNode*>(int)> dfs = [&](int n) -> vector<TreeNode*> {
            if (f[n].size()) {
                return f[n];
            }
            if (n == 1) {
                return vector<TreeNode*>{new TreeNode()};
            }
            vector<TreeNode*> ans;
            for (int i = 0; i < n - 1; ++i) {
                int j = n - 1 - i;
                for (auto left : dfs(i)) {
                    for (auto right : dfs(j)) {
                        ans.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            return f[n] = ans;
        };
        return dfs(n);
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
func allPossibleFBT(n int) []*TreeNode {
	f := make([][]*TreeNode, n+1)
	var dfs func(int) []*TreeNode
	dfs = func(n int) []*TreeNode {
		if len(f[n]) > 0 {
			return f[n]
		}
		if n == 1 {
			return []*TreeNode{&TreeNode{Val: 0}}
		}
		ans := []*TreeNode{}
		for i := 0; i < n-1; i++ {
			j := n - 1 - i
			for _, left := range dfs(i) {
				for _, right := range dfs(j) {
					ans = append(ans, &TreeNode{0, left, right})
				}
			}
		}
		f[n] = ans
		return ans
	}
	return dfs(n)
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

function allPossibleFBT(n: number): Array<TreeNode | null> {
    const f: Array<Array<TreeNode | null>> = new Array(n + 1).fill(0).map(() => []);
    const dfs = (n: number): Array<TreeNode | null> => {
        if (f[n].length) {
            return f[n];
        }
        if (n === 1) {
            f[n].push(new TreeNode(0));
            return f[n];
        }
        const ans: Array<TreeNode | null> = [];
        for (let i = 0; i < n - 1; ++i) {
            const j = n - 1 - i;
            for (const left of dfs(i)) {
                for (const right of dfs(j)) {
                    ans.push(new TreeNode(0, left, right));
                }
            }
        }
        return (f[n] = ans);
    };
    return dfs(n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut f: Vec<Option<Vec<Option<Rc<RefCell<TreeNode>>>>>> = vec![None; (n + 1) as usize];
        Self::dfs(n, &mut f)
    }

    fn dfs(
        n: i32,
        f: &mut Vec<Option<Vec<Option<Rc<RefCell<TreeNode>>>>>>,
    ) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if let Some(ref result) = f[n as usize] {
            return result.clone();
        }

        let mut ans = Vec::new();
        if n == 1 {
            ans.push(Some(Rc::new(RefCell::new(TreeNode::new(0)))));
            return ans;
        }

        for i in 0..n - 1 {
            let j = n - 1 - i;
            for left in Self::dfs(i, f).iter() {
                for right in Self::dfs(j, f).iter() {
                    let new_node = Some(Rc::new(RefCell::new(TreeNode {
                        val: 0,
                        left: left.clone(),
                        right: right.clone(),
                    })));
                    ans.push(new_node);
                }
            }
        }
        f[n as usize] = Some(ans.clone());
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private List<TreeNode>[] f;

    public IList<TreeNode> AllPossibleFBT(int n) {
        f = new List<TreeNode>[n + 1];
        return Dfs(n);
    }

    private IList<TreeNode> Dfs(int n) {
        if (f[n] != null) {
            return f[n];
        }

        if (n == 1) {
            return new List<TreeNode> { new TreeNode() };
        }

        List<TreeNode> ans = new List<TreeNode>();
        for (int i = 0; i < n - 1; ++i) {
            int j = n - 1 - i;
            foreach (var left in Dfs(i)) {
                foreach (var right in Dfs(j)) {
                    ans.Add(new TreeNode(0, left, right));
                }
            }
        }
        f[n] = ans;
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

<p>给你一个整数 <code>n</code> ，请你找出所有可能含 <code>n</code> 个节点的 <strong>真二叉树</strong> ，并以列表形式返回。答案中每棵树的每个节点都必须符合 <code>Node.val == 0</code> 。</p>

<p>答案的每个元素都是一棵真二叉树的根节点。你可以按 <strong>任意顺序</strong> 返回最终的真二叉树列表<strong>。</strong></p>

<p><strong>真二叉树</strong> 是一类二叉树，树中每个节点恰好有 <code>0</code> 或 <code>2</code> 个子节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0894.All%20Possible%20Full%20Binary%20Trees/images/fivetrees.png" style="width: 700px; height: 400px;" />
<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>[[0,0,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

如果 $n=1$，直接返回单个节点的列表。

如果 $n \gt 1$，我们可以枚举左子树的节点数量 $i$，那么右子树的节点数量为 $n-1-i$。对于每种情况，我们递归地构造左子树和右子树的所有可能的真二叉树。然后将左子树和右子树两两组合，得到所有可能的真二叉树。

此过程可以用记忆化搜索，避免重复计算。

时间复杂度 $O(\frac{2^n}{\sqrt{n}})$，空间复杂度 $O(\frac{2^n}{\sqrt{n}})$。其中 $n$ 是节点数量。

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
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        @cache
        def dfs(n: int) -> List[Optional[TreeNode]]:
            if n == 1:
                return [TreeNode()]
            ans = []
            for i in range(n - 1):
                j = n - 1 - i
                for left in dfs(i):
                    for right in dfs(j):
                        ans.append(TreeNode(0, left, right))
            return ans

        return dfs(n)
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
    private List<TreeNode>[] f;

    public List<TreeNode> allPossibleFBT(int n) {
        f = new List[n + 1];
        return dfs(n);
    }

    private List<TreeNode> dfs(int n) {
        if (f[n] != null) {
            return f[n];
        }
        if (n == 1) {
            return List.of(new TreeNode());
        }
        List<TreeNode> ans = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            int j = n - 1 - i;
            for (var left : dfs(i)) {
                for (var right : dfs(j)) {
                    ans.add(new TreeNode(0, left, right));
                }
            }
        }
        return f[n] = ans;
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> f(n + 1);
        function<vector<TreeNode*>(int)> dfs = [&](int n) -> vector<TreeNode*> {
            if (f[n].size()) {
                return f[n];
            }
            if (n == 1) {
                return vector<TreeNode*>{new TreeNode()};
            }
            vector<TreeNode*> ans;
            for (int i = 0; i < n - 1; ++i) {
                int j = n - 1 - i;
                for (auto left : dfs(i)) {
                    for (auto right : dfs(j)) {
                        ans.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            return f[n] = ans;
        };
        return dfs(n);
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
func allPossibleFBT(n int) []*TreeNode {
	f := make([][]*TreeNode, n+1)
	var dfs func(int) []*TreeNode
	dfs = func(n int) []*TreeNode {
		if len(f[n]) > 0 {
			return f[n]
		}
		if n == 1 {
			return []*TreeNode{&TreeNode{Val: 0}}
		}
		ans := []*TreeNode{}
		for i := 0; i < n-1; i++ {
			j := n - 1 - i
			for _, left := range dfs(i) {
				for _, right := range dfs(j) {
					ans = append(ans, &TreeNode{0, left, right})
				}
			}
		}
		f[n] = ans
		return ans
	}
	return dfs(n)
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

function allPossibleFBT(n: number): Array<TreeNode | null> {
    const f: Array<Array<TreeNode | null>> = new Array(n + 1).fill(0).map(() => []);
    const dfs = (n: number): Array<TreeNode | null> => {
        if (f[n].length) {
            return f[n];
        }
        if (n === 1) {
            f[n].push(new TreeNode(0));
            return f[n];
        }
        const ans: Array<TreeNode | null> = [];
        for (let i = 0; i < n - 1; ++i) {
            const j = n - 1 - i;
            for (const left of dfs(i)) {
                for (const right of dfs(j)) {
                    ans.push(new TreeNode(0, left, right));
                }
            }
        }
        return (f[n] = ans);
    };
    return dfs(n);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut f: Vec<Option<Vec<Option<Rc<RefCell<TreeNode>>>>>> = vec![None; (n + 1) as usize];
        Self::dfs(n, &mut f)
    }

    fn dfs(
        n: i32,
        f: &mut Vec<Option<Vec<Option<Rc<RefCell<TreeNode>>>>>>,
    ) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if let Some(ref result) = f[n as usize] {
            return result.clone();
        }

        let mut ans = Vec::new();
        if n == 1 {
            ans.push(Some(Rc::new(RefCell::new(TreeNode::new(0)))));
            return ans;
        }

        for i in 0..n - 1 {
            let j = n - 1 - i;
            for left in Self::dfs(i, f).iter() {
                for right in Self::dfs(j, f).iter() {
                    let new_node = Some(Rc::new(RefCell::new(TreeNode {
                        val: 0,
                        left: left.clone(),
                        right: right.clone(),
                    })));
                    ans.push(new_node);
                }
            }
        }
        f[n as usize] = Some(ans.clone());
        ans
    }
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private List<TreeNode>[] f;

    public IList<TreeNode> AllPossibleFBT(int n) {
        f = new List<TreeNode>[n + 1];
        return Dfs(n);
    }

    private IList<TreeNode> Dfs(int n) {
        if (f[n] != null) {
            return f[n];
        }

        if (n == 1) {
            return new List<TreeNode> { new TreeNode() };
        }

        List<TreeNode> ans = new List<TreeNode>();
        for (int i = 0; i < n - 1; ++i) {
            int j = n - 1 - i;
            foreach (var left in Dfs(i)) {
                foreach (var right in Dfs(j)) {
                    ans.Add(new TreeNode(0, left, right));
                }
            }
        }
        f[n] = ans;
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [895. 最大频率栈](https://leetcode.cn/problems/maximum-frequency-stack){#895}

{{< tabs "895" >}}

{{% tab "python" %}}
```python
class FreqStack:
    def __init__(self):
        self.cnt = defaultdict(int)
        self.d = defaultdict(list)
        self.mx = 0

    def push(self, val: int) -> None:
        self.cnt[val] += 1
        self.d[self.cnt[val]].append(val)
        self.mx = max(self.mx, self.cnt[val])

    def pop(self) -> int:
        val = self.d[self.mx].pop()
        self.cnt[val] -= 1
        if not self.d[self.mx]:
            self.mx -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FreqStack {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Map<Integer, Deque<Integer>> d = new HashMap<>();
    private int mx;

    public FreqStack() {
    }

    public void push(int val) {
        cnt.put(val, cnt.getOrDefault(val, 0) + 1);
        int t = cnt.get(val);
        d.computeIfAbsent(t, k -> new ArrayDeque<>()).push(val);
        mx = Math.max(mx, t);
    }

    public int pop() {
        int val = d.get(mx).pop();
        cnt.put(val, cnt.get(val) - 1);
        if (d.get(mx).isEmpty()) {
            --mx;
        }
        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FreqStack {
public:
    FreqStack() {
    }

    void push(int val) {
        ++cnt[val];
        d[cnt[val]].push(val);
        mx = max(mx, cnt[val]);
    }

    int pop() {
        int val = d[mx].top();
        --cnt[val];
        d[mx].pop();
        if (d[mx].empty()) --mx;
        return val;
    }

private:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> d;
    int mx = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type FreqStack struct {
	cnt map[int]int
	d   map[int][]int
	mx  int
}

func Constructor() FreqStack {
	return FreqStack{map[int]int{}, map[int][]int{}, 0}
}

func (this *FreqStack) Push(val int) {
	this.cnt[val]++
	this.d[this.cnt[val]] = append(this.d[this.cnt[val]], val)
	this.mx = max(this.mx, this.cnt[val])
}

func (this *FreqStack) Pop() int {
	val := this.d[this.mx][len(this.d[this.mx])-1]
	this.d[this.mx] = this.d[this.mx][:len(this.d[this.mx])-1]
	this.cnt[val]--
	if len(this.d[this.mx]) == 0 {
		this.mx--
	}
	return val
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出<strong>出现频率</strong>最高的元素。</p>

<p>实现 <code>FreqStack</code>&nbsp;类:</p>

<ul>
	<li><meta charset="UTF-8" /><code>FreqStack()</code>&nbsp;构造一个空的堆栈。</li>
	<li><meta charset="UTF-8" /><code>void push(int val)</code>&nbsp;将一个整数&nbsp;<code>val</code>&nbsp;压入栈顶。</li>
	<li><meta charset="UTF-8" /><code>int pop()</code>&nbsp;删除并返回堆栈中出现频率最高的元素。
	<ul>
		<li>如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
<strong>输出：</strong>[null,null,null,null,null,null,null,5,7,5,4]
<strong>解释：</strong>
FreqStack = new FreqStack();
freqStack.push (5);//堆栈为 [5]
freqStack.push (7);//堆栈是 [5,7]
freqStack.push (5);//堆栈是 [5,7,5]
freqStack.push (7);//堆栈是 [5,7,5,7]
freqStack.push (4);//堆栈是 [5,7,5,7,4]
freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li><code>push</code>&nbsp;和 <code>pop</code>&nbsp;的操作数不大于 <code>2 * 10<sup>4</sup></code>。</li>
	<li>输入保证在调用&nbsp;<code>pop</code>&nbsp;之前堆栈中至少有一个元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 优先队列（大根堆）

根据题目描述，我们需要设计一个支持弹出“出现频率最高”的元素的数据结构。如果存在多个元素出现频率相同，那么弹出最接近栈顶的元素。

我们可以使用哈希表 $cnt$ 记录每个元素出现的频率，用一个优先队列（大根堆） $q$ 维护元素频率以及对应的压栈时间戳。

执行压栈操作时，我们先将当前时间戳加一，即 $ts \gets ts + 1$；然后将元素 $val$ 的频率加一，即 $cnt[val] \gets cnt[val] + 1$，最后将三元组 $(cnt[val], ts, val)$ 加入优先队列 $q$ 中。压栈操作的时间复杂度为 $O(\log n)$。

执行弹栈操作时，我们直接从优先队列 $q$ 中弹出一个元素即可。由于优先队列 $q$ 中的元素按照频率降序排序，因此弹出的元素一定是出现频率最高的元素。如果存在多个元素出现频率相同，那么弹出最接近栈顶的元素，即弹出时间戳最大的元素。弹出后，我们将弹出元素的频率减一，即 $cnt[val] \gets cnt[val] - 1$。弹栈操作的时间复杂度为 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class FreqStack:
    def __init__(self):
        self.cnt = defaultdict(int)
        self.q = []
        self.ts = 0

    def push(self, val: int) -> None:
        self.ts += 1
        self.cnt[val] += 1
        heappush(self.q, (-self.cnt[val], -self.ts, val))

    def pop(self) -> int:
        val = heappop(self.q)[2]
        self.cnt[val] -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
```

#### Java

```java
class FreqStack {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private PriorityQueue<int[]> q
        = new PriorityQueue<>((a, b) -> a[0] == b[0] ? b[1] - a[1] : b[0] - a[0]);
    private int ts;

    public FreqStack() {
    }

    public void push(int val) {
        cnt.put(val, cnt.getOrDefault(val, 0) + 1);
        q.offer(new int[] {cnt.get(val), ++ts, val});
    }

    public int pop() {
        int val = q.poll()[2];
        cnt.put(val, cnt.get(val) - 1);
        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
```

#### C++

```cpp
class FreqStack {
public:
    FreqStack() {
    }

    void push(int val) {
        ++cnt[val];
        q.emplace(cnt[val], ++ts, val);
    }

    int pop() {
        auto [a, b, val] = q.top();
        q.pop();
        --cnt[val];
        return val;
    }

private:
    unordered_map<int, int> cnt;
    priority_queue<tuple<int, int, int>> q;
    int ts = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```

#### Go

```go
type FreqStack struct {
	cnt map[int]int
	q   hp
	ts  int
}

func Constructor() FreqStack {
	return FreqStack{map[int]int{}, hp{}, 0}
}

func (this *FreqStack) Push(val int) {
	this.cnt[val]++
	this.ts++
	heap.Push(&this.q, tuple{this.cnt[val], this.ts, val})
}

func (this *FreqStack) Pop() int {
	val := heap.Pop(&this.q).(tuple).val
	this.cnt[val]--
	return val
}

type tuple struct{ cnt, ts, val int }
type hp []tuple

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	return h[i].cnt > h[j].cnt || h[i].cnt == h[j].cnt && h[i].ts > h[j].ts
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双哈希表

在方法一中，为了能弹出符合要求的元素，我们维护了一个优先队列，每次都需要对优先队列进行操作，时间复杂度为 $O(\log n)$。如果我们能够在 $O(1)$ 的时间内找到符合要求的元素，那么整个数据结构每次操作的时间复杂度就可以降低到 $O(1)$。

实际上，我们可以用一个变量 $mx$ 记录当前出现频率的最大值，用一个哈希表 $d$ 记录每个出现频率对应的元素列表，与方法一相同，用一个哈希表 $cnt$ 记录每个元素出现的频率。

执行压栈操作时，我们将元素的频率加一，即 $cnt[val] \gets cnt[val] + 1$，然后将元素 $val$ 加入哈希表 $d$ 中对应的频率列表中，即 $d[cnt[val]].push(val)$。如果当前元素的频率大于 $mx$，则更新 $mx$，即 $mx \gets cnt[val]$。压栈操作的时间复杂度为 $O(1)$。

执行弹栈操作时，我们从哈希表 $d$ 中取出频率为 $mx$ 的元素列表，弹出列表中的最后一个元素 $val$，然后将 $val$ 从哈希表 $d$ 中移除，即 $d[mx].pop()$。最后将 $val$ 的频率减一，即 $cnt[val] \gets cnt[val] - 1$。如果 $d[mx]$ 列表为空，说明当前出现频率最大的元素已经全部弹出，我们需要将 $mx$ 减一，即 $mx \gets mx - 1$。弹栈操作的时间复杂度为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class FreqStack:
    def __init__(self):
        self.cnt = defaultdict(int)
        self.d = defaultdict(list)
        self.mx = 0

    def push(self, val: int) -> None:
        self.cnt[val] += 1
        self.d[self.cnt[val]].append(val)
        self.mx = max(self.mx, self.cnt[val])

    def pop(self) -> int:
        val = self.d[self.mx].pop()
        self.cnt[val] -= 1
        if not self.d[self.mx]:
            self.mx -= 1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
```

#### Java

```java
class FreqStack {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Map<Integer, Deque<Integer>> d = new HashMap<>();
    private int mx;

    public FreqStack() {
    }

    public void push(int val) {
        cnt.put(val, cnt.getOrDefault(val, 0) + 1);
        int t = cnt.get(val);
        d.computeIfAbsent(t, k -> new ArrayDeque<>()).push(val);
        mx = Math.max(mx, t);
    }

    public int pop() {
        int val = d.get(mx).pop();
        cnt.put(val, cnt.get(val) - 1);
        if (d.get(mx).isEmpty()) {
            --mx;
        }
        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
```

#### C++

```cpp
class FreqStack {
public:
    FreqStack() {
    }

    void push(int val) {
        ++cnt[val];
        d[cnt[val]].push(val);
        mx = max(mx, cnt[val]);
    }

    int pop() {
        int val = d[mx].top();
        --cnt[val];
        d[mx].pop();
        if (d[mx].empty()) --mx;
        return val;
    }

private:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> d;
    int mx = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```

#### Go

```go
type FreqStack struct {
	cnt map[int]int
	d   map[int][]int
	mx  int
}

func Constructor() FreqStack {
	return FreqStack{map[int]int{}, map[int][]int{}, 0}
}

func (this *FreqStack) Push(val int) {
	this.cnt[val]++
	this.d[this.cnt[val]] = append(this.d[this.cnt[val]], val)
	this.mx = max(this.mx, this.cnt[val])
}

func (this *FreqStack) Pop() int {
	val := this.d[this.mx][len(this.d[this.mx])-1]
	this.d[this.mx] = this.d[this.mx][:len(this.d[this.mx])-1]
	this.cnt[val]--
	if len(this.d[this.mx]) == 0 {
		this.mx--
	}
	return val
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [896. 单调数列](https://leetcode.cn/problems/monotonic-array){#896}

{{< tabs "896" >}}

{{% tab "python" %}}
```python
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        asc = all(a <= b for a, b in pairwise(nums))
        desc = all(a >= b for a, b in pairwise(nums))
        return asc or desc
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean asc = false, desc = false;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                asc = true;
            } else if (nums[i - 1] > nums[i]) {
                desc = true;
            }
            if (asc && desc) {
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
    bool isMonotonic(vector<int>& nums) {
        bool asc = false, desc = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                asc = true;
            } else if (nums[i - 1] > nums[i]) {
                desc = true;
            }
            if (asc && desc) {
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
func isMonotonic(nums []int) bool {
	asc, desc := false, false
	for i, x := range nums[1:] {
		if nums[i] < x {
			asc = true
		} else if nums[i] > x {
			desc = true
		}
		if asc && desc {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isMonotonic(nums: number[]): boolean {
    let [asc, desc] = [false, false];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            asc = true;
        } else if (nums[i - 1] > nums[i]) {
            desc = true;
        }
        if (asc && desc) {
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
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut asc = false;
        let mut desc = false;
        for i in 1..nums.len() {
            if nums[i - 1] < nums[i] {
                asc = true;
            } else if nums[i - 1] > nums[i] {
                desc = true;
            }
            if asc && desc {
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
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function (nums) {
    let [asc, desc] = [false, false];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            asc = true;
        } else if (nums[i - 1] > nums[i]) {
            desc = true;
        }
        if (asc && desc) {
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

<p>如果数组是单调递增或单调递减的，那么它是&nbsp;<strong>单调 </strong><em>的</em>。</p>

<p>如果对于所有 <code>i &lt;= j</code>，<code>nums[i] &lt;= nums[j]</code>，那么数组 <code>nums</code> 是单调递增的。 如果对于所有 <code>i &lt;= j</code>，<code>nums[i] &gt;= nums[j]</code>，那么数组 <code>nums</code>&nbsp;是单调递减的。</p>

<p>当给定的数组 <code>nums</code>&nbsp;是单调数组时返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,5,4,4]
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

遍历数组，如果出现递增或递减的情况，记录下来。判断是否出现过递增和递减的情况，如果都出现过，说明不是单调数组，返回 `false`。

否则遍历结束，说明是单调数组，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        asc = all(a <= b for a, b in pairwise(nums))
        desc = all(a >= b for a, b in pairwise(nums))
        return asc or desc
```

#### Java

```java
class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean asc = false, desc = false;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                asc = true;
            } else if (nums[i - 1] > nums[i]) {
                desc = true;
            }
            if (asc && desc) {
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
    bool isMonotonic(vector<int>& nums) {
        bool asc = false, desc = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                asc = true;
            } else if (nums[i - 1] > nums[i]) {
                desc = true;
            }
            if (asc && desc) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isMonotonic(nums []int) bool {
	asc, desc := false, false
	for i, x := range nums[1:] {
		if nums[i] < x {
			asc = true
		} else if nums[i] > x {
			desc = true
		}
		if asc && desc {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isMonotonic(nums: number[]): boolean {
    let [asc, desc] = [false, false];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            asc = true;
        } else if (nums[i - 1] > nums[i]) {
            desc = true;
        }
        if (asc && desc) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut asc = false;
        let mut desc = false;
        for i in 1..nums.len() {
            if nums[i - 1] < nums[i] {
                asc = true;
            } else if nums[i - 1] > nums[i] {
                desc = true;
            }
            if asc && desc {
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
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function (nums) {
    let [asc, desc] = [false, false];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i - 1] < nums[i]) {
            asc = true;
        } else if (nums[i - 1] > nums[i]) {
            desc = true;
        }
        if (asc && desc) {
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

# [897. 递增顺序搜索树](https://leetcode.cn/problems/increasing-order-search-tree){#897}

{{< tabs "897" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return
            nonlocal prev
            dfs(root.left)
            prev.right = root
            root.left = None
            prev = root
            dfs(root.right)

        dummy = prev = TreeNode(right=root)
        dfs(root)
        return dummy.right
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
    private TreeNode prev;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(0, null, root);
        prev = dummy;
        dfs(root);
        return dummy.right;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        prev.right = root;
        root.left = null;
        prev = root;
        dfs(root.right);
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0, nullptr, root);
        TreeNode* prev = dummy;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            prev->right = root;
            root->left = nullptr;
            prev = root;
            dfs(root->right);
        };
        dfs(root);
        return dummy->right;
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
func increasingBST(root *TreeNode) *TreeNode {
	dummy := &TreeNode{Val: 0, Right: root}
	prev := dummy
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		prev.Right = root
		root.Left = nil
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	return dummy.Right
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

function increasingBST(root: TreeNode | null): TreeNode | null {
    const dummy = new TreeNode((right = root));
    let prev = dummy;
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        prev.right = root;
        root.left = null;
        prev = root;
        dfs(root.right);
    };
    dfs(root);
    return dummy.right;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉搜索树的<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，请你 <strong>按中序遍历</strong> 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0897.Increasing%20Order%20Search%20Tree/images/ex1.jpg" style="height: 350px; width: 600px;" />
<pre>
<strong>输入：</strong>root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
<strong>输出：</strong>[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0897.Increasing%20Order%20Search%20Tree/images/ex2.jpg" style="height: 114px; width: 300px;" />
<pre>
<strong>输入：</strong>root = [5,1,7]
<strong>输出：</strong>[1,null,5,null,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数的取值范围是 <code>[1, 100]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 中序遍历

我们定义一个虚拟节点 $dummy$，初始时 $dummy$ 的右子节点指向根节点 $root$，定义一个指针 $prev$ 指向 $dummy$。

我们对二叉搜索树进行中序遍历，遍历过程中，每遍历到一个节点，就将 $prev$ 的右子节点指向它，然后将当前节点的左子节点置为空，再将当前节点赋值给 $prev$，以便于下一次遍历。

遍历结束后，原二叉搜索树被修改成只有右子节点的单链表，我们再将虚拟节点 $dummy$ 的右子节点返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉搜索树的节点个数。

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
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return
            nonlocal prev
            dfs(root.left)
            prev.right = root
            root.left = None
            prev = root
            dfs(root.right)

        dummy = prev = TreeNode(right=root)
        dfs(root)
        return dummy.right
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
    private TreeNode prev;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(0, null, root);
        prev = dummy;
        dfs(root);
        return dummy.right;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        prev.right = root;
        root.left = null;
        prev = root;
        dfs(root.right);
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0, nullptr, root);
        TreeNode* prev = dummy;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            prev->right = root;
            root->left = nullptr;
            prev = root;
            dfs(root->right);
        };
        dfs(root);
        return dummy->right;
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
func increasingBST(root *TreeNode) *TreeNode {
	dummy := &TreeNode{Val: 0, Right: root}
	prev := dummy
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		prev.Right = root
		root.Left = nil
		prev = root
		dfs(root.Right)
	}
	dfs(root)
	return dummy.Right
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

function increasingBST(root: TreeNode | null): TreeNode | null {
    const dummy = new TreeNode((right = root));
    let prev = dummy;
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        prev.right = root;
        root.left = null;
        prev = root;
        dfs(root.right);
    };
    dfs(root);
    return dummy.right;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [898. 子数组按位或操作](https://leetcode.cn/problems/bitwise-ors-of-subarrays){#898}

{{< tabs "898" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        ans = set()
        s = set()
        for x in arr:
            s = {x | y for y in s} | {x}
            ans |= s
        return len(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> ans = new HashSet<>();
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            Set<Integer> t = new HashSet<>();
            for (int y : s) {
                t.add(x | y);
            }
            t.add(x);
            ans.addAll(t);
            s = t;
        }
        return ans.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> s;
        for (int x : arr) {
            unordered_set<int> t;
            for (int y : s) {
                t.insert(x | y);
            }
            t.insert(x);
            ans.insert(t.begin(), t.end());
            s = move(t);
        }
        return ans.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarrayBitwiseORs(arr []int) int {
	ans := map[int]bool{}
	s := map[int]bool{}
	for _, x := range arr {
		t := map[int]bool{x: true}
		for y := range s {
			t[x|y] = true
		}
		for y := range t {
			ans[y] = true
		}
		s = t
	}
	return len(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subarrayBitwiseORs(arr: number[]): number {
    const ans: Set<number> = new Set();
    const s: Set<number> = new Set();
    for (const x of arr) {
        const t: Set<number> = new Set([x]);
        for (const y of s) {
            t.add(x | y);
        }
        s.clear();
        for (const y of t) {
            ans.add(y);
            s.add(y);
        }
    }
    return ans.size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组<meta charset="UTF-8" />&nbsp;<code>arr</code>，返回所有&nbsp;<code>arr</code>&nbsp;的非空子数组的不同按位或的数量。</p>

<p>子数组的按位或是子数组中每个整数的按位或。含有一个整数的子数组的按位或就是该整数。</p>

<p><strong>子数组</strong> 是数组内连续的非空元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [0]
<strong>输出：</strong>1
<strong>解释：</strong>
只有一个可能的结果 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,2]
<strong>输出：</strong>3
<strong>解释：</strong>
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,4]
<strong>输出：</strong>6
<strong>解释：</strong>
可能的结果是 1，2，3，4，6，以及 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

题目求的是子数组按位或操作的结果的数量，如果我们枚举子数组的结束位置 $i$，那么以 $i-1$ 结尾的子数组按位或操作的结果的数量最多不超过 $32$ 个。这是因为，按位或是一个单调递增的操作。

因此，我们用一个哈希表 $ans$ 记录所有子数组按位或操作的结果，用一个哈希表 $s$ 记录以当前元素结尾的子数组按位或操作的结果，初始时 $s$ 只包含一个元素 $0$。

接下来，我们枚举子数组的结束位置 $i$，那么以 $i$ 结尾的子数组按位或操作的结果，是以 $i-1$ 结尾的子数组按位或操作的结果与 $a[i]$ 进行按位或操作的结果的集合，再加上 $a[i]$ 本身。我们用一个哈希表 $t$ 记录以 $i$ 结尾的子数组按位或操作的结果，然后我们更新 $s = t$，并将 $t$ 中的所有元素加入 $ans$。

最终，我们返回哈希表 $ans$ 中元素的数量即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$。其中 $n$ 和 $M$ 分别为数组长度和数组中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        ans = set()
        s = set()
        for x in arr:
            s = {x | y for y in s} | {x}
            ans |= s
        return len(ans)
```

#### Java

```java
class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> ans = new HashSet<>();
        Set<Integer> s = new HashSet<>();
        for (int x : arr) {
            Set<Integer> t = new HashSet<>();
            for (int y : s) {
                t.add(x | y);
            }
            t.add(x);
            ans.addAll(t);
            s = t;
        }
        return ans.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> s;
        for (int x : arr) {
            unordered_set<int> t;
            for (int y : s) {
                t.insert(x | y);
            }
            t.insert(x);
            ans.insert(t.begin(), t.end());
            s = move(t);
        }
        return ans.size();
    }
};
```

#### Go

```go
func subarrayBitwiseORs(arr []int) int {
	ans := map[int]bool{}
	s := map[int]bool{}
	for _, x := range arr {
		t := map[int]bool{x: true}
		for y := range s {
			t[x|y] = true
		}
		for y := range t {
			ans[y] = true
		}
		s = t
	}
	return len(ans)
}
```

#### TypeScript

```ts
function subarrayBitwiseORs(arr: number[]): number {
    const ans: Set<number> = new Set();
    const s: Set<number> = new Set();
    for (const x of arr) {
        const t: Set<number> = new Set([x]);
        for (const y of s) {
            t.add(x | y);
        }
        s.clear();
        for (const y of t) {
            ans.add(y);
            s.add(y);
        }
    }
    return ans.size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [899. 有序队列](https://leetcode.cn/problems/orderly-queue){#899}

{{< tabs "899" >}}

{{% tab "python" %}}
```python
class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            ans = s
            for _ in range(len(s) - 1):
                s = s[1:] + s[0]
                ans = min(ans, s)
            return ans
        return "".join(sorted(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String ans = s;
            StringBuilder sb = new StringBuilder(s);
            for (int i = 0; i < s.length() - 1; ++i) {
                sb.append(sb.charAt(0)).deleteCharAt(0);
                if (sb.toString().compareTo(ans) < 0) {
                    ans = sb.toString();
                }
            }
            return ans;
        }
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 0; i < s.size() - 1; ++i) {
                s = s.substr(1) + s[0];
                if (s < ans) ans = s;
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func orderlyQueue(s string, k int) string {
	if k == 1 {
		ans := s
		for i := 0; i < len(s)-1; i++ {
			s = s[1:] + s[:1]
			if s < ans {
				ans = s
			}
		}
		return ans
	}
	t := []byte(s)
	sort.Slice(t, func(i, j int) bool { return t[i] < t[j] })
	return string(t)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function orderlyQueue(s: string, k: number): string {
    if (k > 1) {
        return [...s].sort().join('');
    }
    const n = s.length;
    let min = s;
    for (let i = 1; i < n; i++) {
        const t = s.slice(i) + s.slice(0, i);
        if (t < min) {
            min = t;
        }
    }
    return min;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code> 和一个整数 <code>k</code>&nbsp;。你可以从 <code>s</code> 的前 <code>k</code> 个字母中选择一个，并把它加到字符串的末尾。</p>

<p>返回 <em>在应用上述步骤的任意数量的移动后，字典序最小的字符串&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "cba", k = 1
<strong>输出：</strong>"acb"
<strong>解释：</strong>
在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "baaca", k = 3
<strong>输出：</strong>"aaabc"
<strong>解释：
</strong>在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k&nbsp;&lt;= S.length&nbsp;&lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只由小写字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况判断

若 $k = 1$，我们每次只能将字符串首字符移动到字符串末尾，总共有 $|s|$ 种不同的状态，我们返回其中字典序最小的字符串即可。

若 $k \gt 1$，对于形如 $abc[xy]def$ 的字符串，可以依次将 $a$, $b$, $c$ 移动到最后，得到 $[xy]defabc$，然后将 $y$, $x$ 移动到最后，得到 $defabc[yx]$，最后将 $d$, $e$, $f$ 移动到最后，得到 $abc[yx]def$，这样就实现了对 $y$, $x$ 的交换。

因此，只要 $k \gt 1$，我们就能够交换字符串中的任何两个相邻字符，最终得到一个升序排列的字符串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            ans = s
            for _ in range(len(s) - 1):
                s = s[1:] + s[0]
                ans = min(ans, s)
            return ans
        return "".join(sorted(s))
```

#### Java

```java
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String ans = s;
            StringBuilder sb = new StringBuilder(s);
            for (int i = 0; i < s.length() - 1; ++i) {
                sb.append(sb.charAt(0)).deleteCharAt(0);
                if (sb.toString().compareTo(ans) < 0) {
                    ans = sb.toString();
                }
            }
            return ans;
        }
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 0; i < s.size() - 1; ++i) {
                s = s.substr(1) + s[0];
                if (s < ans) ans = s;
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
```

#### Go

```go
func orderlyQueue(s string, k int) string {
	if k == 1 {
		ans := s
		for i := 0; i < len(s)-1; i++ {
			s = s[1:] + s[:1]
			if s < ans {
				ans = s
			}
		}
		return ans
	}
	t := []byte(s)
	sort.Slice(t, func(i, j int) bool { return t[i] < t[j] })
	return string(t)
}
```

#### TypeScript

```ts
function orderlyQueue(s: string, k: number): string {
    if (k > 1) {
        return [...s].sort().join('');
    }
    const n = s.length;
    let min = s;
    for (let i = 1; i < n; i++) {
        const t = s.slice(i) + s.slice(0, i);
        if (t < min) {
            min = t;
        }
    }
    return min;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
