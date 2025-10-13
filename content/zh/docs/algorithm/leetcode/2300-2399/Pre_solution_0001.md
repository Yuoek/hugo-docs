---
title: "2300_咒语和药水的成功对数"
date: 2025-10-08T18:39:12+08:00
weight: 1
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 图, 字符串, 字符串匹配, 并查集, 排序, 数据库, 数组, 枚举, 模拟, 深度优先搜索, 滑动窗口, 状态压缩, 矩阵]
---

{{< markmap >}}
### [2300_咒语和药水的成功对数](#2300)
#### [数组](#2300)
#### [双指针](#2300)
#### [二分查找](#2300)
#### [排序](#2300)
### [2301_替换字符后匹配](#2301)
#### [数组](#2301)
#### [哈希表](#2301)
#### [字符串](#2301)
#### [字符串匹配](#2301)
### [2302_统计得分小于 K 的子数组数目](#2302)
#### [数组](#2302)
#### [二分查找](#2302)
#### [前缀和](#2302)
#### [滑动窗口](#2302)
### [2303_计算应缴税款总额](#2303)
#### [数组](#2303)
#### [模拟](#2303)
### [2304_网格中的最小路径代价](#2304)
#### [数组](#2304)
#### [动态规划](#2304)
#### [矩阵](#2304)
### [2305_公平分发饼干](#2305)
#### [位运算](#2305)
#### [数组](#2305)
#### [动态规划](#2305)
#### [回溯](#2305)
#### [状态压缩](#2305)
### [2306_公司命名](#2306)
#### [位运算](#2306)
#### [数组](#2306)
#### [哈希表](#2306)
#### [字符串](#2306)
#### [枚举](#2306)
### [2307_检查方程中的矛盾之处 🔒](#2307)
#### [深度优先搜索](#2307)
#### [并查集](#2307)
#### [图](#2307)
#### [数组](#2307)
### [2308_按性别排列表格 🔒](#2308)
#### [数据库](#2308)
### [2309_兼具大小写的最好英文字母](#2309)
#### [哈希表](#2309)
#### [字符串](#2309)
#### [枚举](#2309)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2300_咒语和药水的成功对数
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2301_替换字符后匹配
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 字符串匹配
---
### 2302_统计得分小于 K 的子数组数目
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 2303_计算应缴税款总额
___
#### 数组
___
#### 模拟
---
### 2304_网格中的最小路径代价
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2305_公平分发饼干
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 2306_公司命名
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 枚举
---
### 2307_检查方程中的矛盾之处 🔒
___
#### 深度优先搜索
___
#### 并查集
___
#### 图
___
#### 数组
---
### 2308_按性别排列表格 🔒
___
#### 数据库
---
### 2309_兼具大小写的最好英文字母
___
#### 哈希表
___
#### 字符串
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 图 | 字符串 |
| 字符串匹配 | 并查集 | 排序 |
| 数据库 | 数组 | 枚举 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 状态压缩 | 矩阵 |  |

# [2300. 咒语和药水的成功对数](https://leetcode.cn/problems/successful-pairs-of-spells-and-potions){#2300}

{{< tabs "2300" >}}

{{% tab "python" %}}
```python
class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        m = len(potions)
        return [m - bisect_left(potions, success / v) for v in spells]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length, m = potions.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int left = 0, right = m;
            while (left < right) {
                int mid = (left + right) >> 1;
                if ((long) spells[i] * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = m - left;
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for (int& v : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / v) - potions.begin();
            ans.push_back(m - i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func successfulPairs(spells []int, potions []int, success int64) (ans []int) {
	sort.Ints(potions)
	m := len(potions)
	for _, v := range spells {
		i := sort.Search(m, func(i int) bool { return int64(potions[i]*v) >= success })
		ans = append(ans, m-i)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    potions.sort((a, b) => a - b);
    const m = potions.length;
    const ans: number[] = [];
    for (const v of spells) {
        let left = 0;
        let right = m;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (v * potions[mid] >= success) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans.push(m - left);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, mut potions: Vec<i32>, success: i64) -> Vec<i32> {
        potions.sort();
        let m = potions.len();

        spells.into_iter().map(|v| {
            let i = potions.binary_search_by(|&p| {
                let prod = (p as i64) * (v as i64);
                if prod >= success {
                    std::cmp::Ordering::Greater
                } else {
                    std::cmp::Ordering::Less
                }
            }).unwrap_or_else(|x| x);
            (m - i) as i32
        }).collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数数组&nbsp;<code>spells</code> 和&nbsp;<code>potions</code>&nbsp;，长度分别为&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;，其中&nbsp;<code>spells[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个咒语的能量强度，<code>potions[j]</code>&nbsp;表示第&nbsp;<code>j</code>&nbsp;瓶药水的能量强度。</p>

<p>同时给你一个整数&nbsp;<code>success</code>&nbsp;。一个咒语和药水的能量强度 <strong>相乘</strong> 如果&nbsp;<strong>大于等于</strong>&nbsp;<code>success</code>&nbsp;，那么它们视为一对&nbsp;<strong>成功</strong>&nbsp;的组合。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>pairs</code>，其中<em>&nbsp;</em><code>pairs[i]</code>&nbsp;是能跟第 <code>i</code>&nbsp;个咒语成功组合的 <b>药水</b>&nbsp;数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>spells = [5,1,3], potions = [1,2,3,4,5], success = 7
<b>输出：</b>[4,0,3]
<strong>解释：</strong>
- 第 0 个咒语：5 * [1,2,3,4,5] = [5,<em><strong>10</strong></em>,<em><strong>15</strong></em>,<em><strong>20</strong></em>,<em><strong>25</strong></em>] 。总共 4 个成功组合。
- 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
- 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,<em><strong>9</strong></em>,<em><strong>12</strong></em>,<em><strong>15</strong></em>] 。总共 3 个成功组合。
所以返回 [4,0,3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>spells = [3,1,2], potions = [8,5,8], success = 16
<b>输出：</b>[2,0,2]
<strong>解释：</strong>
- 第 0 个咒语：3 * [8,5,8] = [<em><strong>24</strong></em>,15,<em><strong>24</strong></em>] 。总共 2 个成功组合。
- 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
- 第 2 个咒语：2 * [8,5,8] = [<em><strong>16</strong></em>,10,<em><strong>16</strong></em>] 。总共 2 个成功组合。
所以返回 [2,0,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == spells.length</code></li>
	<li><code>m == potions.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= spells[i], potions[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= success &lt;= 10<sup>10</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以对药水数组进行排序，然后遍历咒语数组，对于每个咒语 $v$，利用二分查找找到第一个大于等于 $\frac{success}{v}$ 的药水，下标记为 $i$，那么药水的长度减去 $i$ 即为能跟该咒语成功组合的药水数目。

时间复杂度 $O((m + n) \times \log m)$，空间复杂度 $O(\log n)$。其中 $m$ 和 $n$ 分别为药水数组和咒语数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        m = len(potions)
        return [m - bisect_left(potions, success / v) for v in spells]
```

#### Java

```java
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length, m = potions.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int left = 0, right = m;
            while (left < right) {
                int mid = (left + right) >> 1;
                if ((long) spells[i] * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = m - left;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for (int& v : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / v) - potions.begin();
            ans.push_back(m - i);
        }
        return ans;
    }
};
```

#### Go

```go
func successfulPairs(spells []int, potions []int, success int64) (ans []int) {
	sort.Ints(potions)
	m := len(potions)
	for _, v := range spells {
		i := sort.Search(m, func(i int) bool { return int64(potions[i]*v) >= success })
		ans = append(ans, m-i)
	}
	return ans
}
```

#### TypeScript

```ts
function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    potions.sort((a, b) => a - b);
    const m = potions.length;
    const ans: number[] = [];
    for (const v of spells) {
        let left = 0;
        let right = m;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (v * potions[mid] >= success) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans.push(m - left);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, mut potions: Vec<i32>, success: i64) -> Vec<i32> {
        potions.sort();
        let m = potions.len();

        spells.into_iter().map(|v| {
            let i = potions.binary_search_by(|&p| {
                let prod = (p as i64) * (v as i64);
                if prod >= success {
                    std::cmp::Ordering::Greater
                } else {
                    std::cmp::Ordering::Less
                }
            }).unwrap_or_else(|x| x);
            (m - i) as i32
        }).collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2301. 替换字符后匹配](https://leetcode.cn/problems/match-substring-after-replacement){#2301}

{{< tabs "2301" >}}

{{% tab "python" %}}
```python
class Solution:
    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        d = [[False] * 128 for _ in range(128)]
        for a, b in mappings:
            d[ord(a)][ord(b)] = True
        for i in range(len(s) - len(sub) + 1):
            if all(
                a == b or d[ord(b)][ord(a)] for a, b in zip(s[i : i + len(sub)], sub)
            ):
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) {
        boolean[][] d = new boolean[128][128];
        for (var e : mappings) {
            d[e[0]][e[1]] = true;
        }
        int m = s.length(), n = sub.length();
        for (int i = 0; i < m - n + 1; ++i) {
            boolean ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s.charAt(i + j), b = sub.charAt(j);
                if (a != b && !d[b][a]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
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
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool d[128][128]{};
        for (auto& e : mappings) {
            d[e[0]][e[1]] = true;
        }
        int m = s.size(), n = sub.size();
        for (int i = 0; i < m - n + 1; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s[i + j], b = sub[j];
                if (a != b && !d[b][a]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matchReplacement(s string, sub string, mappings [][]byte) bool {
	d := [128][128]bool{}
	for _, e := range mappings {
		d[e[0]][e[1]] = true
	}
	for i := 0; i < len(s)-len(sub)+1; i++ {
		ok := true
		for j := 0; j < len(sub) && ok; j++ {
			a, b := s[i+j], sub[j]
			if a != b && !d[b][a] {
				ok = false
			}
		}
		if ok {
			return true
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>sub</code>&nbsp;。同时给你一个二维字符数组&nbsp;<code>mappings</code> ，其中&nbsp;<code>mappings[i] = [old<sub>i</sub>, new<sub>i</sub>]</code>&nbsp;表示你可以将&nbsp;<code>sub</code>&nbsp;中任意数目的&nbsp;<code>old<sub>i</sub></code>&nbsp;字符替换为&nbsp;<code>new<sub>i</sub></code>&nbsp;。<code>sub</code>&nbsp;中每个字符 <b>不能</b>&nbsp;被替换超过一次。</p>

<p>如果使用 <code>mappings</code>&nbsp;替换 0 个或者若干个字符，可以将 <code>sub</code>&nbsp;变成 <code>s</code>&nbsp;的一个子字符串，请你返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>一个 <strong>子字符串</strong>&nbsp;是字符串中连续非空的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "fool3e7bar", sub = "leet", mappings = [["e","3"],["t","7"],["t","8"]]
<b>输出：</b>true
<b>解释：</b>将 sub 中第一个 'e' 用 '3' 替换，将 't' 用 '7' 替换。
现在 sub = "l3e7" ，它是 s 的子字符串，所以我们返回 true 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "fooleetbar", sub = "f00l", mappings = [["o","0"]]
<b>输出：</b>false
<b>解释：</b>字符串 "f00l" 不是 s 的子串且没有可以进行的修改。
注意我们不能用 'o' 替换 '0' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "Fool33tbaR", sub = "leetd", mappings = [["e","3"],["t","7"],["t","8"],["d","b"],["p","b"]]
<b>输出：</b>true
<b>解释：</b>将 sub 里第一个和第二个 'e' 用 '3' 替换，用 'b' 替换 sub 里的 'd' 。
得到 sub = "l33tb" ，它是 s 的子字符串，所以我们返回 true 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sub.length &lt;= s.length &lt;= 5000</code></li>
	<li><code>0 &lt;= mappings.length &lt;= 1000</code></li>
	<li><code>mappings[i].length == 2</code></li>
	<li><code>old<sub>i</sub> != new<sub>i</sub></code></li>
	<li><code>s</code> 和&nbsp;<code>sub</code>&nbsp;只包含大写和小写英文字母和数字。</li>
	<li><code>old<sub>i</sub></code> 和&nbsp;<code>new<sub>i</sub></code>&nbsp;是大写、小写字母或者是个数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们先用哈希表 $d$ 记录每个字符可以替换成的字符集合。

然后我们枚举 $s$ 中所有长度为 $sub$ 长度的子串，判断字符串 $sub$ 是否可以通过替换得到该子串，如果可以则返回 `true`，否则枚举下一个子串。

枚举结束，说明 $sub$ 无法通过替换得到 $s$ 中的任何子串，返回 `false`。

时间复杂度 $O(m \times n)$，空间复杂度 $O(C^2)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $sub$ 的长度，而 $C$ 是字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        d = defaultdict(set)
        for a, b in mappings:
            d[a].add(b)
        for i in range(len(s) - len(sub) + 1):
            if all(a == b or a in d[b] for a, b in zip(s[i : i + len(sub)], sub)):
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) {
        Map<Character, Set<Character>> d = new HashMap<>();
        for (var e : mappings) {
            d.computeIfAbsent(e[0], k -> new HashSet<>()).add(e[1]);
        }
        int m = s.length(), n = sub.length();
        for (int i = 0; i < m - n + 1; ++i) {
            boolean ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s.charAt(i + j), b = sub.charAt(j);
                if (a != b && !d.getOrDefault(b, Collections.emptySet()).contains(a)) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
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
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> d;
        for (auto& e : mappings) {
            d[e[0]].insert(e[1]);
        }
        int m = s.size(), n = sub.size();
        for (int i = 0; i < m - n + 1; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s[i + j], b = sub[j];
                if (a != b && !d[b].count(a)) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func matchReplacement(s string, sub string, mappings [][]byte) bool {
	d := map[byte]map[byte]bool{}
	for _, e := range mappings {
		if d[e[0]] == nil {
			d[e[0]] = map[byte]bool{}
		}
		d[e[0]][e[1]] = true
	}
	for i := 0; i < len(s)-len(sub)+1; i++ {
		ok := true
		for j := 0; j < len(sub) && ok; j++ {
			a, b := s[i+j], sub[j]
			if a != b && !d[b][a] {
				ok = false
			}
		}
		if ok {
			return true
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数组 + 枚举

由于字符集只包含大写和小写英文字母和数字，因此我们可以直接用一个 $128 \times 128$ 的数组 $d$ 记录每个字符可以替换成的字符集合。

时间复杂度 $O(m \times n)$，空间复杂度 $O(C^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        d = [[False] * 128 for _ in range(128)]
        for a, b in mappings:
            d[ord(a)][ord(b)] = True
        for i in range(len(s) - len(sub) + 1):
            if all(
                a == b or d[ord(b)][ord(a)] for a, b in zip(s[i : i + len(sub)], sub)
            ):
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) {
        boolean[][] d = new boolean[128][128];
        for (var e : mappings) {
            d[e[0]][e[1]] = true;
        }
        int m = s.length(), n = sub.length();
        for (int i = 0; i < m - n + 1; ++i) {
            boolean ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s.charAt(i + j), b = sub.charAt(j);
                if (a != b && !d[b][a]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
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
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool d[128][128]{};
        for (auto& e : mappings) {
            d[e[0]][e[1]] = true;
        }
        int m = s.size(), n = sub.size();
        for (int i = 0; i < m - n + 1; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s[i + j], b = sub[j];
                if (a != b && !d[b][a]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func matchReplacement(s string, sub string, mappings [][]byte) bool {
	d := [128][128]bool{}
	for _, e := range mappings {
		d[e[0]][e[1]] = true
	}
	for i := 0; i < len(s)-len(sub)+1; i++ {
		ok := true
		for j := 0; j < len(sub) && ok; j++ {
			a, b := s[i+j], sub[j]
			if a != b && !d[b][a] {
				ok = false
			}
		}
		if ok {
			return true
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2302. 统计得分小于 K 的子数组数目](https://leetcode.cn/problems/count-subarrays-with-score-less-than-k){#2302}

{{< tabs "2302" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = s = j = 0
        for i, x in enumerate(nums):
            s += x
            while s * (i - j + 1) >= k:
                s -= nums[j]
                j += 1
            ans += i - j + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0, s = 0;
        for (int i = 0, j = 0; i < nums.length; ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j++];
            }
            ans += i - j + 1;
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
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, s = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j++];
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int, k int64) (ans int64) {
	s, j := 0, 0
	for i, x := range nums {
		s += x
		for int64(s*(i-j+1)) >= k {
			s -= nums[j]
			j++
		}
		ans += int64(i - j + 1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[], k: number): number {
    let [ans, s, j] = [0, 0, 0];
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        while (s * (i - j + 1) >= k) {
            s -= nums[j++];
        }
        ans += i - j + 1;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let mut ans = 0i64;
        let mut s = 0i64;
        let mut j = 0;

        for i in 0..nums.len() {
            s += nums[i] as i64;
            while s * (i as i64 - j as i64 + 1) >= k {
                s -= nums[j] as i64;
                j += 1;
            }
            ans += i as i64 - j as i64 + 1;
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

<p>一个数组的 <strong>分数</strong>&nbsp;定义为数组之和 <strong>乘以</strong>&nbsp;数组的长度。</p>

<ul>
	<li>比方说，<code>[1, 2, 3, 4, 5]</code>&nbsp;的分数为&nbsp;<code>(1 + 2 + 3 + 4 + 5) * 5 = 75</code>&nbsp;。</li>
</ul>

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回&nbsp;<code>nums</code>&nbsp;中分数&nbsp;<strong>严格小于&nbsp;</strong><code>k</code>&nbsp;的&nbsp;<strong>非空整数子数组数目</strong>。</p>

<p><strong>子数组</strong> 是数组中的一个连续元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4,3,5], k = 10
<b>输出：</b>6
<strong>解释：</strong>
有 6 个子数组的分数小于 10 ：
- [2] 分数为 2 * 1 = 2 。
- [1] 分数为 1 * 1 = 1 。
- [4] 分数为 4 * 1 = 4 。
- [3] 分数为 3 * 1 = 3 。 
- [5] 分数为 5 * 1 = 5 。
- [2,1] 分数为 (2 + 1) * 2 = 6 。
注意，子数组 [1,4] 和 [4,3,5] 不符合要求，因为它们的分数分别为 10 和 36，但我们要求子数组的分数严格小于 10 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1], k = 5
<b>输出：</b>5
<strong>解释：</strong>
除了 [1,1,1] 以外每个子数组分数都小于 5 。
[1,1,1] 分数为 (1 + 1 + 1) * 3 = 9 ，大于 5 。
所以总共有 5 个子数组得分小于 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 二分查找

我们先计算出数组 $\textit{nums}$ 的前缀和数组 $s$，其中 $s[i]$ 表示数组 $\textit{nums}$ 前 $i$ 个元素的和。

接下来，我们枚举数组 $\textit{nums}$ 每个元素作为子数组的最后一个元素，对于每个元素，我们可以通过二分查找的方式找到最大的长度 $l$，使得 $s[i] - s[i - l] \times l < k$。那么以该元素为最后一个元素的子数组个数即为 $l$，我们将所有的 $l$ 相加即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        s = list(accumulate(nums, initial=0))
        ans = 0
        for i in range(1, len(s)):
            l, r = 0, i
            while l < r:
                mid = (l + r + 1) >> 1
                if (s[i] - s[i - mid]) * mid < k:
                    l = mid
                else:
                    r = mid - 1
            ans += l
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if ((s[i] - s[i - mid]) * mid < k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans += l;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if ((s[i] - s[i - mid]) * mid < k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans += l;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, k int64) (ans int64) {
	n := len(nums)
	s := make([]int64, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + int64(x)
	}
	for i := 1; i <= n; i++ {
		l, r := 0, i
		for l < r {
			mid := (l + r + 1) >> 1
			if (s[i]-s[i-mid])*int64(mid) < k {
				l = mid
			} else {
				r = mid - 1
			}
		}
		ans += int64(l)
	}
	return
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], k: number): number {
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        let [l, r] = [0, i];
        while (l < r) {
            const mid = (l + r + 1) >> 1;
            if ((s[i] - s[i - mid]) * mid < k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let n = nums.len();
        let mut s = vec![0i64; n + 1];
        for i in 0..n {
            s[i + 1] = s[i] + nums[i] as i64;
        }
        let mut ans = 0i64;
        for i in 1..=n {
            let mut l = 0;
            let mut r = i;
            while l < r {
                let mid = (l + r + 1) / 2;
                let sum = s[i] - s[i - mid];
                if sum * (mid as i64) < k {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans += l as i64;
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

我们可以使用双指针的方式，维护一个滑动窗口，使得窗口内的元素和小于 $k$。那么以当前元素为最后一个元素的子数组个数即为窗口的长度，我们将所有的窗口长度相加即为答案。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = s = j = 0
        for i, x in enumerate(nums):
            s += x
            while s * (i - j + 1) >= k:
                s -= nums[j]
                j += 1
            ans += i - j + 1
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0, s = 0;
        for (int i = 0, j = 0; i < nums.length; ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j++];
            }
            ans += i - j + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, s = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j++];
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, k int64) (ans int64) {
	s, j := 0, 0
	for i, x := range nums {
		s += x
		for int64(s*(i-j+1)) >= k {
			s -= nums[j]
			j++
		}
		ans += int64(i - j + 1)
	}
	return
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], k: number): number {
    let [ans, s, j] = [0, 0, 0];
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        while (s * (i - j + 1) >= k) {
            s -= nums[j++];
        }
        ans += i - j + 1;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let mut ans = 0i64;
        let mut s = 0i64;
        let mut j = 0;

        for i in 0..nums.len() {
            s += nums[i] as i64;
            while s * (i as i64 - j as i64 + 1) >= k {
                s -= nums[j] as i64;
                j += 1;
            }
            ans += i as i64 - j as i64 + 1;
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

# [2303. 计算应缴税款总额](https://leetcode.cn/problems/calculate-amount-paid-in-taxes){#2303}

{{< tabs "2303" >}}

{{% tab "python" %}}
```python
class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans = prev = 0
        for upper, percent in brackets:
            ans += max(0, min(income, upper) - prev) * percent
            prev = upper
        return ans / 100
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        int ans = 0, prev = 0;
        for (var e : brackets) {
            int upper = e[0], percent = e[1];
            ans += Math.max(0, Math.min(income, upper) - prev) * percent;
            prev = upper;
        }
        return ans / 100.0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0, prev = 0;
        for (auto& e : brackets) {
            int upper = e[0], percent = e[1];
            ans += max(0, min(income, upper) - prev) * percent;
            prev = upper;
        }
        return ans / 100.0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func calculateTax(brackets [][]int, income int) float64 {
	var ans, prev int
	for _, e := range brackets {
		upper, percent := e[0], e[1]
		ans += max(0, min(income, upper)-prev) * percent
		prev = upper
	}
	return float64(ans) / 100.0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function calculateTax(brackets: number[][], income: number): number {
    let ans = 0;
    let prev = 0;
    for (const [upper, percent] of brackets) {
        ans += Math.max(0, Math.min(income, upper) - prev) * percent;
        prev = upper;
    }
    return ans / 100;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn calculate_tax(brackets: Vec<Vec<i32>>, income: i32) -> f64 {
        let mut res = 0f64;
        let mut pre = 0i32;
        for bracket in brackets.iter() {
            res += f64::from(income.min(bracket[0]) - pre) * f64::from(bracket[1]) * 0.01;
            if income <= bracket[0] {
                break;
            }
            pre = bracket[0];
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>brackets</code> ，其中 <code>brackets[i] = [upper<sub>i</sub>, percent<sub>i</sub>]</code> ，表示第 <code>i</code> 个税级的上限是 <code>upper<sub>i</sub></code> ，征收的税率为 <code>percent<sub>i</sub></code> 。税级按上限 <strong>从低到高排序</strong>（在满足 <code>0 &lt; i &lt; brackets.length</code> 的前提下，<code>upper<sub>i-1</sub> &lt; upper<sub>i</sub></code>）。</p>

<p>税款计算方式如下：</p>

<ul>
	<li>不超过 <code>upper<sub>0</sub></code> 的收入按税率 <code>percent<sub>0</sub></code> 缴纳</li>
	<li>接着 <code>upper<sub>1</sub> - upper<sub>0</sub></code> 的部分按税率 <code>percent<sub>1</sub></code> 缴纳</li>
	<li>然后 <code>upper<sub>2</sub> - upper<sub>1</sub></code> 的部分按税率 <code>percent<sub>2</sub></code> 缴纳</li>
	<li>以此类推</li>
</ul>

<p>给你一个整数 <code>income</code> 表示你的总收入。返回你需要缴纳的税款总额。与标准答案误差不超 <code>10<sup>-5</sup></code> 的结果将被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>brackets = [[3,50],[7,10],[12,25]], income = 10
<strong>输出：</strong>2.65000
<strong>解释：</strong>
前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>brackets = [[1,0],[4,25],[5,50]], income = 2
<strong>输出：</strong>0.25000
<strong>解释：</strong>
前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
需要支付的税款总计 $0 + $0.25 = $0.25 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>brackets = [[2,50]], income = 0
<strong>输出：</strong>0.00000
<strong>解释：</strong>
没有收入，无需纳税，需要支付的税款总计 $0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= brackets.length &lt;= 100</code></li>
	<li><code>1 &lt;= upper<sub>i</sub> &lt;= 1000</code></li>
	<li><code>0 &lt;= percent<sub>i</sub> &lt;= 100</code></li>
	<li><code>0 &lt;= income &lt;= 1000</code></li>
	<li><code>upper<sub>i</sub></code> 按递增顺序排列</li>
	<li><code>upper<sub>i</sub></code> 中的所有值 <strong>互不相同</strong></li>
	<li>最后一个税级的上限大于等于 <code>income</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历 `brackets`，对于每个税级，计算该税级的税额，然后累加即可。

时间复杂度 $O(n)$，其中 $n$ 为 `brackets` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans = prev = 0
        for upper, percent in brackets:
            ans += max(0, min(income, upper) - prev) * percent
            prev = upper
        return ans / 100
```

#### Java

```java
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        int ans = 0, prev = 0;
        for (var e : brackets) {
            int upper = e[0], percent = e[1];
            ans += Math.max(0, Math.min(income, upper) - prev) * percent;
            prev = upper;
        }
        return ans / 100.0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0, prev = 0;
        for (auto& e : brackets) {
            int upper = e[0], percent = e[1];
            ans += max(0, min(income, upper) - prev) * percent;
            prev = upper;
        }
        return ans / 100.0;
    }
};
```

#### Go

```go
func calculateTax(brackets [][]int, income int) float64 {
	var ans, prev int
	for _, e := range brackets {
		upper, percent := e[0], e[1]
		ans += max(0, min(income, upper)-prev) * percent
		prev = upper
	}
	return float64(ans) / 100.0
}
```

#### TypeScript

```ts
function calculateTax(brackets: number[][], income: number): number {
    let ans = 0;
    let prev = 0;
    for (const [upper, percent] of brackets) {
        ans += Math.max(0, Math.min(income, upper) - prev) * percent;
        prev = upper;
    }
    return ans / 100;
}
```

#### Rust

```rust
impl Solution {
    pub fn calculate_tax(brackets: Vec<Vec<i32>>, income: i32) -> f64 {
        let mut res = 0f64;
        let mut pre = 0i32;
        for bracket in brackets.iter() {
            res += f64::from(income.min(bracket[0]) - pre) * f64::from(bracket[1]) * 0.01;
            if income <= bracket[0] {
                break;
            }
            pre = bracket[0];
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2304. 网格中的最小路径代价](https://leetcode.cn/problems/minimum-path-cost-in-a-grid){#2304}

{{< tabs "2304" >}}

{{% tab "python" %}}
```python
class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = grid[0]
        for i in range(1, m):
            g = [inf] * n
            for j in range(n):
                for k in range(n):
                    g[j] = min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j])
            f = g
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int m = grid.length, n = grid[0].length;
        int[] f = grid[0];
        final int inf = 1 << 30;
        for (int i = 1; i < m; ++i) {
            int[] g = new int[n];
            Arrays.fill(g, inf);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[j] = Math.min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
            f = g;
        }

        // return Arrays.stream(f).min().getAsInt();
        int ans = inf;
        for (int v : f) {
            ans = Math.min(ans, v);
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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        const int inf = 1 << 30;
        vector<int> f = grid[0];
        for (int i = 1; i < m; ++i) {
            vector<int> g(n, inf);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[j] = min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minPathCost(grid [][]int, moveCost [][]int) int {
	m, n := len(grid), len(grid[0])
	f := grid[0]
	for i := 1; i < m; i++ {
		g := make([]int, n)
		for j := 0; j < n; j++ {
			g[j] = 1 << 30
			for k := 0; k < n; k++ {
				g[j] = min(g[j], f[k]+moveCost[grid[i-1][k]][j]+grid[i][j])
			}
		}
		f = g
	}
	return slices.Min(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minPathCost(grid: number[][], moveCost: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f = grid[0];
    for (let i = 1; i < m; ++i) {
        const g: number[] = Array(n).fill(Infinity);
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < n; ++k) {
                g[j] = Math.min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
            }
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_path_cost(grid: Vec<Vec<i32>>, move_cost: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut f = grid[0].clone();

        for i in 1..m {
            let mut g: Vec<i32> = vec![i32::MAX; n];
            for j in 0..n {
                for k in 0..n {
                    g[j] = g[j].min(f[k] + move_cost[grid[i - 1][k] as usize][j] + grid[i][j]);
                }
            }
            f.copy_from_slice(&g);
        }

        f.iter().cloned().min().unwrap_or(0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数矩阵&nbsp;<code>grid</code> ，矩阵大小为 <code>m x n</code> ，由从 <code>0</code> 到 <code>m * n - 1</code> 的不同整数组成。你可以在此矩阵中，从一个单元格移动到 <strong>下一行</strong> 的任何其他单元格。如果你位于单元格 <code>(x, y)</code> ，且满足 <code>x &lt; m - 1</code> ，你可以移动到 <code>(x + 1, 0)</code>, <code>(x + 1, 1)</code>, ..., <code>(x + 1, n - 1)</code><strong> </strong>中的任何一个单元格。<strong>注意：</strong>&nbsp;在最后一行中的单元格不能触发移动。</p>

<p>每次可能的移动都需要付出对应的代价，代价用一个下标从 <strong>0</strong> 开始的二维数组 <code>moveCost</code> 表示，该数组大小为 <code>(m * n) x n</code> ，其中 <code>moveCost[i][j]</code> 是从值为 <code>i</code> 的单元格移动到下一行第 <code>j</code> 列单元格的代价。从&nbsp;<code>grid</code> 最后一行的单元格移动的代价可以忽略。</p>

<p><code>grid</code> 一条路径的代价是：所有路径经过的单元格的 <strong>值之和</strong> 加上 所有移动的 <strong>代价之和 </strong>。从 <strong>第一行</strong> 任意单元格出发，返回到达 <strong>最后一行</strong> 任意单元格的最小路径代价<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2304.Minimum%20Path%20Cost%20in%20a%20Grid/images/griddrawio-2.png" style="width: 301px; height: 281px;" /></p>

<pre>
<strong>输入：</strong>grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
<strong>输出：</strong>17
<strong>解释：</strong>最小代价的路径是 5 -&gt; 0 -&gt; 1 。
- 路径途经单元格值之和 5 + 0 + 1 = 6 。
- 从 5 移动到 0 的代价为 3 。
- 从 0 移动到 1 的代价为 8 。
路径总代价为 6 + 3 + 8 = 17 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]
<strong>输出：</strong>6
<strong>解释：</strong>
最小代价的路径是 2 -&gt; 3 。 
- 路径途经单元格值之和 2 + 3 = 5 。 
- 从 2 移动到 3 的代价为 1 。 
路径总代价为 5 + 1 = 6 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid</code> 由从 <code>0</code> 到 <code>m * n - 1</code> 的不同整数组成</li>
	<li><code>moveCost.length == m * n</code></li>
	<li><code>moveCost[i].length == n</code></li>
	<li><code>1 &lt;= moveCost[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从第一行出发，到达第 $i$ 行第 $j$ 列的最小路径代价。由于每次只能从上一行的某一列移动到当前行的某一列，因此 $f[i][j]$ 的值可以从 $f[i - 1][k]$ 转移而来，其中 $k$ 的取值范围为 $[0, n - 1]$。因此状态转移方程为：

$$
f[i][j] = \min_{0 \leq k < n} \{f[i - 1][k] + \textit{moveCost}[grid[i - 1][k]][j] + grid[i][j]\}
$$

其中 $\textit{moveCost}[grid[i - 1][k]][j]$ 表示从第 $i - 1$ 行第 $k$ 列移动到第 $i$ 行第 $j$ 列的代价。

最终答案即为 $\min_{0 \leq j < n} \{f[m - 1][j]\}$。

由于每次转移只需要用到上一行的状态，因此我们可以使用滚动数组的方式，将空间复杂度优化到 $O(n)$。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = grid[0]
        for i in range(1, m):
            g = [inf] * n
            for j in range(n):
                for k in range(n):
                    g[j] = min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j])
            f = g
        return min(f)
```

#### Java

```java
class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int m = grid.length, n = grid[0].length;
        int[] f = grid[0];
        final int inf = 1 << 30;
        for (int i = 1; i < m; ++i) {
            int[] g = new int[n];
            Arrays.fill(g, inf);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[j] = Math.min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
            f = g;
        }

        // return Arrays.stream(f).min().getAsInt();
        int ans = inf;
        for (int v : f) {
            ans = Math.min(ans, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        const int inf = 1 << 30;
        vector<int> f = grid[0];
        for (int i = 1; i < m; ++i) {
            vector<int> g(n, inf);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    g[j] = min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func minPathCost(grid [][]int, moveCost [][]int) int {
	m, n := len(grid), len(grid[0])
	f := grid[0]
	for i := 1; i < m; i++ {
		g := make([]int, n)
		for j := 0; j < n; j++ {
			g[j] = 1 << 30
			for k := 0; k < n; k++ {
				g[j] = min(g[j], f[k]+moveCost[grid[i-1][k]][j]+grid[i][j])
			}
		}
		f = g
	}
	return slices.Min(f)
}
```

#### TypeScript

```ts
function minPathCost(grid: number[][], moveCost: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f = grid[0];
    for (let i = 1; i < m; ++i) {
        const g: number[] = Array(n).fill(Infinity);
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < n; ++k) {
                g[j] = Math.min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
            }
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_path_cost(grid: Vec<Vec<i32>>, move_cost: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut f = grid[0].clone();

        for i in 1..m {
            let mut g: Vec<i32> = vec![i32::MAX; n];
            for j in 0..n {
                for k in 0..n {
                    g[j] = g[j].min(f[k] + move_cost[grid[i - 1][k] as usize][j] + grid[i][j]);
                }
            }
            f.copy_from_slice(&g);
        }

        f.iter().cloned().min().unwrap_or(0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2305. 公平分发饼干](https://leetcode.cn/problems/fair-distribution-of-cookies){#2305}

{{< tabs "2305" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        def dfs(i):
            if i >= len(cookies):
                nonlocal ans
                ans = max(cnt)
                return
            for j in range(k):
                if cnt[j] + cookies[i] >= ans or (j and cnt[j] == cnt[j - 1]):
                    continue
                cnt[j] += cookies[i]
                dfs(i + 1)
                cnt[j] -= cookies[i]

        ans = inf
        cnt = [0] * k
        cookies.sort(reverse=True)
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] cookies;
    private int[] cnt;
    private int k;
    private int n;
    private int ans = 1 << 30;

    public int distributeCookies(int[] cookies, int k) {
        n = cookies.length;
        cnt = new int[k];
        // 升序排列
        Arrays.sort(cookies);
        this.cookies = cookies;
        this.k = k;
        // 这里搜索顺序是 n-1, n-2,...0
        dfs(n - 1);
        return ans;
    }

    private void dfs(int i) {
        if (i < 0) {
            // ans = Arrays.stream(cnt).max().getAsInt();
            ans = 0;
            for (int v : cnt) {
                ans = Math.max(ans, v);
            }
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + cookies[i] >= ans || (j > 0 && cnt[j] == cnt[j - 1])) {
                continue;
            }
            cnt[j] += cookies[i];
            dfs(i - 1);
            cnt[j] -= cookies[i];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.rbegin(), cookies.rend());
        int cnt[k];
        memset(cnt, 0, sizeof cnt);
        int n = cookies.size();
        int ans = 1 << 30;
        function<void(int)> dfs = [&](int i) {
            if (i >= n) {
                ans = *max_element(cnt, cnt + k);
                return;
            }
            for (int j = 0; j < k; ++j) {
                if (cnt[j] + cookies[i] >= ans || (j && cnt[j] == cnt[j - 1])) {
                    continue;
                }
                cnt[j] += cookies[i];
                dfs(i + 1);
                cnt[j] -= cookies[i];
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCookies(cookies []int, k int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cookies)))
	cnt := make([]int, k)
	ans := 1 << 30
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(cookies) {
			ans = slices.Max(cnt)
			return
		}
		for j := 0; j < k; j++ {
			if cnt[j]+cookies[i] >= ans || (j > 0 && cnt[j] == cnt[j-1]) {
				continue
			}
			cnt[j] += cookies[i]
			dfs(i + 1)
			cnt[j] -= cookies[i]
		}
	}
	dfs(0)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCookies(cookies: number[], k: number): number {
    const cnt = new Array(k).fill(0);
    let ans = 1 << 30;
    const dfs = (i: number) => {
        if (i >= cookies.length) {
            ans = Math.max(...cnt);
            return;
        }
        for (let j = 0; j < k; ++j) {
            if (cnt[j] + cookies[i] >= ans || (j && cnt[j] == cnt[j - 1])) {
                continue;
            }
            cnt[j] += cookies[i];
            dfs(i + 1);
            cnt[j] -= cookies[i];
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>cookies</code> ，其中 <code>cookies[i]</code> 表示在第 <code>i</code> 个零食包中的饼干数量。另给你一个整数 <code>k</code> 表示等待分发零食包的孩子数量，<strong>所有</strong> 零食包都需要分发。在同一个零食包中的所有饼干都必须分发给同一个孩子，不能分开。</p>

<p>分发的 <strong>不公平程度</strong> 定义为单个孩子在分发过程中能够获得饼干的最大总数。</p>

<p>返回所有分发的最小不公平程度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cookies = [8,15,10,20,8], k = 2
<strong>输出：</strong>31
<strong>解释：</strong>一种最优方案是 [8,15,8] 和 [10,20] 。
- 第 1 个孩子分到 [8,15,8] ，总计 8 + 15 + 8 = 31 块饼干。
- 第 2 个孩子分到 [10,20] ，总计 10 + 20 = 30 块饼干。
分发的不公平程度为 max(31,30) = 31 。
可以证明不存在不公平程度小于 31 的分发方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cookies = [6,1,3,2,2,4,1,2], k = 3
<strong>输出：</strong>7
<strong>解释：</strong>一种最优方案是 [6,1]、[3,2,2] 和 [4,1,2] 。
- 第 1 个孩子分到 [6,1] ，总计 6 + 1 = 7 块饼干。 
- 第 2 个孩子分到 [3,2,2] ，总计 3 + 2 + 2 = 7 块饼干。
- 第 3 个孩子分到 [4,1,2] ，总计 4 + 1 + 2 = 7 块饼干。
分发的不公平程度为 max(7,7,7) = 7 。
可以证明不存在不公平程度小于 7 的分发方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= cookies.length &lt;= 8</code></li>
	<li><code>1 &lt;= cookies[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= k &lt;= cookies.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯 + 剪枝

我们先对数组 $cookies$ 进行降序排序（减少搜索次数），然后创建一个长度为 $k$ 的数组 $cnt$，用于存储每个孩子分到的饼干数量。另外，用变量 $ans$ 维护当前的最小不公平程度，初始化一个很大的值。

接下来，我们从第一个零食包开始，对于当前零食包 $i$，我们枚举每个孩子 $j$，如果当前零食包中的饼干 $cookies[i]$ 分给孩子 $j$ 后，使得不公平程度大于等于 $ans$，或者当前孩子已有的饼干数量与前一个孩子相同，那么我们不需要考虑将当前零食包中的饼干分给孩子 $j$，直接跳过（剪枝）。否则，我们将当前零食包中的饼干 $cookies[i]$ 分给孩子 $j$，然后继续考虑下一个零食包。当我们考虑完所有的零食包后，更新 $ans$ 的值，然后回溯到上一个零食包，继续枚举当前零食包中的饼干分给哪个孩子。

最后，我们返回 $ans$ 即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        def dfs(i):
            if i >= len(cookies):
                nonlocal ans
                ans = max(cnt)
                return
            for j in range(k):
                if cnt[j] + cookies[i] >= ans or (j and cnt[j] == cnt[j - 1]):
                    continue
                cnt[j] += cookies[i]
                dfs(i + 1)
                cnt[j] -= cookies[i]

        ans = inf
        cnt = [0] * k
        cookies.sort(reverse=True)
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private int[] cookies;
    private int[] cnt;
    private int k;
    private int n;
    private int ans = 1 << 30;

    public int distributeCookies(int[] cookies, int k) {
        n = cookies.length;
        cnt = new int[k];
        // 升序排列
        Arrays.sort(cookies);
        this.cookies = cookies;
        this.k = k;
        // 这里搜索顺序是 n-1, n-2,...0
        dfs(n - 1);
        return ans;
    }

    private void dfs(int i) {
        if (i < 0) {
            // ans = Arrays.stream(cnt).max().getAsInt();
            ans = 0;
            for (int v : cnt) {
                ans = Math.max(ans, v);
            }
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + cookies[i] >= ans || (j > 0 && cnt[j] == cnt[j - 1])) {
                continue;
            }
            cnt[j] += cookies[i];
            dfs(i - 1);
            cnt[j] -= cookies[i];
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.rbegin(), cookies.rend());
        int cnt[k];
        memset(cnt, 0, sizeof cnt);
        int n = cookies.size();
        int ans = 1 << 30;
        function<void(int)> dfs = [&](int i) {
            if (i >= n) {
                ans = *max_element(cnt, cnt + k);
                return;
            }
            for (int j = 0; j < k; ++j) {
                if (cnt[j] + cookies[i] >= ans || (j && cnt[j] == cnt[j - 1])) {
                    continue;
                }
                cnt[j] += cookies[i];
                dfs(i + 1);
                cnt[j] -= cookies[i];
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func distributeCookies(cookies []int, k int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cookies)))
	cnt := make([]int, k)
	ans := 1 << 30
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(cookies) {
			ans = slices.Max(cnt)
			return
		}
		for j := 0; j < k; j++ {
			if cnt[j]+cookies[i] >= ans || (j > 0 && cnt[j] == cnt[j-1]) {
				continue
			}
			cnt[j] += cookies[i]
			dfs(i + 1)
			cnt[j] -= cookies[i]
		}
	}
	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function distributeCookies(cookies: number[], k: number): number {
    const cnt = new Array(k).fill(0);
    let ans = 1 << 30;
    const dfs = (i: number) => {
        if (i >= cookies.length) {
            ans = Math.max(...cnt);
            return;
        }
        for (let j = 0; j < k; ++j) {
            if (cnt[j] + cookies[i] >= ans || (j && cnt[j] == cnt[j - 1])) {
                continue;
            }
            cnt[j] += cookies[i];
            dfs(i + 1);
            cnt[j] -= cookies[i];
        }
    };
    dfs(0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2306. 公司命名](https://leetcode.cn/problems/naming-a-company){#2306}

{{< tabs "2306" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        s = set(ideas)
        f = [[0] * 26 for _ in range(26)]
        for v in ideas:
            i = ord(v[0]) - ord('a')
            t = list(v)
            for j in range(26):
                t[0] = chr(ord('a') + j)
                if ''.join(t) not in s:
                    f[i][j] += 1
        ans = 0
        for v in ideas:
            i = ord(v[0]) - ord('a')
            t = list(v)
            for j in range(26):
                t[0] = chr(ord('a') + j)
                if ''.join(t) not in s:
                    ans += f[j][i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long distinctNames(String[] ideas) {
        Set<String> s = new HashSet<>();
        for (String v : ideas) {
            s.add(v);
        }
        int[][] f = new int[26][26];
        for (String v : ideas) {
            char[] t = v.toCharArray();
            int i = t[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                t[0] = (char) (j + 'a');
                if (!s.contains(String.valueOf(t))) {
                    ++f[i][j];
                }
            }
        }
        long ans = 0;
        for (String v : ideas) {
            char[] t = v.toCharArray();
            int i = t[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                t[0] = (char) (j + 'a');
                if (!s.contains(String.valueOf(t))) {
                    ans += f[j][i];
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
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s(ideas.begin(), ideas.end());
        int f[26][26]{};
        for (auto v : ideas) {
            int i = v[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                v[0] = j + 'a';
                if (!s.count(v)) {
                    ++f[i][j];
                }
            }
        }
        long long ans = 0;
        for (auto& v : ideas) {
            int i = v[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                v[0] = j + 'a';
                if (!s.count(v)) {
                    ans += f[j][i];
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
func distinctNames(ideas []string) (ans int64) {
	s := map[string]bool{}
	for _, v := range ideas {
		s[v] = true
	}
	f := [26][26]int{}
	for _, v := range ideas {
		i := int(v[0] - 'a')
		t := []byte(v)
		for j := 0; j < 26; j++ {
			t[0] = 'a' + byte(j)
			if !s[string(t)] {
				f[i][j]++
			}
		}
	}

	for _, v := range ideas {
		i := int(v[0] - 'a')
		t := []byte(v)
		for j := 0; j < 26; j++ {
			t[0] = 'a' + byte(j)
			if !s[string(t)] {
				ans += int64(f[j][i])
			}
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

<p>给你一个字符串数组 <code>ideas</code> 表示在公司命名过程中使用的名字列表。公司命名流程如下：</p>

<ol>
	<li>从 <code>ideas</code> 中选择 2 个 <strong>不同</strong> 名字，称为 <code>idea<sub>A</sub></code> 和 <code>idea<sub>B</sub></code> 。</li>
	<li>交换 <code>idea<sub>A</sub></code> 和 <code>idea<sub>B</sub></code> 的首字母。</li>
	<li>如果得到的两个新名字 <strong>都</strong> 不在 <code>ideas</code> 中，那么 <code>idea<sub>A</sub> idea<sub>B</sub></code>（<strong>串联</strong> <code>idea<sub>A</sub></code> 和 <code>idea<sub>B</sub></code> ，中间用一个空格分隔）是一个有效的公司名字。</li>
	<li>否则，不是一个有效的名字。</li>
</ol>

<p>返回 <strong>不同</strong> 且有效的公司名字的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>ideas = ["coffee","donuts","time","toffee"]
<strong>输出：</strong>6
<strong>解释：</strong>下面列出一些有效的选择方案：
- ("coffee", "donuts")：对应的公司名字是 "doffee conuts" 。
- ("donuts", "coffee")：对应的公司名字是 "conuts doffee" 。
- ("donuts", "time")：对应的公司名字是 "tonuts dime" 。
- ("donuts", "toffee")：对应的公司名字是 "tonuts doffee" 。
- ("time", "donuts")：对应的公司名字是 "dime tonuts" 。
- ("toffee", "donuts")：对应的公司名字是 "doffee tonuts" 。
因此，总共有 6 个不同的公司名字。

下面列出一些无效的选择方案：
- ("coffee", "time")：在原数组中存在交换后形成的名字 "toffee" 。
- ("time", "toffee")：在原数组中存在交换后形成的两个名字。
- ("coffee", "toffee")：在原数组中存在交换后形成的两个名字。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>ideas = ["lack","back"]
<strong>输出：</strong>0
<strong>解释：</strong>不存在有效的选择方案。因此，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= ideas.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ideas[i].length &lt;= 10</code></li>
	<li><code>ideas[i]</code> 由小写英文字母组成</li>
	<li><code>ideas</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举计数

我们定义 $f[i][j]$ 表示 $\textit{ideas}$ 中以第 $i$ 个字母开头，替换为第 $j$ 个字母后，不在 $\textit{ideas}$ 中的字符串的个数。初始时 $f[i][j] = 0$。另外，用一个哈希表 $s$ 记录 $\textit{ideas}$ 中的字符串，方便我们快速判断某个字符串是否在 $\textit{ideas}$ 中。

接下来，我们遍历 $\textit{ideas}$ 中字符串，对于当前遍历到的字符串 $v$，我们枚举替换后的第一个字母 $j$，如果 $v$ 替换后的字符串不在 $\textit{ideas}$ 中，那么我们就更新 $f[i][j] = f[i][j] + 1$。

最后，我们再次遍历 $\textit{ideas}$ 中字符串，对于当前遍历到的字符串 $v$，我们枚举替换后的第一个字母 $j$，如果 $v$ 替换后的字符串不在 $\textit{ideas}$ 中，那么我们就更新答案 $\textit{ans} = \textit{ans} + f[j][i]$。

最终答案即为 $\textit{ans}$。

时间复杂度 $O(n \times m \times |\Sigma|)$，空间复杂度 $O(|\Sigma|^2)$。其中 $n$ 和 $m$ 分别是 $\textit{ideas}$ 中字符串的个数和字符串的最大长度，而 $|\Sigma|$ 是字符串中出现的字符集，本题中 $|\Sigma| \leq 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        s = set(ideas)
        f = [[0] * 26 for _ in range(26)]
        for v in ideas:
            i = ord(v[0]) - ord('a')
            t = list(v)
            for j in range(26):
                t[0] = chr(ord('a') + j)
                if ''.join(t) not in s:
                    f[i][j] += 1
        ans = 0
        for v in ideas:
            i = ord(v[0]) - ord('a')
            t = list(v)
            for j in range(26):
                t[0] = chr(ord('a') + j)
                if ''.join(t) not in s:
                    ans += f[j][i]
        return ans
```

#### Java

```java
class Solution {
    public long distinctNames(String[] ideas) {
        Set<String> s = new HashSet<>();
        for (String v : ideas) {
            s.add(v);
        }
        int[][] f = new int[26][26];
        for (String v : ideas) {
            char[] t = v.toCharArray();
            int i = t[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                t[0] = (char) (j + 'a');
                if (!s.contains(String.valueOf(t))) {
                    ++f[i][j];
                }
            }
        }
        long ans = 0;
        for (String v : ideas) {
            char[] t = v.toCharArray();
            int i = t[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                t[0] = (char) (j + 'a');
                if (!s.contains(String.valueOf(t))) {
                    ans += f[j][i];
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
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s(ideas.begin(), ideas.end());
        int f[26][26]{};
        for (auto v : ideas) {
            int i = v[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                v[0] = j + 'a';
                if (!s.count(v)) {
                    ++f[i][j];
                }
            }
        }
        long long ans = 0;
        for (auto& v : ideas) {
            int i = v[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                v[0] = j + 'a';
                if (!s.count(v)) {
                    ans += f[j][i];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func distinctNames(ideas []string) (ans int64) {
	s := map[string]bool{}
	for _, v := range ideas {
		s[v] = true
	}
	f := [26][26]int{}
	for _, v := range ideas {
		i := int(v[0] - 'a')
		t := []byte(v)
		for j := 0; j < 26; j++ {
			t[0] = 'a' + byte(j)
			if !s[string(t)] {
				f[i][j]++
			}
		}
	}

	for _, v := range ideas {
		i := int(v[0] - 'a')
		t := []byte(v)
		for j := 0; j < 26; j++ {
			t[0] = 'a' + byte(j)
			if !s[string(t)] {
				ans += int64(f[j][i])
			}
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

# [2307. 检查方程中的矛盾之处 🔒](https://leetcode.cn/problems/check-for-contradictions-in-equations){#2307}

{{< tabs "2307" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkContradictions(
        self, equations: List[List[str]], values: List[float]
    ) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                root = find(p[x])
                w[x] *= w[p[x]]
                p[x] = root
            return p[x]

        d = defaultdict(int)
        n = 0
        for e in equations:
            for s in e:
                if s not in d:
                    d[s] = n
                    n += 1
        p = list(range(n))
        w = [1.0] * n
        eps = 1e-5
        for (a, b), v in zip(equations, values):
            a, b = d[a], d[b]
            pa, pb = find(a), find(b)
            if pa != pb:
                p[pb] = pa
                w[pb] = v * w[a] / w[b]
            elif abs(v * w[a] - w[b]) >= eps:
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;
    private double[] w;

    public boolean checkContradictions(List<List<String>> equations, double[] values) {
        Map<String, Integer> d = new HashMap<>();
        int n = 0;
        for (var e : equations) {
            for (var s : e) {
                if (!d.containsKey(s)) {
                    d.put(s, n++);
                }
            }
        }
        p = new int[n];
        w = new double[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            w[i] = 1.0;
        }
        final double eps = 1e-5;
        for (int i = 0; i < equations.size(); ++i) {
            int a = d.get(equations.get(i).get(0)), b = d.get(equations.get(i).get(1));
            int pa = find(a), pb = find(b);
            double v = values[i];
            if (pa != pb) {
                p[pb] = pa;
                w[pb] = v * w[a] / w[b];
            } else if (Math.abs(v * w[a] - w[b]) >= eps) {
                return true;
            }
        }
        return false;
    }

    private int find(int x) {
        if (p[x] != x) {
            int root = find(p[x]);
            w[x] *= w[p[x]];
            p[x] = root;
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> d;
        int n = 0;
        for (auto& e : equations) {
            for (auto& s : e) {
                if (!d.count(s)) {
                    d[s] = n++;
                }
            }
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        vector<double> w(n, 1.0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                int root = find(p[x]);
                w[x] *= w[p[x]];
                p[x] = root;
            }
            return p[x];
        };
        for (int i = 0; i < equations.size(); ++i) {
            int a = d[equations[i][0]], b = d[equations[i][1]];
            double v = values[i];
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pb] = pa;
                w[pb] = v * w[a] / w[b];
            } else if (fabs(v * w[a] - w[b]) >= 1e-5) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkContradictions(equations [][]string, values []float64) bool {
	d := make(map[string]int)
	n := 0

	for _, e := range equations {
		for _, s := range e {
			if _, ok := d[s]; !ok {
				d[s] = n
				n++
			}
		}
	}

	p := make([]int, n)
	for i := range p {
		p[i] = i
	}

	w := make([]float64, n)
	for i := range w {
		w[i] = 1.0
	}

	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			root := find(p[x])
			w[x] *= w[p[x]]
			p[x] = root
		}
		return p[x]
	}
	for i, e := range equations {
		a, b := d[e[0]], d[e[1]]
		v := values[i]

		pa, pb := find(a), find(b)
		if pa != pb {
			p[pb] = pa
			w[pb] = v * w[a] / w[b]
		} else if v*w[a]-w[b] >= 1e-5 || w[b]-v*w[a] >= 1e-5 {
			return true
		}
	}

	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkContradictions(equations: string[][], values: number[]): boolean {
    const d: { [key: string]: number } = {};
    let n = 0;

    for (const e of equations) {
        for (const s of e) {
            if (!(s in d)) {
                d[s] = n;
                n++;
            }
        }
    }

    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const w: number[] = Array.from({ length: n }, () => 1.0);

    const find = (x: number): number => {
        if (p[x] !== x) {
            const root = find(p[x]);
            w[x] *= w[p[x]];
            p[x] = root;
        }
        return p[x];
    };

    for (let i = 0; i < equations.length; i++) {
        const a = d[equations[i][0]];
        const b = d[equations[i][1]];
        const v = values[i];

        const pa = find(a);
        const pb = find(b);

        if (pa !== pb) {
            p[pb] = pa;
            w[pb] = (v * w[a]) / w[b];
        } else if (Math.abs(v * w[a] - w[b]) >= 1e-5) {
            return true;
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

<p>给你一个由字符串二维数组&nbsp;<code>equations</code> 和实数数组&nbsp;&nbsp;<code>values</code>&nbsp;，其中 <code>equations[i] = [A<sub>i</sub>, B<sub>i</sub>]</code>，<code>values[i]</code> 表示 <code>A<sub>i</sub> / B<sub>i</sub> = values[i]</code>.。</p>

<p>确定方程中是否存在矛盾。<em>如果存在矛盾则返回 <code>true</code>，否则返回 <code>false</code></em>。</p>

<p><b>注意</b>:</p>

<ul>
	<li>当检查两个数字是否相等时，检查它们的&nbsp;<strong>绝对差值&nbsp;</strong>是否小于 <code>10<sup>-5</sup></code>.</li>
	<li>生成的测试用例没有针对精度的用例，即使用 <code>double</code> 就足以解决问题。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> equations = [["a","b"],["b","c"],["a","c"]], values = [3,0.5,1.5]
<strong>输出:</strong> false
<strong>解释:
</strong>给定的方程为: a / b = 3, b / c = 0.5, a / c = 1.5
方程中没有矛盾。满足所有方程的一个可能的分配是:
a = 3, b = 1 和 c = 2.
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> equations = [["le","et"],["le","code"],["code","et"]], values = [2,5,0.5]
<strong>输出:</strong> true
<strong>解释:</strong>
给定的方程为: le / et = 2, le / code = 5, code / et = 0.5
根据前两个方程，我们得到 code / et = 0.4.
因为第三个方程是 code / et = 0.5, 所以矛盾。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 100</code></li>
	<li><code>equations[i].length == 2</code></li>
	<li><code>1 &lt;= A<sub>i</sub>.length, B<sub>i</sub>.length &lt;= 5</code></li>
	<li><code>A<sub>i</sub></code>, <code>B<sub>i</sub></code> 由小写英文字母组成。</li>
	<li><code>equations.length == values.length</code></li>
	<li><code>0.0 &lt; values[i] &lt;= 10.0</code></li>
	<li><code>values[i]</code> 小数点后最多 2 位。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：带权并查集

我们先将字符串转换成从 $0$ 开始的整数，然后遍历所有的等式，将等式中的两个字符串映射成对应的整数 $a$ 和 $b$，如果这两个整数不在同一个集合中，就将它们合并到同一个集合中，并且记录下两个整数的权值，即 $a$ 与 $b$ 的比值。如果这两个整数在同一个集合中，就判断它们的权值是否满足等式，如果不满足就返回 `true`。

时间复杂度 $O(n \times \log n)$ 或 $O(n \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 是等式的数量。

相似题目：

-   [399. 除法求值](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0399.Evaluate%20Division/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkContradictions(
        self, equations: List[List[str]], values: List[float]
    ) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                root = find(p[x])
                w[x] *= w[p[x]]
                p[x] = root
            return p[x]

        d = defaultdict(int)
        n = 0
        for e in equations:
            for s in e:
                if s not in d:
                    d[s] = n
                    n += 1
        p = list(range(n))
        w = [1.0] * n
        eps = 1e-5
        for (a, b), v in zip(equations, values):
            a, b = d[a], d[b]
            pa, pb = find(a), find(b)
            if pa != pb:
                p[pb] = pa
                w[pb] = v * w[a] / w[b]
            elif abs(v * w[a] - w[b]) >= eps:
                return True
        return False
```

#### Java

```java
class Solution {
    private int[] p;
    private double[] w;

    public boolean checkContradictions(List<List<String>> equations, double[] values) {
        Map<String, Integer> d = new HashMap<>();
        int n = 0;
        for (var e : equations) {
            for (var s : e) {
                if (!d.containsKey(s)) {
                    d.put(s, n++);
                }
            }
        }
        p = new int[n];
        w = new double[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            w[i] = 1.0;
        }
        final double eps = 1e-5;
        for (int i = 0; i < equations.size(); ++i) {
            int a = d.get(equations.get(i).get(0)), b = d.get(equations.get(i).get(1));
            int pa = find(a), pb = find(b);
            double v = values[i];
            if (pa != pb) {
                p[pb] = pa;
                w[pb] = v * w[a] / w[b];
            } else if (Math.abs(v * w[a] - w[b]) >= eps) {
                return true;
            }
        }
        return false;
    }

    private int find(int x) {
        if (p[x] != x) {
            int root = find(p[x]);
            w[x] *= w[p[x]];
            p[x] = root;
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> d;
        int n = 0;
        for (auto& e : equations) {
            for (auto& s : e) {
                if (!d.count(s)) {
                    d[s] = n++;
                }
            }
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        vector<double> w(n, 1.0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                int root = find(p[x]);
                w[x] *= w[p[x]];
                p[x] = root;
            }
            return p[x];
        };
        for (int i = 0; i < equations.size(); ++i) {
            int a = d[equations[i][0]], b = d[equations[i][1]];
            double v = values[i];
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pb] = pa;
                w[pb] = v * w[a] / w[b];
            } else if (fabs(v * w[a] - w[b]) >= 1e-5) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func checkContradictions(equations [][]string, values []float64) bool {
	d := make(map[string]int)
	n := 0

	for _, e := range equations {
		for _, s := range e {
			if _, ok := d[s]; !ok {
				d[s] = n
				n++
			}
		}
	}

	p := make([]int, n)
	for i := range p {
		p[i] = i
	}

	w := make([]float64, n)
	for i := range w {
		w[i] = 1.0
	}

	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			root := find(p[x])
			w[x] *= w[p[x]]
			p[x] = root
		}
		return p[x]
	}
	for i, e := range equations {
		a, b := d[e[0]], d[e[1]]
		v := values[i]

		pa, pb := find(a), find(b)
		if pa != pb {
			p[pb] = pa
			w[pb] = v * w[a] / w[b]
		} else if v*w[a]-w[b] >= 1e-5 || w[b]-v*w[a] >= 1e-5 {
			return true
		}
	}

	return false
}
```

#### TypeScript

```ts
function checkContradictions(equations: string[][], values: number[]): boolean {
    const d: { [key: string]: number } = {};
    let n = 0;

    for (const e of equations) {
        for (const s of e) {
            if (!(s in d)) {
                d[s] = n;
                n++;
            }
        }
    }

    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const w: number[] = Array.from({ length: n }, () => 1.0);

    const find = (x: number): number => {
        if (p[x] !== x) {
            const root = find(p[x]);
            w[x] *= w[p[x]];
            p[x] = root;
        }
        return p[x];
    };

    for (let i = 0; i < equations.length; i++) {
        const a = d[equations[i][0]];
        const b = d[equations[i][1]];
        const v = values[i];

        const pa = find(a);
        const pb = find(b);

        if (pa !== pb) {
            p[pb] = pa;
            w[pb] = (v * w[a]) / w[b];
        } else if (Math.abs(v * w[a] - w[b]) >= 1e-5) {
            return true;
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

# [2308. 按性别排列表格 🔒](https://leetcode.cn/problems/arrange-table-by-gender){#2308}

{{< tabs "2308" >}}

{{% tab "sql" %}}
```sql
SELECT
    user_id,
    gender
FROM Genders
ORDER BY
    (
        RANK() OVER (
            PARTITION BY gender
            ORDER BY user_id
        )
    ),
    2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Genders</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| gender      | varchar |
+-------------+---------+
user_id 是该表的主键(具有唯一值的列)。
gender 的值是 'female', 'male','other' 之一。
该表中的每一行都包含用户的 ID 及其性别。
表格中 'female', 'male','other' 数量相等。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案以重新排列 <code>Genders</code> 表，使行按顺序在&nbsp;<code>'female'</code>,&nbsp;<code>'other'</code>&nbsp;和&nbsp;<code>'male'</code>&nbsp;之间交替。同时每种性别按照&nbsp;user_id 升序进行排序。<br />
按 <strong>上述顺序</strong> 返回结果表。<br />
返回结果格式如以下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Genders 表:
+---------+--------+
| user_id | gender |
+---------+--------+
| 4       | male   |
| 7       | female |
| 2       | other  |
| 5       | male   |
| 3       | female |
| 8       | male   |
| 6       | other  |
| 1       | other  |
| 9       | female |
+---------+--------+
<strong>输出:</strong> 
+---------+--------+
| user_id | gender |
+---------+--------+
| 3       | female |
| 1       | other  |
| 4       | male   |
| 7       | female |
| 2       | other  |
| 5       | male   |
| 9       | female |
| 6       | other  |
| 8       | male   |
+---------+--------+
<strong>解释:</strong> 
女性：ID 3、7、9。
其他性别：ID 1、2、6。
男性：ID 4、5、8。
我们在 'female', 'other','male' 之间交替排列表。
注意，每种性别都是按 user_id 升序排序的。
</pre>

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
    t AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY gender
                ORDER BY user_id
            ) AS rk1,
            CASE
                WHEN gender = 'female' THEN 0
                WHEN gender = 'other' THEN 1
                ELSE 2
            END AS rk2
        FROM Genders
    )
SELECT user_id, gender
FROM t
ORDER BY rk1, rk2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    user_id,
    gender
FROM Genders
ORDER BY
    (
        RANK() OVER (
            PARTITION BY gender
            ORDER BY user_id
        )
    ),
    2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2309. 兼具大小写的最好英文字母](https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case){#2309}

{{< tabs "2309" >}}

{{% tab "python" %}}
```python
class Solution:
    def greatestLetter(self, s: str) -> str:
        mask1 = mask2 = 0
        for c in s:
            if c.islower():
                mask1 |= 1 << (ord(c) - ord("a"))
            else:
                mask2 |= 1 << (ord(c) - ord("A"))
        mask = mask1 & mask2
        return chr(mask.bit_length() - 1 + ord("A")) if mask else ""
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String greatestLetter(String s) {
        int mask1 = 0, mask2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask > 0 ? String.valueOf((char) (31 - Integer.numberOfLeadingZeros(mask) + 'A'))
                        : "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string greatestLetter(string s) {
        int mask1 = 0, mask2 = 0;
        for (char& c : s) {
            if (islower(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask ? string(1, 31 - __builtin_clz(mask) + 'A') : "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func greatestLetter(s string) string {
	mask1, mask2 := 0, 0
	for _, c := range s {
		if unicode.IsLower(c) {
			mask1 |= 1 << (c - 'a')
		} else {
			mask2 |= 1 << (c - 'A')
		}
	}
	mask := mask1 & mask2
	if mask == 0 {
		return ""
	}
	return string(byte(bits.Len(uint(mask))-1) + 'A')
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function greatestLetter(s: string): string {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut arr = [0; 26];
        for &c in s.as_bytes().iter() {
            if c >= b'a' {
                arr[(c - b'a') as usize] |= 1;
            } else {
                arr[(c - b'A') as usize] |= 2;
            }
        }
        for i in (0..26).rev() {
            if arr[i] == 3 {
                return char::from(b'A' + (i as u8)).to_string();
            }
        }
        "".to_string()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var greatestLetter = function (s) {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
        }
    }
    return '';
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由英文字母组成的字符串 <code>s</code> ，请你找出并返回 <code>s</code> 中的 <strong>最好</strong> 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。</p>

<p><strong>最好</strong> 英文字母的大写和小写形式必须 <strong>都</strong> 在 <code>s</code> 中出现。</p>

<p>英文字母 <code>b</code> 比另一个英文字母&nbsp;<code>a</code>&nbsp;<strong>更好</strong> 的前提是：英文字母表中，<code>b</code> 在 <code>a</code> 之 <strong>后</strong> 出现。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "l<em><strong>Ee</strong></em>TcOd<em><strong>E</strong></em>"
<strong>输出：</strong>"E"
<strong>解释：</strong>
字母 'E' 是唯一一个大写和小写形式都出现的字母。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a<em><strong>rR</strong></em>AzFif"
<strong>输出：</strong>"R"
<strong>解释：</strong>
字母 'R' 是大写和小写形式都出现的最好英文字母。
注意 'A' 和 'F' 的大写和小写形式也都出现了，但是 'R' 比 'F' 和 'A' 更好。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "AbCdEfGhIjK"
<strong>输出：</strong>""
<strong>解释：</strong>
不存在大写和小写形式都出现的字母。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 由小写和大写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们先用哈希表 $ss$ 记录字符串 $s$ 中出现的所有字母，然后从大写字母表的最后一个字母开始枚举，如果当前字母的大写和小写形式都在 $ss$ 中，则返回该字母。

枚举结束后，如果没有找到符合条件的字母，则返回空字符串。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 和 $C$ 分别是字符串 $s$ 的长度和字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def greatestLetter(self, s: str) -> str:
        ss = set(s)
        for c in ascii_uppercase[::-1]:
            if c in ss and c.lower() in ss:
                return c
        return ''
```

#### Java

```java
class Solution {
    public String greatestLetter(String s) {
        Set<Character> ss = new HashSet<>();
        for (char c : s.toCharArray()) {
            ss.add(c);
        }
        for (char a = 'Z'; a >= 'A'; --a) {
            if (ss.contains(a) && ss.contains((char) (a + 32))) {
                return String.valueOf(a);
            }
        }
        return "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ss(s.begin(), s.end());
        for (char c = 'Z'; c >= 'A'; --c) {
            if (ss.count(c) && ss.count(char(c + 32))) {
                return string(1, c);
            }
        }
        return "";
    }
};
```

#### Go

```go
func greatestLetter(s string) string {
	ss := map[rune]bool{}
	for _, c := range s {
		ss[c] = true
	}
	for c := 'Z'; c >= 'A'; c-- {
		if ss[c] && ss[rune(c+32)] {
			return string(c)
		}
	}
	return ""
}
```

#### TypeScript

```ts
function greatestLetter(s: string): string {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
        }
    }
    return '';
}
```

#### Rust

```rust
impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut arr = [0; 26];
        for &c in s.as_bytes().iter() {
            if c >= b'a' {
                arr[(c - b'a') as usize] |= 1;
            } else {
                arr[(c - b'A') as usize] |= 2;
            }
        }
        for i in (0..26).rev() {
            if arr[i] == 3 {
                return char::from(b'A' + (i as u8)).to_string();
            }
        }
        "".to_string()
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var greatestLetter = function (s) {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
        }
    }
    return '';
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算（空间优化）

我们可以用两个整数 $mask1$ 和 $mask2$ 分别记录字符串 $s$ 中出现的小写字母和大写字母，其中 $mask1$ 的第 $i$ 位表示第 $i$ 个小写字母是否出现，而 $mask2$ 的第 $i$ 位表示第 $i$ 个大写字母是否出现。

然后我们将 $mask1$ 和 $mask2$ 进行与运算，得到的结果 $mask$ 的第 $i$ 位表示第 $i$ 个字母的大小写是否同时出现。

接下来我们只要获取 $mask$ 的二进制表示中最高位的 $1$ 的位置，将其转换为对应的大写字母即可。如果所有二进制位都不为 $1$，说明不存在大小写同时出现的字母，返回空字符串。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def greatestLetter(self, s: str) -> str:
        mask1 = mask2 = 0
        for c in s:
            if c.islower():
                mask1 |= 1 << (ord(c) - ord("a"))
            else:
                mask2 |= 1 << (ord(c) - ord("A"))
        mask = mask1 & mask2
        return chr(mask.bit_length() - 1 + ord("A")) if mask else ""
```

#### Java

```java
class Solution {
    public String greatestLetter(String s) {
        int mask1 = 0, mask2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask > 0 ? String.valueOf((char) (31 - Integer.numberOfLeadingZeros(mask) + 'A'))
                        : "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string greatestLetter(string s) {
        int mask1 = 0, mask2 = 0;
        for (char& c : s) {
            if (islower(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask ? string(1, 31 - __builtin_clz(mask) + 'A') : "";
    }
};
```

#### Go

```go
func greatestLetter(s string) string {
	mask1, mask2 := 0, 0
	for _, c := range s {
		if unicode.IsLower(c) {
			mask1 |= 1 << (c - 'a')
		} else {
			mask2 |= 1 << (c - 'A')
		}
	}
	mask := mask1 & mask2
	if mask == 0 {
		return ""
	}
	return string(byte(bits.Len(uint(mask))-1) + 'A')
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
