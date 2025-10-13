---
title: "1060_有序数组中的缺失元素 🔒"
date: 2025-10-08T18:36:50+08:00
weight: 7
tags: [二分查找, 位运算, 动态规划, 单调栈, 后缀数组, 哈希函数, 回溯, 字典树, 字符串, 并查集, 排序, 数学, 数据库, 数组, 栈, 滚动哈希, 状态压缩]
---

{{< markmap >}}
### [1060_有序数组中的缺失元素 🔒](#1060)
#### [数组](#1060)
#### [二分查找](#1060)
### [1061_按字典序排列最小的等效字符串](#1061)
#### [并查集](#1061)
#### [字符串](#1061)
### [1062_最长重复子串的长度 🔒](#1062)
#### [字符串](#1062)
#### [二分查找](#1062)
#### [动态规划](#1062)
#### [后缀数组](#1062)
#### [哈希函数](#1062)
#### [滚动哈希](#1062)
### [1063_有效子数组的数目 🔒](#1063)
#### [栈](#1063)
#### [数组](#1063)
#### [单调栈](#1063)
### [1064_不动点 🔒](#1064)
#### [数组](#1064)
#### [二分查找](#1064)
### [1065_字符串的索引对 🔒](#1065)
#### [字典树](#1065)
#### [数组](#1065)
#### [字符串](#1065)
#### [排序](#1065)
### [1066_校园自行车分配 II 🔒](#1066)
#### [位运算](#1066)
#### [数组](#1066)
#### [动态规划](#1066)
#### [回溯](#1066)
#### [状态压缩](#1066)
### [1067_范围内的数字计数 🔒](#1067)
#### [数学](#1067)
#### [动态规划](#1067)
### [1068_产品销售分析 I](#1068)
#### [数据库](#1068)
### [1069_产品销售分析 II 🔒](#1069)
#### [数据库](#1069)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1060_有序数组中的缺失元素 🔒
___
#### 数组
___
#### 二分查找
---
### 1061_按字典序排列最小的等效字符串
___
#### 并查集
___
#### 字符串
---
### 1062_最长重复子串的长度 🔒
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
___
#### 后缀数组
___
#### 哈希函数
___
#### 滚动哈希
---
### 1063_有效子数组的数目 🔒
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 1064_不动点 🔒
___
#### 数组
___
#### 二分查找
---
### 1065_字符串的索引对 🔒
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 排序
---
### 1066_校园自行车分配 II 🔒
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
### 1067_范围内的数字计数 🔒
___
#### 数学
___
#### 动态规划
---
### 1068_产品销售分析 I
___
#### 数据库
---
### 1069_产品销售分析 II 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 后缀数组 | 哈希函数 |
| 回溯 | 字典树 | 字符串 |
| 并查集 | 排序 | 数学 |
| 数据库 | 数组 | 栈 |
| 滚动哈希 | 状态压缩 |  |

# [1060. 有序数组中的缺失元素 🔒](https://leetcode.cn/problems/missing-element-in-sorted-array){#1060}

{{< tabs "1060" >}}

{{% tab "python" %}}
```python
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        def missing(i: int) -> int:
            return nums[i] - nums[0] - i

        n = len(nums)
        if k > missing(n - 1):
            return nums[n - 1] + k - missing(n - 1)
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) >> 1
            if missing(mid) >= k:
                r = mid
            else:
                l = mid + 1
        return nums[l - 1] + k - missing(l - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        if (k > missing(nums, n - 1)) {
            return nums[n - 1] + k - missing(nums, n - 1);
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (missing(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l - 1] + k - missing(nums, l - 1);
    }

    private int missing(int[] nums, int i) {
        return nums[i] - nums[0] - i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        auto missing = [&](int i) {
            return nums[i] - nums[0] - i;
        };
        int n = nums.size();
        if (k > missing(n - 1)) {
            return nums[n - 1] + k - missing(n - 1);
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (missing(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l - 1] + k - missing(l - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func missingElement(nums []int, k int) int {
	missing := func(i int) int {
		return nums[i] - nums[0] - i
	}
	n := len(nums)
	if k > missing(n-1) {
		return nums[n-1] + k - missing(n-1)
	}
	l, r := 0, n-1
	for l < r {
		mid := (l + r) >> 1
		if missing(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l-1] + k - missing(l-1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个按 <strong>升序</strong> 排列的整数数组 <code>nums</code> ，其中每个数字都 <strong>互不相同</strong> 。</p>

<p>给你一个整数 <code>k</code> ，请你找出并返回从数组最左边开始的第 <code>k</code> 个缺失数字。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,7,9,10], k = 1
<strong>输出：</strong>5
<strong>解释：</strong>第一个缺失数字为 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,7,9,10], k = 3
<strong>输出：</strong>8
<strong>解释：</strong>缺失数字有 [5,6,8,...]，因此第三个缺失数字为 8 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4], k = 3
<strong>输出：</strong>6
<strong>解释：</strong>缺失数字有 [3,5,6,7,...]，因此第三个缺失数字为 6 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>7</sup></code></li>
	<li><code>nums</code> 按 <strong>升序</strong> 排列，其中所有元素 <strong>互不相同</strong> 。</li>
	<li><code>1 <= k <= 10<sup>8</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以设计一个对数时间复杂度（即，<code>O(log(n))</code>）的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们设计一个函数 $missing(i)$，表示 $nums[i]$ 与 $nums[0]$ 之间缺失的元素个数。那么 $missing(i)$ 就等于 $nums[i] - nums[0] - i$。我们可以通过二分查找找到最小的 $i$，使得 $missing(i) \geq k$，那么 $nums[i - 1] + k - missing(i - 1)$ 就是第 $k$ 个缺失的元素。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        def missing(i: int) -> int:
            return nums[i] - nums[0] - i

        n = len(nums)
        if k > missing(n - 1):
            return nums[n - 1] + k - missing(n - 1)
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) >> 1
            if missing(mid) >= k:
                r = mid
            else:
                l = mid + 1
        return nums[l - 1] + k - missing(l - 1)
```

#### Java

```java
class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        if (k > missing(nums, n - 1)) {
            return nums[n - 1] + k - missing(nums, n - 1);
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (missing(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l - 1] + k - missing(nums, l - 1);
    }

    private int missing(int[] nums, int i) {
        return nums[i] - nums[0] - i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        auto missing = [&](int i) {
            return nums[i] - nums[0] - i;
        };
        int n = nums.size();
        if (k > missing(n - 1)) {
            return nums[n - 1] + k - missing(n - 1);
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (missing(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l - 1] + k - missing(l - 1);
    }
};
```

#### Go

```go
func missingElement(nums []int, k int) int {
	missing := func(i int) int {
		return nums[i] - nums[0] - i
	}
	n := len(nums)
	if k > missing(n-1) {
		return nums[n-1] + k - missing(n-1)
	}
	l, r := 0, n-1
	for l < r {
		mid := (l + r) >> 1
		if missing(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l-1] + k - missing(l-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1061. 按字典序排列最小的等效字符串](https://leetcode.cn/problems/lexicographically-smallest-equivalent-string){#1061}

{{< tabs "1061" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(26))
        for a, b in zip(s1, s2):
            x, y = ord(a) - ord("a"), ord(b) - ord("a")
            px, py = find(x), find(y)
            if px < py:
                p[py] = px
            else:
                p[px] = py
        return "".join(chr(find(ord(c) - ord("a")) + ord("a")) for c in baseStr)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[] p = new int[26];

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < s1.length(); ++i) {
            int x = s1.charAt(i) - 'a';
            int y = s2.charAt(i) - 'a';
            int px = find(x), py = find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }
        char[] s = baseStr.toCharArray();
        for (int i = 0; i < s.length; ++i) {
            s[i] = (char) ('a' + find(s[i] - 'a'));
        }
        return String.valueOf(s);
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p(26);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int i = 0; i < s1.length(); ++i) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            int px = find(x), py = find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }
        string s;
        for (char c : baseStr) {
            s.push_back('a' + find(c - 'a'));
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	p := make([]int, 26)
	for i := 0; i < 26; i++ {
		p[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	for i := 0; i < len(s1); i++ {
		x := int(s1[i] - 'a')
		y := int(s2[i] - 'a')
		px := find(x)
		py := find(y)
		if px < py {
			p[py] = px
		} else {
			p[px] = py
		}
	}

	var s []byte
	for i := 0; i < len(baseStr); i++ {
		s = append(s, byte('a'+find(int(baseStr[i]-'a'))))
	}

	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestEquivalentString(s1: string, s2: string, baseStr: string): string {
    const p: number[] = Array.from({ length: 26 }, (_, i) => i);

    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };

    for (let i = 0; i < s1.length; i++) {
        const x = s1.charCodeAt(i) - 'a'.charCodeAt(0);
        const y = s2.charCodeAt(i) - 'a'.charCodeAt(0);
        const px = find(x);
        const py = find(y);
        if (px < py) {
            p[py] = px;
        } else {
            p[px] = py;
        }
    }

    const s: string[] = [];
    for (let i = 0; i < baseStr.length; i++) {
        const c = baseStr.charCodeAt(i) - 'a'.charCodeAt(0);
        s.push(String.fromCharCode('a'.charCodeAt(0) + find(c)));
    }
    return s.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_equivalent_string(s1: String, s2: String, base_str: String) -> String {
        fn find(x: usize, p: &mut Vec<usize>) -> usize {
            if p[x] != x {
                p[x] = find(p[x], p);
            }
            p[x]
        }

        let mut p = (0..26).collect::<Vec<_>>();
        for (a, b) in s1.bytes().zip(s2.bytes()) {
            let x = (a - b'a') as usize;
            let y = (b - b'a') as usize;
            let px = find(x, &mut p);
            let py = find(y, &mut p);
            if px < py {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }

        base_str
            .bytes()
            .map(|c| (b'a' + find((c - b'a') as usize, &mut p) as u8) as char)
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string SmallestEquivalentString(string s1, string s2, string baseStr) {
        int[] p = new int[26];
        for (int i = 0; i < 26; i++) {
            p[i] = i;
        }

        int Find(int x) {
            if (p[x] != x) {
                p[x] = Find(p[x]);
            }
            return p[x];
        }

        for (int i = 0; i < s1.Length; i++) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            int px = Find(x);
            int py = Find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }

        var res = new System.Text.StringBuilder();
        foreach (char c in baseStr) {
            int idx = Find(c - 'a');
            res.Append((char)(idx + 'a'));
        }

        return res.ToString();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出长度相同的两个字符串<code>s1</code> 和&nbsp;<code>s2</code>&nbsp;，还有一个字符串&nbsp;<code>baseStr</code>&nbsp;。</p>

<p>其中 &nbsp;<code>s1[i]</code>&nbsp;和&nbsp;<code>s2[i]</code>&nbsp; 是一组等价字符。</p>

<ul>
	<li>举个例子，如果&nbsp;<code>s1 = "abc"</code> 且&nbsp;<code>s2 = "cde"</code>，那么就有&nbsp;<code>'a' == 'c', 'b' == 'd', 'c' == 'e'</code>。</li>
</ul>

<p>等价字符遵循任何等价关系的一般规则：</p>

<ul>
	<li><strong>&nbsp;自反性&nbsp;</strong>：<code>'a' == 'a'</code></li>
	<li>&nbsp;<strong>对称性&nbsp;</strong>：<code>'a' == 'b'</code> 则必定有 <code>'b' == 'a'</code></li>
	<li>&nbsp;<strong>传递性</strong> ：<code>'a' == 'b'</code> 且 <code>'b' == 'c'</code> 就表明 <code>'a' == 'c'</code></li>
</ul>

<p>例如，&nbsp;<code>s1 = "abc"</code>&nbsp;和&nbsp;<code>s2 = "cde"</code>&nbsp;的等价信息和之前的例子一样，那么&nbsp;<code>baseStr = "eed"</code>&nbsp;, <code>"acd"</code>&nbsp;或&nbsp;<code>"aab"</code>，这三个字符串都是等价的，而&nbsp;<code>"aab"</code>&nbsp;是&nbsp;<code>baseStr</code>&nbsp;的按字典序最小的等价字符串</p>

<p>利用<em>&nbsp;</em><code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;的等价信息，找出并返回<em>&nbsp;</em><code>baseStr</code><em>&nbsp;</em>的按字典序排列最小的等价字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "parker", s2 = "morris", baseStr = "parser"
<strong>输出：</strong>"makkek"
<strong>解释：</strong>根据 <code>A</code> 和 <code>B</code> 中的等价信息，我们可以将这些字符分为 <code>[m,p]</code>, <code>[a,o]</code>, <code>[k,r,s]</code>, <code>[e,i]</code> 共 4 组。每组中的字符都是等价的，并按字典序排列。所以答案是 <code>"makkek"</code>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "hello", s2 = "world", baseStr = "hold"
<strong>输出：</strong>"hdld"
<strong>解释：</strong>根据 <code>A</code> 和 <code>B</code> 中的等价信息，我们可以将这些字符分为 <code>[h,w]</code>, <code>[d,e,o]</code>, <code>[l,r]</code> 共 3 组。所以只有 S 中的第二个字符 <code>'o'</code> 变成 <code>'d'</code>，最后答案为 <code>"hdld"</code>。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
<strong>输出：</strong>"aauaaaaada"
<strong>解释：</strong>我们可以把 <code>A</code> 和 <code>B</code> 中的等价字符分为 <code>[a,o,e,r,s,c]</code>, <code>[l,p]</code>, <code>[g,t]</code> 和 <code>[d,m]</code> 共 4 组，因此 <code>S</code> 中除了 <code>'u'</code> 和 <code>'d'</code> 之外的所有字母都转化成了 <code>'a'</code>，最后答案为 <code>"aauaaaaada"</code>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length, baseStr &lt;= 1000</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li>字符串<code>s1</code>,&nbsp;<code>s2</code>, and&nbsp;<code>baseStr</code>&nbsp;仅由从&nbsp;<code>'a'</code> 到&nbsp;<code>'z'</code>&nbsp;的小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以使用并查集来处理等价字符的关系。每个字符可以看作一个节点，等价关系可以看作是连接这些节点的边。通过并查集，我们可以将所有等价的字符归为一类，并且在查询时能够快速找到每个字符的代表元素。我们在进行合并操作时，始终将代表元素设置为字典序最小的字符，这样可以确保最终得到的字符串是按字典序排列的最小等价字符串。

时间复杂度 $O((n + m) \times \log |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s1$ 和 $s2$ 的长度，而 $m$ 是字符串 $baseStr$ 的长度，而 $|\Sigma|$ 是字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(26))
        for a, b in zip(s1, s2):
            x, y = ord(a) - ord("a"), ord(b) - ord("a")
            px, py = find(x), find(y)
            if px < py:
                p[py] = px
            else:
                p[px] = py
        return "".join(chr(find(ord(c) - ord("a")) + ord("a")) for c in baseStr)
```

#### Java

```java
class Solution {
    private final int[] p = new int[26];

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < s1.length(); ++i) {
            int x = s1.charAt(i) - 'a';
            int y = s2.charAt(i) - 'a';
            int px = find(x), py = find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }
        char[] s = baseStr.toCharArray();
        for (int i = 0; i < s.length; ++i) {
            s[i] = (char) ('a' + find(s[i] - 'a'));
        }
        return String.valueOf(s);
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p(26);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int i = 0; i < s1.length(); ++i) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            int px = find(x), py = find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }
        string s;
        for (char c : baseStr) {
            s.push_back('a' + find(c - 'a'));
        }
        return s;
    }
};
```

#### Go

```go
func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	p := make([]int, 26)
	for i := 0; i < 26; i++ {
		p[i] = i
	}

	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	for i := 0; i < len(s1); i++ {
		x := int(s1[i] - 'a')
		y := int(s2[i] - 'a')
		px := find(x)
		py := find(y)
		if px < py {
			p[py] = px
		} else {
			p[px] = py
		}
	}

	var s []byte
	for i := 0; i < len(baseStr); i++ {
		s = append(s, byte('a'+find(int(baseStr[i]-'a'))))
	}

	return string(s)
}
```

#### TypeScript

```ts
function smallestEquivalentString(s1: string, s2: string, baseStr: string): string {
    const p: number[] = Array.from({ length: 26 }, (_, i) => i);

    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };

    for (let i = 0; i < s1.length; i++) {
        const x = s1.charCodeAt(i) - 'a'.charCodeAt(0);
        const y = s2.charCodeAt(i) - 'a'.charCodeAt(0);
        const px = find(x);
        const py = find(y);
        if (px < py) {
            p[py] = px;
        } else {
            p[px] = py;
        }
    }

    const s: string[] = [];
    for (let i = 0; i < baseStr.length; i++) {
        const c = baseStr.charCodeAt(i) - 'a'.charCodeAt(0);
        s.push(String.fromCharCode('a'.charCodeAt(0) + find(c)));
    }
    return s.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_equivalent_string(s1: String, s2: String, base_str: String) -> String {
        fn find(x: usize, p: &mut Vec<usize>) -> usize {
            if p[x] != x {
                p[x] = find(p[x], p);
            }
            p[x]
        }

        let mut p = (0..26).collect::<Vec<_>>();
        for (a, b) in s1.bytes().zip(s2.bytes()) {
            let x = (a - b'a') as usize;
            let y = (b - b'a') as usize;
            let px = find(x, &mut p);
            let py = find(y, &mut p);
            if px < py {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }

        base_str
            .bytes()
            .map(|c| (b'a' + find((c - b'a') as usize, &mut p) as u8) as char)
            .collect()
    }
}
```

#### C#

```cs
public class Solution {
    public string SmallestEquivalentString(string s1, string s2, string baseStr) {
        int[] p = new int[26];
        for (int i = 0; i < 26; i++) {
            p[i] = i;
        }

        int Find(int x) {
            if (p[x] != x) {
                p[x] = Find(p[x]);
            }
            return p[x];
        }

        for (int i = 0; i < s1.Length; i++) {
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            int px = Find(x);
            int py = Find(y);
            if (px < py) {
                p[py] = px;
            } else {
                p[px] = py;
            }
        }

        var res = new System.Text.StringBuilder();
        foreach (char c in baseStr) {
            int idx = Find(c - 'a');
            res.Append((char)(idx + 'a'));
        }

        return res.ToString();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1062. 最长重复子串的长度 🔒](https://leetcode.cn/problems/longest-repeating-substring){#1062}

{{< tabs "1062" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                if s[i] == s[j]:
                    f[i][j] = 1 + (f[i - 1][j - 1] if j else 0)
                    ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestRepeatingSubstring(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = Math.max(ans, f[i][j]);
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
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = max(ans, f[i][j]);
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
func longestRepeatingSubstring(s string) (ans int) {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if s[i] == s[j] {
				if j > 0 {
					f[i][j] = f[i-1][j-1]
				}
				f[i][j]++
				ans = max(ans, f[i][j])
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestRepeatingSubstring(s: string): number {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }).map(() => Array(n).fill(0));
    let ans = 0;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = 1 + (f[i - 1][j - 1] || 0);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_repeating_substring(s: String) -> i32 {
        let n = s.len();
        let mut f = vec![vec![0; n]; n];
        let mut ans = 0;
        let s = s.as_bytes();

        for i in 1..n {
            for j in 0..i {
                if s[i] == s[j] {
                    f[i][j] = if j > 0 { f[i - 1][j - 1] + 1 } else { 1 };
                    ans = ans.max(f[i][j]);
                }
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

<p>给定字符串&nbsp;<code>s</code>，找出最长重复子串的长度。如果不存在重复子串就返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>"abcd"
<strong>输出：</strong>0
<strong>解释：</strong>没有重复子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>"abbaba"
<strong>输出：</strong>2
<strong>解释：</strong>最长的重复子串为 "ab" 和 "ba"，每个出现 2 次。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>"aabcaabdaab"
<strong>输出：</strong>3
<strong>解释：</strong>最长的重复子串为 "aab"，出现 3 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li>字符串&nbsp;<code>s</code>&nbsp;仅包含从&nbsp;<code>'a'</code> 到&nbsp;<code>'z'</code>&nbsp;的小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以 $s[i]$ 和 $s[j]$ 结尾的最长重复子串的长度，初始时 $f[i][j]=0$。

我们在 $[1, n)$ 的区间内枚举 $i$，在 $[0, i)$ 的区间内枚举 $j$，如果 $s[i]=s[j]$，那么有：

$$
f[i][j]=
\begin{cases}
f[i-1][j-1]+1, & j>0 \\
1, & j=0
\end{cases}
$$

我们求出所有 $f[i][j]$ 的最大值即为答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

相似题目：

-   [1044. 最长重复子串 🔒](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1044.Longest%20Duplicate%20Substring/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                if s[i] == s[j]:
                    f[i][j] = 1 + (f[i - 1][j - 1] if j else 0)
                    ans = max(ans, f[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int longestRepeatingSubstring(String s) {
        int n = s.length();
        int[][] f = new int[n][n];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = Math.max(ans, f[i][j]);
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
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestRepeatingSubstring(s string) (ans int) {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if s[i] == s[j] {
				if j > 0 {
					f[i][j] = f[i-1][j-1]
				}
				f[i][j]++
				ans = max(ans, f[i][j])
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function longestRepeatingSubstring(s: string): number {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }).map(() => Array(n).fill(0));
    let ans = 0;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = 1 + (f[i - 1][j - 1] || 0);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_repeating_substring(s: String) -> i32 {
        let n = s.len();
        let mut f = vec![vec![0; n]; n];
        let mut ans = 0;
        let s = s.as_bytes();

        for i in 1..n {
            for j in 0..i {
                if s[i] == s[j] {
                    f[i][j] = if j > 0 { f[i - 1][j - 1] + 1 } else { 1 };
                    ans = ans.max(f[i][j]);
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

# [1063. 有效子数组的数目 🔒](https://leetcode.cn/problems/number-of-valid-subarrays){#1063}

{{< tabs "1063" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        stk = []
        ans = 0
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            ans += (stk[-1] if stk else n) - i
            stk.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int validSubarrays(int[] nums) {
        int n = nums.length;
        Deque<Integer> stk = new ArrayDeque<>();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            ans += (stk.isEmpty() ? n : stk.peek()) - i;

            stk.push(i);
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
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        int ans = 0;
        for (int i = n - 1; ~i; --i) {
            while (stk.size() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            ans += (stk.size() ? stk.top() : n) - i;
            stk.push(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSubarrays(nums []int) (ans int) {
	n := len(nums)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= nums[i] {
			stk = stk[:len(stk)-1]
		}
		ans -= i
		if len(stk) > 0 {
			ans += stk[len(stk)-1]
		} else {
			ans += n
		}
		stk = append(stk, i)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validSubarrays(nums: number[]): number {
    const n = nums.length;
    const stk: number[] = [];
    let ans = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length && nums[stk.at(-1)!] >= nums[i]) {
            stk.pop();
        }
        ans += (stk.at(-1) ?? n) - i;
        stk.push(i);
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

<p>给定一个整数数组&nbsp;<code>nums</code>&nbsp;，返回满足下面条件的&nbsp;<em>非空、连续</em><strong>&nbsp;子数组</strong>的数目：</p>

<ul>
	<li><strong>子数组&nbsp;</strong>是数组的 <strong>连续</strong> 部分。</li>
	<li><em>子数组最左边的元素不大于子数组中的其他元素</em>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,2,5,3]
<strong>输出：</strong>11
<strong>解释：</strong>有 11 个有效子数组，分别是：[1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1]
<strong>输出：</strong>3
<strong>解释：</strong>有 3 个有效子数组，分别是：[3],[2],[1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2]
<strong>输出：</strong>6
<strong>解释：</strong>有 6 个有效子数组，分别为是：[2],[2],[2],[2,2],[2,2],[2,2,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

题目实际上是求解每个位置 $i$ 的右边第一个小于 $nums[i]$ 的位置 $j$，那么以 $i$ 为左端点的有效子数组的个数就是 $j - i$。

我们可以使用单调栈来求解右边第一个小于 $nums[i]$ 的位置 $j$，具体做法是从右往左遍历数组，维护一个从栈顶到栈底严格单调递减的栈。如果栈不为空，并且栈顶元素大于等于 $nums[i]$，那么就将栈顶元素出栈，直到栈为空或者栈顶元素小于 $nums[i]$，此时栈顶元素就是右边第一个小于 $nums[i]$ 的位置 $j$，如果栈为空，那么 $j = n$。

接下来，我们将 $i$ 入栈，继续遍历数组，直到遍历结束，最后我们就可以得到每个位置 $i$ 的右边第一个小于 $nums[i]$ 的位置 $j$，从而得到以 $i$ 为左端点的有效子数组的个数 $j-i$，将所有的 $j-i$ 累加即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        right = [n] * n
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        return sum(j - i for i, j in enumerate(right))
```

#### Java

```java
class Solution {
    public int validSubarrays(int[] nums) {
        int n = nums.length;
        int[] right = new int[n];
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += right[i] - i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (stk.size() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (stk.size()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += right[i] - i;
        }
        return ans;
    }
};
```

#### Go

```go
func validSubarrays(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n)
	for i := range right {
		right[i] = n
	}
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, j := range right {
		ans += j - i
	}
	return
}
```

#### TypeScript

```ts
function validSubarrays(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = n - 1; ~i; --i) {
        while (stk.length && nums[stk.at(-1)] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1)!;
        }
        stk.push(i);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += right[i] - i;
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
    def validSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        stk = []
        ans = 0
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            ans += (stk[-1] if stk else n) - i
            stk.append(i)
        return ans
```

#### Java

```java
class Solution {
    public int validSubarrays(int[] nums) {
        int n = nums.length;
        Deque<Integer> stk = new ArrayDeque<>();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            ans += (stk.isEmpty() ? n : stk.peek()) - i;

            stk.push(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        int ans = 0;
        for (int i = n - 1; ~i; --i) {
            while (stk.size() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            ans += (stk.size() ? stk.top() : n) - i;
            stk.push(i);
        }
        return ans;
    }
};
```

#### Go

```go
func validSubarrays(nums []int) (ans int) {
	n := len(nums)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= nums[i] {
			stk = stk[:len(stk)-1]
		}
		ans -= i
		if len(stk) > 0 {
			ans += stk[len(stk)-1]
		} else {
			ans += n
		}
		stk = append(stk, i)
	}
	return
}
```

#### TypeScript

```ts
function validSubarrays(nums: number[]): number {
    const n = nums.length;
    const stk: number[] = [];
    let ans = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length && nums[stk.at(-1)!] >= nums[i]) {
            stk.pop();
        }
        ans += (stk.at(-1) ?? n) - i;
        stk.push(i);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1064. 不动点 🔒](https://leetcode.cn/problems/fixed-point){#1064}

{{< tabs "1064" >}}

{{% tab "python" %}}
```python
class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) >> 1
            if arr[mid] >= mid:
                right = mid
            else:
                left = mid + 1
        return left if arr[left] == left else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int fixedPoint(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] >= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left] == left ? left : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (arr[mid] >= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left] == left ? left : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fixedPoint(arr []int) int {
	left, right := 0, len(arr)-1
	for left < right {
		mid := (left + right) >> 1
		if arr[mid] >= mid {
			right = mid
		} else {
			left = mid + 1
		}
	}
	if arr[left] == left {
		return left
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fixedPoint(arr: number[]): number {
    let left = 0;
    let right = arr.length - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (arr[mid] >= mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return arr[left] === left ? left : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定已经按 <strong>升序</strong> 排列、由不同整数组成的数组 <code>arr</code>，返回满足 <code>arr[i] == i</code> 的最小索引 <code>i</code>。如果不存在这样的 <code>i</code>，返回 <code>-1</code>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [-10,-5,0,3,7]
<strong>输出：</strong>3
<strong>解释：</strong>对于给定的数组，<code>arr[0] = -10，arr[1] = -5，arr[2] = 0，arr[3] = 3</code>，因此输出为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,2,5,8,17]
<strong>输出：</strong>0
<strong>解释：</strong><code>arr[0] = 0</code>，因此输出为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [-10,-5,3,4,7,9]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在这样的 i 满足 <code>arr[i] = i</code>，因此输出为 -1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length < 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> <= arr[i] <= 10<sup>9</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>时间复杂度为 <code>O(n)</code> 的解决方案很直观也很简单。你可以设计更优的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

题目给定的数组是按升序排列的，因此我们可以使用二分查找的方法找出最小的满足 $arr[i]$ 等于 $i$ 的下标 $i$。

我们定义二分查找的左边界 $left=0$，右边界 $right=n-1$。每一次，我们找到当前的中间位置 $mid$，如果中间位置满足 $arr[mid] \geq mid$，那么我们就确定了最小的不动点 🔒 的位置一定不会出现在下标大于 $mid$ 的位置，因此我们令 $right=mid$；如果中间位置满足 $arr[mid] \lt mid$，那么最小的不动点 🔒 一定出现在下标大于 $mid$ 的位置，因此我们令 $left=mid+1$。

最后，如果我们没有找到最小的不动点 🔒，那么我们返回 $-1$。

时间复杂度 $O(\log n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) >> 1
            if arr[mid] >= mid:
                right = mid
            else:
                left = mid + 1
        return left if arr[left] == left else -1
```

#### Java

```java
class Solution {
    public int fixedPoint(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] >= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left] == left ? left : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (arr[mid] >= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return arr[left] == left ? left : -1;
    }
};
```

#### Go

```go
func fixedPoint(arr []int) int {
	left, right := 0, len(arr)-1
	for left < right {
		mid := (left + right) >> 1
		if arr[mid] >= mid {
			right = mid
		} else {
			left = mid + 1
		}
	}
	if arr[left] == left {
		return left
	}
	return -1
}
```

#### TypeScript

```ts
function fixedPoint(arr: number[]): number {
    let left = 0;
    let right = arr.length - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (arr[mid] >= mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return arr[left] === left ? left : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1065. 字符串的索引对 🔒](https://leetcode.cn/problems/index-pairs-of-a-string){#1065}

{{< tabs "1065" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(text)
        ans = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(text[j]) - ord('a')
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    ans.append([i, j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public int[][] indexPairs(String text, String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        int n = text.length();
        List<int[]> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = text.charAt(j) - 'a';
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    ans.add(new int[] {i, j});
                }
            }
        }
        return ans.toArray(new int[ans.size()][2]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd = false;

    Trie() {
        children.resize(26);
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie* trie = new Trie();
        for (auto w : words) trie->insert(w);
        int n = text.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = text[j] - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		idx := int(c - 'a')
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func indexPairs(text string, words []string) [][]int {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(text)
	var ans [][]int
	for i := range text {
		node := trie
		for j := i; j < n; j++ {
			idx := int(text[j] - 'a')
			if node.children[idx] == nil {
				break
			}
			node = node.children[idx]
			if node.isEnd {
				ans = append(ans, []int{i, j})
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

<p>给出&nbsp;<strong>字符串 </strong><code>text</code> 和&nbsp;<strong>字符串列表</strong> <code>words</code>, 返回所有的索引对 <code>[i, j]</code> 使得子字符串 <code>text[i]...text[j]</code>（包括&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>）属于字符串列表 <code>words</code>。</p>

<p>按顺序返回索引对 <code>[i, j]</code>（即，按它们的第一个坐标进行排序，如果相同，则按它们的第二个坐标对它们进行排序）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
<strong>输出: </strong>[[3,7],[9,13],[10,17]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>text = "ababa", words = ["aba","ab"]
<strong>输出: </strong>[[0,1],[0,2],[2,3],[2,4]]
<strong>解释: 
</strong>注意，返回的配对可以有交叉，比如，"aba" 既在 [0,2] 中也在 [2,4] 中
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 100</code></li>
	<li><code>1 &lt;= words.length &lt;= 20</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>text</code>&nbsp;和&nbsp;<code>words[i]</code>&nbsp;都只包含小写字母。</li>
	<li>保证 <code>words</code> 中的字符串无重复。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        words = set(words)
        n = len(text)
        return [
            [i, j] for i in range(n) for j in range(i, n) if text[i : j + 1] in words
        ]
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public int[][] indexPairs(String text, String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        int n = text.length();
        List<int[]> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = text.charAt(j) - 'a';
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    ans.add(new int[] {i, j});
                }
            }
        }
        return ans.toArray(new int[ans.size()][2]);
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd = false;

    Trie() {
        children.resize(26);
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie* trie = new Trie();
        for (auto w : words) trie->insert(w);
        int n = text.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = text[j] - 'a';
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		idx := int(c - 'a')
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func indexPairs(text string, words []string) [][]int {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(text)
	var ans [][]int
	for i := range text {
		node := trie
		for j := i; j < n; j++ {
			idx := int(text[j] - 'a')
			if node.children[idx] == nil {
				break
			}
			node = node.children[idx]
			if node.isEnd {
				ans = append(ans, []int{i, j})
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀树

相似题目：

-   [616. 给字符串添加加粗标签](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0616.Add%20Bold%20Tag%20in%20String/README.md)
-   [758. 字符串中的加粗单词](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0758.Bold%20Words%20in%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(text)
        ans = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(text[j]) - ord('a')
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    ans.append([i, j])
        return ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1066. 校园自行车分配 II 🔒](https://leetcode.cn/problems/campus-bikes-ii){#1066}

{{< tabs "1066" >}}

{{% tab "python" %}}
```python
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        n, m = len(workers), len(bikes)
        f = [[inf] * (1 << m) for _ in range(n + 1)]
        f[0][0] = 0
        for i, (x1, y1) in enumerate(workers, 1):
            for j in range(1 << m):
                for k, (x2, y2) in enumerate(bikes):
                    if j >> k & 1:
                        f[i][j] = min(
                            f[i][j],
                            f[i - 1][j ^ (1 << k)] + abs(x1 - x2) + abs(y1 - y2),
                        )
        return min(f[n])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length;
        int m = bikes.length;
        int[][] f = new int[n + 1][1 << m];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if ((j >> k & 1) == 1) {
                        int d = Math.abs(workers[i - 1][0] - bikes[k][0])
                            + Math.abs(workers[i - 1][1] - bikes[k][1]);
                        f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return Arrays.stream(f[n]).min().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        int f[n + 1][1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (j >> k & 1) {
                        int d = abs(workers[i - 1][0] - bikes[k][0]) + abs(workers[i - 1][1] - bikes[k][1]);
                        f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return *min_element(f[n], f[n] + (1 << m));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func assignBikes(workers [][]int, bikes [][]int) int {
	n, m := len(workers), len(bikes)
	f := make([][]int, n+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, 1<<m)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 0; j < 1<<m; j++ {
			for k := 0; k < m; k++ {
				if j>>k&1 == 1 {
					d := abs(workers[i-1][0]-bikes[k][0]) + abs(workers[i-1][1]-bikes[k][1])
					f[i][j] = min(f[i][j], f[i-1][j^(1<<k)]+d)
				}
			}
		}
	}
	return slices.Min(f[n])
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
function assignBikes(workers: number[][], bikes: number[][]): number {
    const n = workers.length;
    const m = bikes.length;
    const inf = 1 << 30;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(1 << m).fill(inf));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            for (let k = 0; k < m; ++k) {
                if (((j >> k) & 1) === 1) {
                    const d =
                        Math.abs(workers[i - 1][0] - bikes[k][0]) +
                        Math.abs(workers[i - 1][1] - bikes[k][1]);
                    f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                }
            }
        }
    }
    return Math.min(...f[n]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在由 2D 网格表示的校园里有&nbsp;<code>n</code>&nbsp;位工人（<code>worker</code>）和 <code>m</code>&nbsp;辆自行车（<code>bike</code>），<code>n &lt;= m</code>。所有工人和自行车的位置都用网格上的 2D 坐标表示。</p>

<p>我们为每一位工人分配一辆专属自行车，使每个工人与其分配到的自行车之间的 <strong>曼哈顿距离</strong> 最小化。</p>

<p>返回 <code>每个工人与分配到的自行车之间的曼哈顿距离的最小可能总和</code> 。</p>

<p><code>p1</code> 和&nbsp;<code>p2</code>&nbsp;之间的 <strong>曼哈顿距离</strong> 为&nbsp;<code>Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1066.Campus%20Bikes%20II/images/1261_example_1_v2.png" /></p>

<pre>
<strong>输入：</strong>workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
<strong>输出：</strong>6
<strong>解释：</strong>
自行车 0 分配给工人 0，自行车 1 分配给工人 1 。分配得到的曼哈顿距离都是 3, 所以输出为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1066.Campus%20Bikes%20II/images/1261_example_2_v2.png" /></p>

<pre>
<strong>输入：</strong>workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
<strong>输出：</strong>4
<strong>解释：</strong>
先将自行车 0 分配给工人 0，再将自行车 1 分配给工人 1（或工人 2），自行车 2 给工人 2（或工人 1）。如此分配使得曼哈顿距离的总和为 4。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>workers = [[0,0],[1,0],[2,0],[3,0],[4,0]], bikes = [[0,999],[1,999],[2,999],[3,999],[4,999]]
<strong>输出：</strong>4995
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == workers.length</code></li>
	<li><code>m == bikes.length</code></li>
	<li><code>1 &lt;= n &lt;= m &lt;= 10</code></li>
	<li><code>workers[i].length == 2</code></li>
	<li><code>bikes[i].length == 2</code></li>
	<li><code>0 &lt;= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] &lt; 1000</code></li>
	<li>所有的工人和自行车的位置都是 <strong>不同</strong>&nbsp;的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个工人分配到自行车的状态为 $j$ 时的最小曼哈顿距离总和，其中 $j$ 是一个二进制数，表示自行车的分配情况。初始时 $f[0][0]=0$，其余 $f[0][j]=+\infty$。

考虑 $f[i][j]$，我们枚举第 $i$ 个工人分配到的自行车的编号 $k$，那么 $f[i][j]$ 可以从 $f[i-1][j\oplus 2^k]$ 转移而来，其中 $\oplus$ 表示异或运算。这是因为 $f[i-1][j\oplus 2^k]$ 表示前 $i-1$ 个工人分配到自行车的状态为 $j\oplus 2^k$ 时的最小曼哈顿距离总和，而第 $i$ 个工人分配到自行车 $k$ 时，其曼哈顿距离为 $|worker[i]-bike[k]|$，其中 $|x|$ 表示 $x$ 的绝对值。因此我们可以列出状态转移方程：

$$
f[i][j]=\min_{k=0}^{m-1}\{f[i-1][j\oplus 2^k]+|worker[i]-bike[k]|\}
$$

最终的答案为 $\min_{j=0}^{2^m-1}\{f[n][j]\}$。

时间复杂度 $O(n \times 2^m \times m)$，空间复杂度 $O(n \times 2^m)$。其中 $n$ 和 $m$ 分别是工人和自行车的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        n, m = len(workers), len(bikes)
        f = [[inf] * (1 << m) for _ in range(n + 1)]
        f[0][0] = 0
        for i, (x1, y1) in enumerate(workers, 1):
            for j in range(1 << m):
                for k, (x2, y2) in enumerate(bikes):
                    if j >> k & 1:
                        f[i][j] = min(
                            f[i][j],
                            f[i - 1][j ^ (1 << k)] + abs(x1 - x2) + abs(y1 - y2),
                        )
        return min(f[n])
```

#### Java

```java
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length;
        int m = bikes.length;
        int[][] f = new int[n + 1][1 << m];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if ((j >> k & 1) == 1) {
                        int d = Math.abs(workers[i - 1][0] - bikes[k][0])
                            + Math.abs(workers[i - 1][1] - bikes[k][1]);
                        f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return Arrays.stream(f[n]).min().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        int f[n + 1][1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (j >> k & 1) {
                        int d = abs(workers[i - 1][0] - bikes[k][0]) + abs(workers[i - 1][1] - bikes[k][1]);
                        f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                    }
                }
            }
        }
        return *min_element(f[n], f[n] + (1 << m));
    }
};
```

#### Go

```go
func assignBikes(workers [][]int, bikes [][]int) int {
	n, m := len(workers), len(bikes)
	f := make([][]int, n+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, 1<<m)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 0; j < 1<<m; j++ {
			for k := 0; k < m; k++ {
				if j>>k&1 == 1 {
					d := abs(workers[i-1][0]-bikes[k][0]) + abs(workers[i-1][1]-bikes[k][1])
					f[i][j] = min(f[i][j], f[i-1][j^(1<<k)]+d)
				}
			}
		}
	}
	return slices.Min(f[n])
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
function assignBikes(workers: number[][], bikes: number[][]): number {
    const n = workers.length;
    const m = bikes.length;
    const inf = 1 << 30;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(1 << m).fill(inf));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 1 << m; ++j) {
            for (let k = 0; k < m; ++k) {
                if (((j >> k) & 1) === 1) {
                    const d =
                        Math.abs(workers[i - 1][0] - bikes[k][0]) +
                        Math.abs(workers[i - 1][1] - bikes[k][1]);
                    f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + d);
                }
            }
        }
    }
    return Math.min(...f[n]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1067. 范围内的数字计数 🔒](https://leetcode.cn/problems/digit-count-in-range){#1067}

{{< tabs "1067" >}}

{{% tab "python" %}}
```python
class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        return self.f(high, d) - self.f(low - 1, d)

    def f(self, n, d):
        @cache
        def dfs(pos, cnt, lead, limit):
            if pos <= 0:
                return cnt
            up = a[pos] if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos - 1, cnt, lead, limit and i == up)
                else:
                    ans += dfs(pos - 1, cnt + (i == d), False, limit and i == up)
            return ans

        a = [0] * 11
        l = 0
        while n:
            l += 1
            a[l] = n % 10
            n //= 10
        return dfs(l, 0, True, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int d;
    private int[] a = new int[11];
    private int[][] dp = new int[11][11];

    public int digitsCount(int d, int low, int high) {
        this.d = d;
        return f(high) - f(low - 1);
    }

    private int f(int n) {
        for (var e : dp) {
            Arrays.fill(e, -1);
        }
        int len = 0;
        while (n > 0) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true, true);
    }

    private int dfs(int pos, int cnt, boolean lead, boolean limit) {
        if (pos <= 0) {
            return cnt;
        }
        if (!lead && !limit && dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos - 1, cnt, lead, limit && i == up);
            } else {
                ans += dfs(pos - 1, cnt + (i == d ? 1 : 0), false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            dp[pos][cnt] = ans;
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
    int d;
    int a[11];
    int dp[11][11];

    int digitsCount(int d, int low, int high) {
        this->d = d;
        return f(high) - f(low - 1);
    }

    int f(int n) {
        memset(dp, -1, sizeof dp);
        int len = 0;
        while (n) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true, true);
    }

    int dfs(int pos, int cnt, bool lead, bool limit) {
        if (pos <= 0) {
            return cnt;
        }
        if (!lead && !limit && dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos - 1, cnt, lead, limit && i == up);
            } else {
                ans += dfs(pos - 1, cnt + (i == d), false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            dp[pos][cnt] = ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func digitsCount(d int, low int, high int) int {
	f := func(n int) int {
		a := make([]int, 11)
		dp := make([][]int, 11)
		for i := range dp {
			dp[i] = make([]int, 11)
			for j := range dp[i] {
				dp[i][j] = -1
			}
		}
		l := 0
		for n > 0 {
			l++
			a[l] = n % 10
			n /= 10
		}

		var dfs func(int, int, bool, bool) int
		dfs = func(pos, cnt int, lead, limit bool) int {
			if pos <= 0 {
				return cnt
			}
			if !lead && !limit && dp[pos][cnt] != -1 {
				return dp[pos][cnt]
			}
			up := 9
			if limit {
				up = a[pos]
			}
			ans := 0
			for i := 0; i <= up; i++ {
				if i == 0 && lead {
					ans += dfs(pos-1, cnt, lead, limit && i == up)
				} else {
					t := cnt
					if d == i {
						t++
					}
					ans += dfs(pos-1, t, false, limit && i == up)
				}
			}
			if !lead && !limit {
				dp[pos][cnt] = ans
			}
			return ans
		}

		return dfs(l, 0, true, true)
	}
	return f(high) - f(low-1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个在 <code>0</code>&nbsp;到&nbsp;<code>9</code> 之间的整数&nbsp;<code>d</code>，和两个正整数&nbsp;<code>low</code>&nbsp;和&nbsp;<code>high</code>&nbsp;分别作为上下界。返回&nbsp;<code>d</code> 在&nbsp;<code>low</code>&nbsp;和&nbsp;<code>high</code>&nbsp;之间的整数中出现的次数，包括边界&nbsp;<code>low</code> 和&nbsp;<code>high</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>d = 1, low = 1, high = 13
<strong>输出：</strong>6
<strong>解释： </strong>
数字 <code>d=1</code> 在 <code>1,10,11,12,13 中出现 6 次</code>。注意 <code>d=1</code> 在数字 11 中出现两次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>d = 3, low = 100, high = 250
<strong>输出：</strong>35
<strong>解释：</strong>
数字 <code>d=3</code> 在 <code>103,113,123,130,131,...,238,239,243 出现 35 次。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 &lt;= d &lt;= 9</code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 2&times;10^8</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，数字中出现 $d$ 的个数。个数与数的位数以及每一位上的数字有关。我们可以用数位 DP 的思路来解决这道题。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

1. 将数字 $n$ 转为 int 数组 $a$，其中 $a[1]$ 为最低位，而 $a[len]$ 为最高位；
1. 根据题目信息，设计函数 $dfs()$，对于本题，我们定义 $dfs(pos, cnt, lead, limit)$，答案为 $dfs(len, 0, true, true)$。

其中：

-   `pos` 表示数字的位数，从末位或者第一位开始，一般根据题目的数字构造性质来选择顺序。对于本题，我们选择从高位开始，因此，`pos` 的初始值为 `len`；
-   `cnt` 表示当前数字中包含 $d$ 的个数；
-   `lead` 表示当前数字是否有前导零，如果有前导零，则 `lead` 为 `true`，否则为 `false`，初始化为 `true`；
-   `limit` 表示可填的数字的限制，如果无限制，那么可以选择 $[0,1,..9]$，否则，只能选择 $[0,..a[pos]]$。如果 `limit` 为 `true` 且已经取到了能取到的最大值，那么下一个 `limit` 同样为 `true`；如果 `limit` 为 `true` 但是还没有取到最大值，或者 `limit` 为 `false`，那么下一个 `limit` 为 `false`。

关于函数的实现细节，可以参考下面的代码。

时间复杂度 $O(\log m + \log n)$。其中 $m$, $n$ 分别为题目中的 `low` 和 `high`。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        return self.f(high, d) - self.f(low - 1, d)

    def f(self, n, d):
        @cache
        def dfs(pos, cnt, lead, limit):
            if pos <= 0:
                return cnt
            up = a[pos] if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos - 1, cnt, lead, limit and i == up)
                else:
                    ans += dfs(pos - 1, cnt + (i == d), False, limit and i == up)
            return ans

        a = [0] * 11
        l = 0
        while n:
            l += 1
            a[l] = n % 10
            n //= 10
        return dfs(l, 0, True, True)
```

#### Java

```java
class Solution {
    private int d;
    private int[] a = new int[11];
    private int[][] dp = new int[11][11];

    public int digitsCount(int d, int low, int high) {
        this.d = d;
        return f(high) - f(low - 1);
    }

    private int f(int n) {
        for (var e : dp) {
            Arrays.fill(e, -1);
        }
        int len = 0;
        while (n > 0) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true, true);
    }

    private int dfs(int pos, int cnt, boolean lead, boolean limit) {
        if (pos <= 0) {
            return cnt;
        }
        if (!lead && !limit && dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos - 1, cnt, lead, limit && i == up);
            } else {
                ans += dfs(pos - 1, cnt + (i == d ? 1 : 0), false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            dp[pos][cnt] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int d;
    int a[11];
    int dp[11][11];

    int digitsCount(int d, int low, int high) {
        this->d = d;
        return f(high) - f(low - 1);
    }

    int f(int n) {
        memset(dp, -1, sizeof dp);
        int len = 0;
        while (n) {
            a[++len] = n % 10;
            n /= 10;
        }
        return dfs(len, 0, true, true);
    }

    int dfs(int pos, int cnt, bool lead, bool limit) {
        if (pos <= 0) {
            return cnt;
        }
        if (!lead && !limit && dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos - 1, cnt, lead, limit && i == up);
            } else {
                ans += dfs(pos - 1, cnt + (i == d), false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            dp[pos][cnt] = ans;
        }
        return ans;
    }
};
```

#### Go

```go
func digitsCount(d int, low int, high int) int {
	f := func(n int) int {
		a := make([]int, 11)
		dp := make([][]int, 11)
		for i := range dp {
			dp[i] = make([]int, 11)
			for j := range dp[i] {
				dp[i][j] = -1
			}
		}
		l := 0
		for n > 0 {
			l++
			a[l] = n % 10
			n /= 10
		}

		var dfs func(int, int, bool, bool) int
		dfs = func(pos, cnt int, lead, limit bool) int {
			if pos <= 0 {
				return cnt
			}
			if !lead && !limit && dp[pos][cnt] != -1 {
				return dp[pos][cnt]
			}
			up := 9
			if limit {
				up = a[pos]
			}
			ans := 0
			for i := 0; i <= up; i++ {
				if i == 0 && lead {
					ans += dfs(pos-1, cnt, lead, limit && i == up)
				} else {
					t := cnt
					if d == i {
						t++
					}
					ans += dfs(pos-1, t, false, limit && i == up)
				}
			}
			if !lead && !limit {
				dp[pos][cnt] = ans
			}
			return ans
		}

		return dfs(l, 0, true, true)
	}
	return f(high) - f(low-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1068. 产品销售分析 I](https://leetcode.cn/problems/product-sales-analysis-i){#1068}

{{< tabs "1068" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT product_name, year, price
FROM
    Sales
    JOIN Product USING (product_id);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>销售表&nbsp;<code>Sales</code>：</p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) 是销售表 Sales 的主键（具有唯一值的列的组合）。
product_id 是关联到产品表 Product 的外键（reference 列）。
该表的每一行显示 product_id 在某一年的销售情况。
注意: price 表示每单位价格。
</pre>

<p>产品表&nbsp;<code>Product</code>：</p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id&nbsp;是表的主键（具有唯一值的列）。
该表的每一行表示每种产品的产品名称。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，以获取 <code>Sales</code>&nbsp;表中所有 <code>sale_id</code> 对应的&nbsp;<code>product_name</code> 以及该产品的所有<strong>&nbsp;</strong><code>year</code>&nbsp;和<strong>&nbsp;</strong><code>price</code> 。</p>

<p>返回结果表&nbsp;<strong>无顺序要求</strong> 。</p>

<p>结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Sales</code> 表：
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
Product 表：
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+
<strong>输出：</strong>
+--------------+-------+-------+
| product_name | year  | price |
+--------------+-------+-------+
| Nokia        | 2008  | 5000  |
| Nokia        | 2009  | 5000  |
| Apple        | 2011  | 9000  |
+--------------+-------+-------+
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 `JOIN` 内连接

我们直接使用 `JOIN` 连接 `Sales` 和 `Product` 两张表，连接字段为 `product_id`，然后选择需要的字段即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT product_name, year, price
FROM
    Sales
    JOIN Product USING (product_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1069. 产品销售分析 II 🔒](https://leetcode.cn/problems/product-sales-analysis-ii){#1069}

{{< tabs "1069" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT product_id, SUM(quantity) AS total_quantity
FROM Sales
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>销售表：<code>Sales</code></p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
sale_id 是这个表的主键（具有唯一值的列）。
product_id 是 Product 表的外键（reference 列）。
该表的每一行显示产品product_id在某一年的销售情况。
请注意价格是每单位的。
</pre>

<p>产品表：<code>Product</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id 是这个表的主键（具有唯一值的列）。
该表的每一行表示每种产品的产品名称。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，统计每个产品的销售总量。</p>

<p>返回结果表 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例子所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Sales</code> 表：
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
Product 表：
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+
<strong>输出：</strong>
+--------------+----------------+
| product_id   | total_quantity |
+--------------+----------------+
| 100          | 22             |
| 200          | 15             |
+--------------+----------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 `GROUP BY`

我们可以使用 `GROUP BY`，按照 `product_id` 分组，然后每一组对 `quantity` 求和。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT product_id, SUM(quantity) AS total_quantity
FROM Sales
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
