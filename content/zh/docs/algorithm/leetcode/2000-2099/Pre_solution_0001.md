---
title: "2000_反转单词前缀"
date: 2025-10-08T18:38:57+08:00
weight: 1
tags: [二分查找, 二叉树, 位运算, 动态规划, 博弈, 双指针, 哈希表, 回溯, 字符串, 并查集, 排序, 数学, 数据库, 数组, 数论, 栈, 树, 深度优先搜索, 滑动窗口, 状态压缩, 计数, 贪心]
---

{{< markmap >}}
### [2000_反转单词前缀](#2000)
#### [栈](#2000)
#### [双指针](#2000)
#### [字符串](#2000)
### [2001_可互换矩形的组数](#2001)
#### [数组](#2001)
#### [哈希表](#2001)
#### [数学](#2001)
#### [计数](#2001)
#### [数论](#2001)
### [2002_两个回文子序列长度的最大乘积](#2002)
#### [位运算](#2002)
#### [字符串](#2002)
#### [动态规划](#2002)
#### [回溯](#2002)
#### [状态压缩](#2002)
### [2003_每棵子树内缺失的最小基因值](#2003)
#### [树](#2003)
#### [深度优先搜索](#2003)
#### [并查集](#2003)
#### [动态规划](#2003)
### [2004_职员招聘人数 🔒](#2004)
#### [数据库](#2004)
### [2005_斐波那契树的移除子树游戏 🔒](#2005)
#### [树](#2005)
#### [数学](#2005)
#### [动态规划](#2005)
#### [二叉树](#2005)
#### [博弈](#2005)
### [2006_差的绝对值为 K 的数对数目](#2006)
#### [数组](#2006)
#### [哈希表](#2006)
#### [计数](#2006)
### [2007_从双倍数组中还原原数组](#2007)
#### [贪心](#2007)
#### [数组](#2007)
#### [哈希表](#2007)
#### [排序](#2007)
### [2008_出租车的最大盈利](#2008)
#### [数组](#2008)
#### [哈希表](#2008)
#### [二分查找](#2008)
#### [动态规划](#2008)
#### [排序](#2008)
### [2009_使数组连续的最少操作数](#2009)
#### [数组](#2009)
#### [哈希表](#2009)
#### [二分查找](#2009)
#### [滑动窗口](#2009)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2000_反转单词前缀
___
#### 栈
___
#### 双指针
___
#### 字符串
---
### 2001_可互换矩形的组数
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
___
#### 数论
---
### 2002_两个回文子序列长度的最大乘积
___
#### 位运算
___
#### 字符串
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 2003_每棵子树内缺失的最小基因值
___
#### 树
___
#### 深度优先搜索
___
#### 并查集
___
#### 动态规划
---
### 2004_职员招聘人数 🔒
___
#### 数据库
---
### 2005_斐波那契树的移除子树游戏 🔒
___
#### 树
___
#### 数学
___
#### 动态规划
___
#### 二叉树
___
#### 博弈
---
### 2006_差的绝对值为 K 的数对数目
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2007_从双倍数组中还原原数组
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2008_出租车的最大盈利
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 2009_使数组连续的最少操作数
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 动态规划 | 博弈 | 双指针 |
| 哈希表 | 回溯 | 字符串 |
| 并查集 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 栈 | 树 | 深度优先搜索 |
| 滑动窗口 | 状态压缩 | 计数 |
| 贪心 |  |  |

# [2000. 反转单词前缀](https://leetcode.cn/problems/reverse-prefix-of-word){#2000}

{{< tabs "2000" >}}

{{% tab "python" %}}
```python
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        i = word.find(ch)
        return word if i == -1 else word[i::-1] + word[i + 1 :]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reversePrefix(String word, char ch) {
        int j = word.indexOf(ch);
        if (j == -1) {
            return word;
        }
        char[] cs = word.toCharArray();
        for (int i = 0; i < j; ++i, --j) {
            char t = cs[i];
            cs[i] = cs[j];
            cs[j] = t;
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        if (i != string::npos) {
            reverse(word.begin(), word.begin() + i + 1);
        }
        return word;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reversePrefix(word string, ch byte) string {
	j := strings.IndexByte(word, ch)
	if j < 0 {
		return word
	}
	s := []byte(word)
	for i := 0; i < j; i++ {
		s[i], s[j] = s[j], s[i]
		j--
	}
	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reversePrefix(word: string, ch: string): string {
    const i = word.indexOf(ch) + 1;
    if (!i) {
        return word;
    }
    return [...word.slice(0, i)].reverse().join('') + word.slice(i);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        match word.find(ch) {
            Some(i) => word[..=i].chars().rev().collect::<String>() + &word[i + 1..],
            None => word,
        }
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $word
     * @param String $ch
     * @return String
     */
    function reversePrefix($word, $ch) {
        $len = strlen($word);
        $rs = '';
        for ($i = 0; $i < $len; $i++) {
            $rs = $rs . $word[$i];
            if ($word[$i] == $ch) {
                break;
            }
        }
        if (strlen($rs) == $len && $rs[$len - 1] != $ch) {
            return $word;
        }
        $rs = strrev($rs);
        $rs = $rs . substr($word, strlen($rs));
        return $rs;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> 和一个字符 <code>ch</code> 。找出 <code>ch</code> 第一次出现的下标 <code>i</code> ，<strong>反转 </strong><code>word</code> 中从下标 <code>0</code> 开始、直到下标 <code>i</code> 结束（含下标 <code>i</code> ）的那段字符。如果 <code>word</code> 中不存在字符 <code>ch</code> ，则无需进行任何操作。</p>

<ul>
	<li>例如，如果 <code>word = "abcdefd"</code> 且 <code>ch = 'd'</code>&nbsp;，那么你应该 <strong>反转</strong> 从下标 0 开始、直到下标 <code>3</code> 结束（含下标 <code>3</code> ）。结果字符串将会是 <code>"<em><strong>dcba</strong></em>efd"</code> 。</li>
</ul>

<p>返回 <strong>结果字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "<em><strong>abcd</strong></em>efd", ch = 'd'
<strong>输出：</strong>"<em><strong>dcba</strong></em>efd"
<strong>解释：</strong>"d" 第一次出现在下标 3 。 
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "dcbaefd" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "<em><strong>xyxz</strong></em>xe", ch = 'z'
<strong>输出：</strong>"<em><strong>zxyx</strong></em>xe"
<strong>解释：</strong>"z" 第一次也是唯一一次出现是在下标 3 。
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "zxyxxe" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "abcd", ch = 'z'
<strong>输出：</strong>"abcd"
<strong>解释：</strong>"z" 不存在于 word 中。
无需执行反转操作，结果字符串是 "abcd" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 250</code></li>
	<li><code>word</code> 由小写英文字母组成</li>
	<li><code>ch</code> 是一个小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先找到字符 $ch$ 第一次出现的下标 $i$，然后反转从下标 $0$ 开始、直到下标 $i$ 结束（含下标 $i$）的那段字符，最后将反转后的字符串与下标 $i + 1$ 开始的字符串拼接即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $word$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        i = word.find(ch)
        return word if i == -1 else word[i::-1] + word[i + 1 :]
```

#### Java

```java
class Solution {
    public String reversePrefix(String word, char ch) {
        int j = word.indexOf(ch);
        if (j == -1) {
            return word;
        }
        char[] cs = word.toCharArray();
        for (int i = 0; i < j; ++i, --j) {
            char t = cs[i];
            cs[i] = cs[j];
            cs[j] = t;
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        if (i != string::npos) {
            reverse(word.begin(), word.begin() + i + 1);
        }
        return word;
    }
};
```

#### Go

```go
func reversePrefix(word string, ch byte) string {
	j := strings.IndexByte(word, ch)
	if j < 0 {
		return word
	}
	s := []byte(word)
	for i := 0; i < j; i++ {
		s[i], s[j] = s[j], s[i]
		j--
	}
	return string(s)
}
```

#### TypeScript

```ts
function reversePrefix(word: string, ch: string): string {
    const i = word.indexOf(ch) + 1;
    if (!i) {
        return word;
    }
    return [...word.slice(0, i)].reverse().join('') + word.slice(i);
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        match word.find(ch) {
            Some(i) => word[..=i].chars().rev().collect::<String>() + &word[i + 1..],
            None => word,
        }
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $word
     * @param String $ch
     * @return String
     */
    function reversePrefix($word, $ch) {
        $len = strlen($word);
        $rs = '';
        for ($i = 0; $i < $len; $i++) {
            $rs = $rs . $word[$i];
            if ($word[$i] == $ch) {
                break;
            }
        }
        if (strlen($rs) == $len && $rs[$len - 1] != $ch) {
            return $word;
        }
        $rs = strrev($rs);
        $rs = $rs . substr($word, strlen($rs));
        return $rs;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2001. 可互换矩形的组数](https://leetcode.cn/problems/number-of-pairs-of-interchangeable-rectangles){#2001}

{{< tabs "2001" >}}

{{% tab "python" %}}
```python
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ans = 0
        cnt = Counter()
        for w, h in rectangles:
            g = gcd(w, h)
            w, h = w // g, h // g
            ans += cnt[(w, h)]
            cnt[(w, h)] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        long ans = 0;
        int n = rectangles.length + 1;
        Map<Long, Integer> cnt = new HashMap<>();
        for (var e : rectangles) {
            int w = e[0], h = e[1];
            int g = gcd(w, h);
            w /= g;
            h /= g;
            long x = (long) w * n + h;
            ans += cnt.getOrDefault(x, 0);
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        int n = rectangles.size();
        unordered_map<long long, int> cnt;
        for (auto& e : rectangles) {
            int w = e[0], h = e[1];
            int g = gcd(w, h);
            w /= g;
            h /= g;
            long long x = 1ll * w * (n + 1) + h;
            ans += cnt[x];
            cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func interchangeableRectangles(rectangles [][]int) int64 {
	ans := 0
	n := len(rectangles)
	cnt := map[int]int{}
	for _, e := range rectangles {
		w, h := e[0], e[1]
		g := gcd(w, h)
		w, h = w/g, h/g
		x := w*(n+1) + h
		ans += cnt[x]
		cnt[x]++
	}
	return int64(ans)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function (rectangles) {
    const cnt = new Map();
    let ans = 0;
    for (let [w, h] of rectangles) {
        const g = gcd(w, h);
        w = Math.floor(w / g);
        h = Math.floor(h / g);
        const x = w * (rectangles.length + 1) + h;
        ans += cnt.get(x) | 0;
        cnt.set(x, (cnt.get(x) | 0) + 1);
    }
    return ans;
};

function gcd(a, b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>用一个下标从 <strong>0</strong> 开始的二维整数数组&nbsp;<code>rectangles</code> 来表示 <code>n</code> 个矩形，其中 <code>rectangles[i] = [width<sub>i</sub>, height<sub>i</sub>]</code> 表示第 <code>i</code> 个矩形的宽度和高度。</p>

<p>如果两个矩形 <code>i</code> 和 <code>j</code>（<code>i &lt; j</code>）的宽高比相同，则认为这两个矩形 <strong>可互换</strong> 。更规范的说法是，两个矩形满足&nbsp;<code>width<sub>i</sub>/height<sub>i</sub> == width<sub>j</sub>/height<sub>j</sub></code>（使用实数除法而非整数除法），则认为这两个矩形 <strong>可互换</strong> 。</p>

<p>计算并返回&nbsp;<code>rectangles</code> 中有多少对 <strong>可互换 </strong>矩形。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rectangles = [[4,8],[3,6],[10,20],[15,30]]
<strong>输出：</strong>6
<strong>解释：</strong>下面按下标（从 0 开始）列出可互换矩形的配对情况：
- 矩形 0 和矩形 1 ：4/8 == 3/6
- 矩形 0 和矩形 2 ：4/8 == 10/20
- 矩形 0 和矩形 3 ：4/8 == 15/30
- 矩形 1 和矩形 2 ：3/6 == 10/20
- 矩形 1 和矩形 3 ：3/6 == 15/30
- 矩形 2 和矩形 3 ：10/20 == 15/30
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rectangles = [[4,5],[7,8]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在成对的可互换矩形。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rectangles.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>rectangles[i].length == 2</code></li>
	<li><code>1 &lt;= width<sub>i</sub>, height<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 哈希表

为了能够唯一表示矩形，我们需要将矩形的宽高比化简为最简分数。因此，我们可以求出每个矩形的宽高比的最大公约数，然后将宽高比化简为最简分数。接下来，我们使用哈希表统计每个最简分数的矩形数量，然后计算每个最简分数的矩形数量的组合数，即可得到答案。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n)$。其中 $n$ 和 $M$ 分别是矩形的数量和矩形的最大边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ans = 0
        cnt = Counter()
        for w, h in rectangles:
            g = gcd(w, h)
            w, h = w // g, h // g
            ans += cnt[(w, h)]
            cnt[(w, h)] += 1
        return ans
```

#### Java

```java
class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        long ans = 0;
        int n = rectangles.length + 1;
        Map<Long, Integer> cnt = new HashMap<>();
        for (var e : rectangles) {
            int w = e[0], h = e[1];
            int g = gcd(w, h);
            w /= g;
            h /= g;
            long x = (long) w * n + h;
            ans += cnt.getOrDefault(x, 0);
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        int n = rectangles.size();
        unordered_map<long long, int> cnt;
        for (auto& e : rectangles) {
            int w = e[0], h = e[1];
            int g = gcd(w, h);
            w /= g;
            h /= g;
            long long x = 1ll * w * (n + 1) + h;
            ans += cnt[x];
            cnt[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func interchangeableRectangles(rectangles [][]int) int64 {
	ans := 0
	n := len(rectangles)
	cnt := map[int]int{}
	for _, e := range rectangles {
		w, h := e[0], e[1]
		g := gcd(w, h)
		w, h = w/g, h/g
		x := w*(n+1) + h
		ans += cnt[x]
		cnt[x]++
	}
	return int64(ans)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### JavaScript

```js
/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function (rectangles) {
    const cnt = new Map();
    let ans = 0;
    for (let [w, h] of rectangles) {
        const g = gcd(w, h);
        w = Math.floor(w / g);
        h = Math.floor(h / g);
        const x = w * (rectangles.length + 1) + h;
        ans += cnt.get(x) | 0;
        cnt.set(x, (cnt.get(x) | 0) + 1);
    }
    return ans;
};

function gcd(a, b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2002. 两个回文子序列长度的最大乘积](https://leetcode.cn/problems/maximum-product-of-the-length-of-two-palindromic-subsequences){#2002}

{{< tabs "2002" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
        p = [True] * (1 << n)
        for k in range(1, 1 << n):
            i, j = 0, n - 1
            while i < j:
                while i < j and (k >> i & 1) == 0:
                    i += 1
                while i < j and (k >> j & 1) == 0:
                    j -= 1
                if i < j and s[i] != s[j]:
                    p[k] = False
                    break
                i, j = i + 1, j - 1
        ans = 0
        for i in range(1, 1 << n):
            if p[i]:
                mx = ((1 << n) - 1) ^ i
                j = mx
                a = i.bit_count()
                while j:
                    if p[j]:
                        b = j.bit_count()
                        ans = max(ans, a * b)
                    j = (j - 1) & mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProduct(String s) {
        int n = s.length();
        boolean[] p = new boolean[1 << n];
        Arrays.fill(p, true);
        for (int k = 1; k < 1 << n; ++k) {
            for (int i = 0, j = n - 1; i < n; ++i, --j) {
                while (i < j && (k >> i & 1) == 0) {
                    ++i;
                }
                while (i < j && (k >> j & 1) == 0) {
                    --j;
                }
                if (i < j && s.charAt(i) != s.charAt(j)) {
                    p[k] = false;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            if (p[i]) {
                int a = Integer.bitCount(i);
                int mx = ((1 << n) - 1) ^ i;
                for (int j = mx; j > 0; j = (j - 1) & mx) {
                    if (p[j]) {
                        int b = Integer.bitCount(j);
                        ans = Math.max(ans, a * b);
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
    int maxProduct(string s) {
        int n = s.size();
        vector<bool> p(1 << n, true);
        for (int k = 1; k < 1 << n; ++k) {
            for (int i = 0, j = n - 1; i < j; ++i, --j) {
                while (i < j && !(k >> i & 1)) {
                    ++i;
                }
                while (i < j && !(k >> j & 1)) {
                    --j;
                }
                if (i < j && s[i] != s[j]) {
                    p[k] = false;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            if (p[i]) {
                int a = __builtin_popcount(i);
                int mx = ((1 << n) - 1) ^ i;
                for (int j = mx; j; j = (j - 1) & mx) {
                    if (p[j]) {
                        int b = __builtin_popcount(j);
                        ans = max(ans, a * b);
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
func maxProduct(s string) (ans int) {
	n := len(s)
	p := make([]bool, 1<<n)
	for i := range p {
		p[i] = true
	}
	for k := 1; k < 1<<n; k++ {
		for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
			for i < j && (k>>i&1) == 0 {
				i++
			}
			for i < j && (k>>j&1) == 0 {
				j--
			}
			if i < j && s[i] != s[j] {
				p[k] = false
				break
			}
		}
	}
	for i := 1; i < 1<<n; i++ {
		if p[i] {
			a := bits.OnesCount(uint(i))
			mx := (1<<n - 1) ^ i
			for j := mx; j > 0; j = (j - 1) & mx {
				if p[j] {
					b := bits.OnesCount(uint(j))
					ans = max(ans, a*b)
				}
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你找到&nbsp;<code>s</code>&nbsp;中两个&nbsp;<strong>不相交回文子序列</strong>&nbsp;，使得它们长度的&nbsp;<strong>乘积最大</strong>&nbsp;。两个子序列在原字符串中如果没有任何相同下标的字符，则它们是&nbsp;<strong>不相交</strong>&nbsp;的。</p>

<p>请你返回两个回文子序列长度可以达到的<strong>&nbsp;最大乘积</strong>&nbsp;。</p>

<p><strong>子序列</strong>&nbsp;指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个 <strong>回文字符串</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2002.Maximum%20Product%20of%20the%20Length%20of%20Two%20Palindromic%20Subsequences/images/two-palindromic-subsequences.png" style="width: 550px; height: 124px;"></p>

<pre><b>输入：</b>s = "leetcodecom"
<b>输出：</b>9
<b>解释：</b>最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
它们的乘积为 3 * 3 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "bb"
<b>输出：</b>1
<b>解释：</b>最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
它们的乘积为 1 * 1 = 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "accbcaxxcxx"
<b>输出：</b>25
<b>解释：</b>最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
它们的乘积为 5 * 5 = 25 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code>&nbsp;只含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

我们注意到，字符串 $s$ 的长度不超过 $12$，因此我们可以使用二进制枚举的方法来枚举 $s$ 的所有子序列。不妨设 $s$ 的长度为 $n$，我们可以使用 $2^n$ 个长度为 $n$ 的二进制数来表示 $s$ 的所有子序列。对于每个二进制数，第 $i$ 位为 $1$ 表示 $s$ 的第 $i$ 个字符在子序列中，为 $0$ 表示不在子序列中。我们对于每个二进制数，判断其是否为回文子序列，并且记录在数组 $p$ 中。

接下来，我们枚举 $p$ 中的每个数 $i$，如果 $i$ 是回文子序列，那么我们可以从 $i$ 的补集 $mx = (2^n - 1) \oplus i$ 中枚举一个数 $j$，如果 $j$ 也是回文子序列，那么 $i$ 和 $j$ 就是我们要找的两个回文子序列，它们的长度分别为 $i$ 和 $j$ 的二进制表示中的 $1$ 的个数，我们记为 $a$ 和 $b$，那么它们的乘积就是 $a \times b$，我们取所有可能的 $a \times b$ 中的最大值即可。

时间复杂度 $(2^n \times n + 3^n)$，空间复杂度 $O(2^n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
        p = [True] * (1 << n)
        for k in range(1, 1 << n):
            i, j = 0, n - 1
            while i < j:
                while i < j and (k >> i & 1) == 0:
                    i += 1
                while i < j and (k >> j & 1) == 0:
                    j -= 1
                if i < j and s[i] != s[j]:
                    p[k] = False
                    break
                i, j = i + 1, j - 1
        ans = 0
        for i in range(1, 1 << n):
            if p[i]:
                mx = ((1 << n) - 1) ^ i
                j = mx
                a = i.bit_count()
                while j:
                    if p[j]:
                        b = j.bit_count()
                        ans = max(ans, a * b)
                    j = (j - 1) & mx
        return ans
```

#### Java

```java
class Solution {
    public int maxProduct(String s) {
        int n = s.length();
        boolean[] p = new boolean[1 << n];
        Arrays.fill(p, true);
        for (int k = 1; k < 1 << n; ++k) {
            for (int i = 0, j = n - 1; i < n; ++i, --j) {
                while (i < j && (k >> i & 1) == 0) {
                    ++i;
                }
                while (i < j && (k >> j & 1) == 0) {
                    --j;
                }
                if (i < j && s.charAt(i) != s.charAt(j)) {
                    p[k] = false;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            if (p[i]) {
                int a = Integer.bitCount(i);
                int mx = ((1 << n) - 1) ^ i;
                for (int j = mx; j > 0; j = (j - 1) & mx) {
                    if (p[j]) {
                        int b = Integer.bitCount(j);
                        ans = Math.max(ans, a * b);
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
    int maxProduct(string s) {
        int n = s.size();
        vector<bool> p(1 << n, true);
        for (int k = 1; k < 1 << n; ++k) {
            for (int i = 0, j = n - 1; i < j; ++i, --j) {
                while (i < j && !(k >> i & 1)) {
                    ++i;
                }
                while (i < j && !(k >> j & 1)) {
                    --j;
                }
                if (i < j && s[i] != s[j]) {
                    p[k] = false;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            if (p[i]) {
                int a = __builtin_popcount(i);
                int mx = ((1 << n) - 1) ^ i;
                for (int j = mx; j; j = (j - 1) & mx) {
                    if (p[j]) {
                        int b = __builtin_popcount(j);
                        ans = max(ans, a * b);
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
func maxProduct(s string) (ans int) {
	n := len(s)
	p := make([]bool, 1<<n)
	for i := range p {
		p[i] = true
	}
	for k := 1; k < 1<<n; k++ {
		for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
			for i < j && (k>>i&1) == 0 {
				i++
			}
			for i < j && (k>>j&1) == 0 {
				j--
			}
			if i < j && s[i] != s[j] {
				p[k] = false
				break
			}
		}
	}
	for i := 1; i < 1<<n; i++ {
		if p[i] {
			a := bits.OnesCount(uint(i))
			mx := (1<<n - 1) ^ i
			for j := mx; j > 0; j = (j - 1) & mx {
				if p[j] {
					b := bits.OnesCount(uint(j))
					ans = max(ans, a*b)
				}
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

# [2003. 每棵子树内缺失的最小基因值](https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree){#2003}

{{< tabs "2003" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestMissingValueSubtree(
        self, parents: List[int], nums: List[int]
    ) -> List[int]:
        def dfs(i: int):
            if vis[i]:
                return
            vis[i] = True
            if nums[i] < len(has):
                has[nums[i]] = True
            for j in g[i]:
                dfs(j)

        n = len(nums)
        ans = [1] * n
        g = [[] for _ in range(n)]
        idx = -1
        for i, p in enumerate(parents):
            if i:
                g[p].append(i)
            if nums[i] == 1:
                idx = i
        if idx == -1:
            return ans
        vis = [False] * n
        has = [False] * (n + 2)
        i = 2
        while idx != -1:
            dfs(idx)
            while has[i]:
                i += 1
            ans[idx] = i
            idx = parents[idx]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;
    private boolean[] has;
    private int[] nums;

    public int[] smallestMissingValueSubtree(int[] parents, int[] nums) {
        int n = nums.length;
        this.nums = nums;
        g = new List[n];
        vis = new boolean[n];
        has = new boolean[n + 2];
        Arrays.setAll(g, i -> new ArrayList<>());
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                g[parents[i]].add(i);
            }
            if (nums[i] == 1) {
                idx = i;
            }
        }
        int[] ans = new int[n];
        Arrays.fill(ans, 1);
        if (idx == -1) {
            return ans;
        }
        for (int i = 2; idx != -1; idx = parents[idx]) {
            dfs(idx);
            while (has[i]) {
                ++i;
            }
            ans[idx] = i;
        }
        return ans;
    }

    private void dfs(int i) {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        if (nums[i] < has.length) {
            has[nums[i]] = true;
        }
        for (int j : g[i]) {
            dfs(j);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        vector<int> g[n];
        bool vis[n];
        bool has[n + 2];
        memset(vis, false, sizeof(vis));
        memset(has, false, sizeof(has));
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (i) {
                g[parents[i]].push_back(i);
            }
            if (nums[i] == 1) {
                idx = i;
            }
        }
        vector<int> ans(n, 1);
        if (idx == -1) {
            return ans;
        }
        function<void(int)> dfs = [&](int i) {
            if (vis[i]) {
                return;
            }
            vis[i] = true;
            if (nums[i] < n + 2) {
                has[nums[i]] = true;
            }
            for (int j : g[i]) {
                dfs(j);
            }
        };
        for (int i = 2; ~idx; idx = parents[idx]) {
            dfs(idx);
            while (has[i]) {
                ++i;
            }
            ans[idx] = i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestMissingValueSubtree(parents []int, nums []int) []int {
	n := len(nums)
	g := make([][]int, n)
	vis := make([]bool, n)
	has := make([]bool, n+2)
	idx := -1
	ans := make([]int, n)
	for i, p := range parents {
		if i > 0 {
			g[p] = append(g[p], i)
		}
		if nums[i] == 1 {
			idx = i
		}
		ans[i] = 1
	}
	if idx < 0 {
		return ans
	}
	var dfs func(int)
	dfs = func(i int) {
		if vis[i] {
			return
		}
		vis[i] = true
		if nums[i] < len(has) {
			has[nums[i]] = true
		}
		for _, j := range g[i] {
			dfs(j)
		}
	}
	for i := 2; idx != -1; idx = parents[idx] {
		dfs(idx)
		for has[i] {
			i++
		}
		ans[idx] = i
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestMissingValueSubtree(parents: number[], nums: number[]): number[] {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const vis: boolean[] = Array(n).fill(false);
    const has: boolean[] = Array(n + 2).fill(false);
    const ans: number[] = Array(n).fill(1);
    let idx = -1;
    for (let i = 0; i < n; ++i) {
        if (i) {
            g[parents[i]].push(i);
        }
        if (nums[i] === 1) {
            idx = i;
        }
    }
    if (idx === -1) {
        return ans;
    }
    const dfs = (i: number): void => {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        if (nums[i] < has.length) {
            has[nums[i]] = true;
        }
        for (const j of g[i]) {
            dfs(j);
        }
    };
    for (let i = 2; ~idx; idx = parents[idx]) {
        dfs(idx);
        while (has[i]) {
            ++i;
        }
        ans[idx] = i;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_missing_value_subtree(parents: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        fn dfs(
            i: usize,
            vis: &mut Vec<bool>,
            has: &mut Vec<bool>,
            g: &Vec<Vec<usize>>,
            nums: &Vec<i32>,
        ) {
            if vis[i] {
                return;
            }
            vis[i] = true;
            if nums[i] < (has.len() as i32) {
                has[nums[i] as usize] = true;
            }
            for &j in &g[i] {
                dfs(j, vis, has, g, nums);
            }
        }

        let n = nums.len();
        let mut ans = vec![1; n];
        let mut g: Vec<Vec<usize>> = vec![vec![]; n];
        let mut idx = -1;
        for (i, &p) in parents.iter().enumerate() {
            if i > 0 {
                g[p as usize].push(i);
            }
            if nums[i] == 1 {
                idx = i as i32;
            }
        }
        if idx == -1 {
            return ans;
        }
        let mut vis = vec![false; n];
        let mut has = vec![false; (n + 2) as usize];
        let mut i = 2;
        let mut idx_mut = idx;
        while idx_mut != -1 {
            dfs(idx_mut as usize, &mut vis, &mut has, &g, &nums);
            while has[i] {
                i += 1;
            }
            ans[idx_mut as usize] = i as i32;
            idx_mut = parents[idx_mut as usize];
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

<p>有一棵根节点为 <code>0</code>&nbsp;的 <strong>家族树</strong>&nbsp;，总共包含 <code>n</code>&nbsp;个节点，节点编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组 <code>parents</code>&nbsp;，其中&nbsp;<code>parents[i]</code>&nbsp;是节点 <code>i</code>&nbsp;的父节点。由于节点 <code>0</code>&nbsp;是 <strong>根</strong>&nbsp;，所以&nbsp;<code>parents[0] == -1</code>&nbsp;。</p>

<p>总共有&nbsp;<code>10<sup>5</sup></code>&nbsp;个基因值，每个基因值都用 <strong>闭区间</strong>&nbsp;<code>[1, 10<sup>5</sup>]</code>&nbsp;中的一个整数表示。给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;是节点 <code>i</code>&nbsp;的基因值，且基因值 <strong>互不相同</strong>&nbsp;。</p>

<p>请你返回一个数组<em>&nbsp;</em><code>ans</code>&nbsp;，长度为&nbsp;<code>n</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;是以节点&nbsp;<code>i</code>&nbsp;为根的子树内 <b>缺失</b>&nbsp;的&nbsp;<strong>最小</strong>&nbsp;基因值。</p>

<p>节点 <code>x</code>&nbsp;为根的 <strong>子树&nbsp;</strong>包含节点 <code>x</code>&nbsp;和它所有的 <strong>后代</strong>&nbsp;节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2003.Smallest%20Missing%20Genetic%20Value%20in%20Each%20Subtree/images/case-1.png" style="width: 204px; height: 167px;"></p>

<pre><b>输入：</b>parents = [-1,0,0,2], nums = [1,2,3,4]
<b>输出：</b>[5,1,1,1]
<b>解释：</b>每个子树答案计算结果如下：
- 0：子树包含节点 [0,1,2,3] ，基因值分别为 [1,2,3,4] 。5 是缺失的最小基因值。
- 1：子树只包含节点 1 ，基因值为 2 。1 是缺失的最小基因值。
- 2：子树包含节点 [2,3] ，基因值分别为 [3,4] 。1 是缺失的最小基因值。
- 3：子树只包含节点 3 ，基因值为 4 。1是缺失的最小基因值。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2003.Smallest%20Missing%20Genetic%20Value%20in%20Each%20Subtree/images/case-2.png" style="width: 247px; height: 168px;"></p>

<pre><b>输入：</b>parents = [-1,0,1,0,3,3], nums = [5,4,6,2,1,3]
<b>输出：</b>[7,1,1,4,2,1]
<b>解释：</b>每个子树答案计算结果如下：
- 0：子树内包含节点 [0,1,2,3,4,5] ，基因值分别为 [5,4,6,2,1,3] 。7 是缺失的最小基因值。
- 1：子树内包含节点 [1,2] ，基因值分别为 [4,6] 。 1 是缺失的最小基因值。
- 2：子树内只包含节点 2 ，基因值为 6 。1 是缺失的最小基因值。
- 3：子树内包含节点 [3,4,5] ，基因值分别为 [2,1,3] 。4 是缺失的最小基因值。
- 4：子树内只包含节点 4 ，基因值为 1 。2 是缺失的最小基因值。
- 5：子树内只包含节点 5 ，基因值为 3 。1 是缺失的最小基因值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>parents = [-1,2,3,0,2,4,1], nums = [2,3,4,5,6,7,8]
<b>输出：</b>[1,1,1,1,1,1,1]
<b>解释：</b>所有子树都缺失基因值 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parents.length == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li>对于&nbsp;<code>i != 0</code>&nbsp;，满足&nbsp;<code>0 &lt;= parents[i] &lt;= n - 1</code></li>
	<li><code>parents[0] == -1</code></li>
	<li><code>parents</code>&nbsp;表示一棵合法的树。</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们注意到，每个节点的基因值互不相同，因此，我们只需要找到基因值为 $1$ 的节点 $idx$，那么除了从节点 $idx$ 到根节点 $0$ 的每个节点，其它节点的答案都是 $1$。

因此，我们初始化答案数组 $ans$ 为 $[1,1,...,1]$，然后我们的重点就在于求出节点 $idx$ 到根节点 $0$ 的路径上的每个节点的答案。

我们可以从节点 $idx$ 开始，通过深度优先搜索的方式，标记以 $idx$ 作为根节点的子树中出现过的基因值，记录在数组 $has$ 中。搜索过程中，我们用一个数组 $vis$ 标记已经访问过的节点，防止重复访问。

接下来，我们从 $i=2$ 开始，不断向后寻找第一个没有出现过的基因值，即为节点 $idx$ 的答案。这里 $i$ 是严格递增的，因为基因值互不相同，所以我们一定能在 $[1,..n+1]$ 中找到一个没有出现过的基因值。

然后，我们更新节点 $idx$ 的答案，即 $ans[idx]=i$，并将 $idx$ 更新为其父节点，继续上述过程，直到 $idx=-1$，即到达了根节点 $0$。

最后，我们返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestMissingValueSubtree(
        self, parents: List[int], nums: List[int]
    ) -> List[int]:
        def dfs(i: int):
            if vis[i]:
                return
            vis[i] = True
            if nums[i] < len(has):
                has[nums[i]] = True
            for j in g[i]:
                dfs(j)

        n = len(nums)
        ans = [1] * n
        g = [[] for _ in range(n)]
        idx = -1
        for i, p in enumerate(parents):
            if i:
                g[p].append(i)
            if nums[i] == 1:
                idx = i
        if idx == -1:
            return ans
        vis = [False] * n
        has = [False] * (n + 2)
        i = 2
        while idx != -1:
            dfs(idx)
            while has[i]:
                i += 1
            ans[idx] = i
            idx = parents[idx]
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;
    private boolean[] has;
    private int[] nums;

    public int[] smallestMissingValueSubtree(int[] parents, int[] nums) {
        int n = nums.length;
        this.nums = nums;
        g = new List[n];
        vis = new boolean[n];
        has = new boolean[n + 2];
        Arrays.setAll(g, i -> new ArrayList<>());
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                g[parents[i]].add(i);
            }
            if (nums[i] == 1) {
                idx = i;
            }
        }
        int[] ans = new int[n];
        Arrays.fill(ans, 1);
        if (idx == -1) {
            return ans;
        }
        for (int i = 2; idx != -1; idx = parents[idx]) {
            dfs(idx);
            while (has[i]) {
                ++i;
            }
            ans[idx] = i;
        }
        return ans;
    }

    private void dfs(int i) {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        if (nums[i] < has.length) {
            has[nums[i]] = true;
        }
        for (int j : g[i]) {
            dfs(j);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        vector<int> g[n];
        bool vis[n];
        bool has[n + 2];
        memset(vis, false, sizeof(vis));
        memset(has, false, sizeof(has));
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (i) {
                g[parents[i]].push_back(i);
            }
            if (nums[i] == 1) {
                idx = i;
            }
        }
        vector<int> ans(n, 1);
        if (idx == -1) {
            return ans;
        }
        function<void(int)> dfs = [&](int i) {
            if (vis[i]) {
                return;
            }
            vis[i] = true;
            if (nums[i] < n + 2) {
                has[nums[i]] = true;
            }
            for (int j : g[i]) {
                dfs(j);
            }
        };
        for (int i = 2; ~idx; idx = parents[idx]) {
            dfs(idx);
            while (has[i]) {
                ++i;
            }
            ans[idx] = i;
        }
        return ans;
    }
};
```

#### Go

```go
func smallestMissingValueSubtree(parents []int, nums []int) []int {
	n := len(nums)
	g := make([][]int, n)
	vis := make([]bool, n)
	has := make([]bool, n+2)
	idx := -1
	ans := make([]int, n)
	for i, p := range parents {
		if i > 0 {
			g[p] = append(g[p], i)
		}
		if nums[i] == 1 {
			idx = i
		}
		ans[i] = 1
	}
	if idx < 0 {
		return ans
	}
	var dfs func(int)
	dfs = func(i int) {
		if vis[i] {
			return
		}
		vis[i] = true
		if nums[i] < len(has) {
			has[nums[i]] = true
		}
		for _, j := range g[i] {
			dfs(j)
		}
	}
	for i := 2; idx != -1; idx = parents[idx] {
		dfs(idx)
		for has[i] {
			i++
		}
		ans[idx] = i
	}
	return ans
}
```

#### TypeScript

```ts
function smallestMissingValueSubtree(parents: number[], nums: number[]): number[] {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const vis: boolean[] = Array(n).fill(false);
    const has: boolean[] = Array(n + 2).fill(false);
    const ans: number[] = Array(n).fill(1);
    let idx = -1;
    for (let i = 0; i < n; ++i) {
        if (i) {
            g[parents[i]].push(i);
        }
        if (nums[i] === 1) {
            idx = i;
        }
    }
    if (idx === -1) {
        return ans;
    }
    const dfs = (i: number): void => {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        if (nums[i] < has.length) {
            has[nums[i]] = true;
        }
        for (const j of g[i]) {
            dfs(j);
        }
    };
    for (let i = 2; ~idx; idx = parents[idx]) {
        dfs(idx);
        while (has[i]) {
            ++i;
        }
        ans[idx] = i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_missing_value_subtree(parents: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        fn dfs(
            i: usize,
            vis: &mut Vec<bool>,
            has: &mut Vec<bool>,
            g: &Vec<Vec<usize>>,
            nums: &Vec<i32>,
        ) {
            if vis[i] {
                return;
            }
            vis[i] = true;
            if nums[i] < (has.len() as i32) {
                has[nums[i] as usize] = true;
            }
            for &j in &g[i] {
                dfs(j, vis, has, g, nums);
            }
        }

        let n = nums.len();
        let mut ans = vec![1; n];
        let mut g: Vec<Vec<usize>> = vec![vec![]; n];
        let mut idx = -1;
        for (i, &p) in parents.iter().enumerate() {
            if i > 0 {
                g[p as usize].push(i);
            }
            if nums[i] == 1 {
                idx = i as i32;
            }
        }
        if idx == -1 {
            return ans;
        }
        let mut vis = vec![false; n];
        let mut has = vec![false; (n + 2) as usize];
        let mut i = 2;
        let mut idx_mut = idx;
        while idx_mut != -1 {
            dfs(idx_mut as usize, &mut vis, &mut has, &g, &nums);
            while has[i] {
                i += 1;
            }
            ans[idx_mut as usize] = i as i32;
            idx_mut = parents[idx_mut as usize];
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

# [2004. 职员招聘人数 🔒](https://leetcode.cn/problems/the-number-of-seniors-and-juniors-to-join-the-company){#2004}

{{< tabs "2004" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            employee_id,
            SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Senior'
    ),
    j AS (
        SELECT
            employee_id,
            IFNULL(
                SELECT
                    MAX(cur)
                FROM s
                WHERE cur <= 70000,
                0
            ) + SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Junior'
    )
SELECT
    'Senior' AS experience,
    COUNT(employee_id) AS accepted_candidates
FROM s
WHERE cur <= 70000
UNION ALL
SELECT
    'Junior' AS experience,
    COUNT(employee_id) AS accepted_candidates
FROM j
WHERE cur <= 70000;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Candidates</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| employee_id | int  |
| experience  | enum |
| salary      | int  |
+-------------+------+
employee_id是此表的主键列。
经验是包含一个值（“高级”、“初级”）的枚举类型。
此表的每一行都显示候选人的id、月薪和经验。</pre>

<p>&nbsp;</p>

<p>一家公司想雇佣新员工。公司的工资预算是 <code>70000</code> 美元。公司的招聘标准是：</p>

<ol>
	<li>雇佣最多的高级员工。</li>
	<li>在雇佣最多的高级员工后，使用剩余预算雇佣最多的初级员工。</li>
</ol>

<p>编写一个SQL查询，查找根据上述标准雇佣的高级员工和初级员工的数量。<br />
按 <strong>任意顺序</strong> 返回结果表。<br />
查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 10000  |
| 9           | Junior     | 10000  |
| 2           | Senior     | 20000  |
| 11          | Senior     | 20000  |
| 13          | Senior     | 50000  |
| 4           | Junior     | 40000  |
+-------------+------------+--------+
<strong>输出:</strong> 
+------------+---------------------+
| experience | accepted_candidates |
+------------+---------------------+
| Senior     | 2                   |
| Junior     | 2                   |
+------------+---------------------+
<strong>说明：
我们可以雇佣2名ID为（2,11）的高级员工。由于预算是7万美元，他们的工资总额是4万美元，我们还有3万美元，但他们不足以雇佣ID为13的高级员工。
我们可以雇佣2名ID为（1,9）的初级员工。由于剩下的预算是3万美元，他们的工资总额是2万美元，我们还有1万美元，但他们不足以雇佣ID为4的初级员工。
</strong></pre>

<strong>示例 2：</strong>

<pre>
<strong>输入:</strong> 
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 10000  |
| 9           | Junior     | 10000  |
| 2           | Senior     | 80000  |
| 11          | Senior     | 80000  |
| 13          | Senior     | 80000  |
| 4           | Junior     | 40000  |
+-------------+------------+--------+
<strong>输出:</strong> 
+------------+---------------------+
| experience | accepted_candidates |
+------------+---------------------+
| Senior     | 0                   |
| Junior     | 3                   |
+------------+---------------------+
<strong>解释：
</strong>我们不能用目前的预算雇佣任何高级员工，因为我们需要至少80000美元来雇佣一名高级员工。
我们可以用剩下的预算雇佣三名初级员工。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

相似题目：

-   [2010. 职员招聘人数 🔒 II](https://github.com/doocs/leetcode/blob/main/solution/2000-2099/2010.The%20Number%20of%20Seniors%20and%20Juniors%20to%20Join%20the%20Company%20II/README.md)

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            employee_id,
            SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Senior'
    ),
    j AS (
        SELECT
            employee_id,
            IFNULL(
                SELECT
                    MAX(cur)
                FROM s
                WHERE cur <= 70000,
                0
            ) + SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Junior'
    )
SELECT
    'Senior' AS experience,
    COUNT(employee_id) AS accepted_candidates
FROM s
WHERE cur <= 70000
UNION ALL
SELECT
    'Junior' AS experience,
    COUNT(employee_id) AS accepted_candidates
FROM j
WHERE cur <= 70000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2005. 斐波那契树的移除子树游戏 🔒](https://leetcode.cn/problems/subtree-removal-game-with-fibonacci-tree){#2005}

{{< tabs "2005" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>斐波那契</strong>树是一种按这种规则函数&nbsp;<code>order(n)</code>&nbsp;创建的二叉树：</p>

<ul>
	<li><code>order(0)</code> 是空树。</li>
	<li><code>order(1)</code>&nbsp;是一棵<strong>只有一个节点</strong>的二叉树。</li>
	<li><code>order(n)</code>&nbsp;是一棵根节点的左子树为&nbsp;<code>order(n - 2)</code>&nbsp;、右子树为&nbsp;<code>order(n - 1)</code>&nbsp;的二叉树。</li>
</ul>

<p>Alice 和&nbsp;Bob 在玩一种关于<strong>斐波那契</strong>树的游戏，由 Alice 先手。在每个回合中，每个玩家选择一个节点，然后移除该节点<strong>及</strong>其子树。只能删除根节点&nbsp;<code>root</code>&nbsp;的玩家输掉这场游戏。</p>

<p>给定一个整数&nbsp;<code>n</code>，假定两名玩家都按最优策略进行游戏，若 Alice 赢得这场游戏，返回&nbsp;<code>true</code>&nbsp;。若 Bob 赢得这场游戏，返回&nbsp;<code>false</code>&nbsp;。</p>

<p>一棵二叉树的子树&nbsp;<code>tree</code> 是由&nbsp;<code>tree</code>&nbsp;中某个节点及其所有后代节点组成的树。树&nbsp;<code>tree</code>&nbsp;也可当作自身的子树。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2005.Subtree%20Removal%20Game%20with%20Fibonacci%20Tree/images/image-20210914173520-3.png" style="width: 200px; height: 184px;" /></p>

<pre>
<strong>输入:</strong> n = 3
<strong>输出:</strong> true
<strong>解释:</strong>
Alice 移除右子树中的节点 1。
Bob 要么移除左子树中的 1，要么移除右子树中的 2。
Alice 可以移除 Bob 未移除的任意节点。
Bob 只能删除根节点 3，所以 Bob 输了。
返回 true，因为 Alice 赢了。
</pre>

<p><strong>示例 2:</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2005.Subtree%20Removal%20Game%20with%20Fibonacci%20Tree/images/image-20210914173634-4.png" style="width: 75px; height: 75px;" /></p>

<pre>
<strong>输入:</strong> n = 1
<strong>输出:</strong> false
<strong>解释:</strong>
Alice 只能移除根节点 1, 所以 Alice 输了。
返回 false，因为 Alice 输了。
</pre>

<p><strong>示例 3:</strong><br />
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2005.Subtree%20Removal%20Game%20with%20Fibonacci%20Tree/images/image-20210914173425-1.png" style="width: 100px; height: 106px;" /></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> true
<strong>解释:</strong>
Alice 删除节点 1.
Bob 只能删除根节点 2，所以 Bob 输了。
返回 true，因为 Alice 赢了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2006. 差的绝对值为 K 的数对数目](https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k){#2006}

{{< tabs "2006" >}}

{{% tab "python" %}}
```python
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans = 0
        cnt = Counter()
        for num in nums:
            ans += cnt[num - k] + cnt[num + k]
            cnt[num] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countKDifference(int[] nums, int k) {
        int ans = 0;
        int[] cnt = new int[110];
        for (int num : nums) {
            if (num >= k) {
                ans += cnt[num - k];
            }
            if (num + k <= 100) {
                ans += cnt[num + k];
            }
            ++cnt[num];
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
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        int cnt[110]{};
        for (int num : nums) {
            if (num >= k) {
                ans += cnt[num - k];
            }
            if (num + k <= 100) {
                ans += cnt[num + k];
            }
            ++cnt[num];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKDifference(nums []int, k int) (ans int) {
	cnt := [110]int{}
	for _, num := range nums {
		if num >= k {
			ans += cnt[num-k]
		}
		if num+k <= 100 {
			ans += cnt[num+k]
		}
		cnt[num]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKDifference(nums: number[], k: number): number {
    let ans = 0;
    let cnt = new Map();
    for (let num of nums) {
        ans += (cnt.get(num - k) || 0) + (cnt.get(num + k) || 0);
        cnt.set(num, (cnt.get(num) || 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut arr = [0; 101];
        let mut res = 0;
        for num in nums {
            if num - k >= 1 {
                res += arr[(num - k) as usize];
            }
            if num + k <= 100 {
                res += arr[(num + k) as usize];
            }
            arr[num as usize] += 1;
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回数对&nbsp;<code>(i, j)</code>&nbsp;的数目，满足&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>|nums[i] - nums[j]| == k</code>&nbsp;。</p>

<p><code>|x|</code>&nbsp;的值定义为：</p>

<ul>
	<li>如果&nbsp;<code>x &gt;= 0</code>&nbsp;，那么值为&nbsp;<code>x</code>&nbsp;。</li>
	<li>如果&nbsp;<code>x &lt; 0</code>&nbsp;，那么值为&nbsp;<code>-x</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,2,1], k = 1
<b>输出：</b>4
<b>解释：</b>差的绝对值为 1 的数对为：
- [<em><strong>1</strong></em>,<em><strong>2</strong></em>,2,1]
- [<em><strong>1</strong></em>,2,<em><strong>2</strong></em>,1]
- [1,<em><strong>2</strong></em>,2,<em><strong>1</strong></em>]
- [1,2,<em><strong>2</strong></em>,<em><strong>1</strong></em>]
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,3], k = 3
<b>输出：</b>0
<b>解释：</b>没有任何数对差的绝对值为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [3,2,1,5,4], k = 2
<b>输出：</b>3
<b>解释：</b>差的绝对值为 2 的数对为：
- [<em><strong>3</strong></em>,2,<em><strong>1</strong></em>,5,4]
- [<em><strong>3</strong></em>,2,1,<em><strong>5</strong></em>,4]
- [3,<em><strong>2</strong></em>,1,5,<em><strong>4</strong></em>]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 99</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们注意到，数组 $nums$ 的长度不超过 $200$，因此我们可以枚举所有的数对 $(i, j)$，其中 $i < j$，并判断 $|nums[i] - nums[j]|$ 是否等于 $k$，是则答案加一。

最后返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)
        return sum(
            abs(nums[i] - nums[j]) == k for i in range(n) for j in range(i + 1, n)
        )
```

#### Java

```java
class Solution {
    public int countKDifference(int[] nums, int k) {
        int ans = 0;
        for (int i = 0, n = nums.length; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (Math.abs(nums[i] - nums[j]) == k) {
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
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += abs(nums[i] - nums[j]) == k;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countKDifference(nums []int, k int) int {
	n := len(nums)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) == k {
				ans++
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}
```

#### TypeScript

```ts
function countKDifference(nums: number[], k: number): number {
    let ans = 0;
    let cnt = new Map();
    for (let num of nums) {
        ans += (cnt.get(num - k) || 0) + (cnt.get(num + k) || 0);
        cnt.set(num, (cnt.get(num) || 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut res = 0;
        let n = nums.len();
        for i in 0..n - 1 {
            for j in i..n {
                if (nums[i] - nums[j]).abs() == k {
                    res += 1;
                }
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表或数组

我们可以使用哈希表或数组记录数组 $nums$ 中每个数出现的次数，然后枚举数组 $nums$ 中的每个数 $x$，判断 $x + k$ 和 $x - k$ 是否在数组 $nums$ 中，是则答案加上 $x+k$ 和 $x-k$ 出现的次数之和。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans = 0
        cnt = Counter()
        for num in nums:
            ans += cnt[num - k] + cnt[num + k]
            cnt[num] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countKDifference(int[] nums, int k) {
        int ans = 0;
        int[] cnt = new int[110];
        for (int num : nums) {
            if (num >= k) {
                ans += cnt[num - k];
            }
            if (num + k <= 100) {
                ans += cnt[num + k];
            }
            ++cnt[num];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        int cnt[110]{};
        for (int num : nums) {
            if (num >= k) {
                ans += cnt[num - k];
            }
            if (num + k <= 100) {
                ans += cnt[num + k];
            }
            ++cnt[num];
        }
        return ans;
    }
};
```

#### Go

```go
func countKDifference(nums []int, k int) (ans int) {
	cnt := [110]int{}
	for _, num := range nums {
		if num >= k {
			ans += cnt[num-k]
		}
		if num+k <= 100 {
			ans += cnt[num+k]
		}
		cnt[num]++
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut arr = [0; 101];
        let mut res = 0;
        for num in nums {
            if num - k >= 1 {
                res += arr[(num - k) as usize];
            }
            if num + k <= 100 {
                res += arr[(num + k) as usize];
            }
            arr[num as usize] += 1;
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

# [2007. 从双倍数组中还原原数组](https://leetcode.cn/problems/find-original-array-from-doubled-array){#2007}

{{< tabs "2007" >}}

{{% tab "python" %}}
```python
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        cnt = Counter(changed)
        ans = []
        for x in changed:
            if cnt[x] == 0:
                continue
            cnt[x] -= 1
            if cnt[x << 1] <= 0:
                return []
            cnt[x << 1] -= 1
            ans.append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        Arrays.sort(changed);
        int[] cnt = new int[changed[n - 1] + 1];
        for (int x : changed) {
            ++cnt[x];
        }
        int[] ans = new int[n >> 1];
        int i = 0;
        for (int x : changed) {
            if (cnt[x] == 0) {
                continue;
            }
            --cnt[x];
            int y = x << 1;
            if (y >= cnt.length || cnt[y] <= 0) {
                return new int[0];
            }
            --cnt[y];
            ans[i++] = x;
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
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> cnt(changed.back() + 1);
        for (int x : changed) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x : changed) {
            if (cnt[x] == 0) {
                continue;
            }
            --cnt[x];
            int y = x << 1;
            if (y >= cnt.size() || cnt[y] <= 0) {
                return {};
            }
            --cnt[y];
            ans.push_back(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findOriginalArray(changed []int) (ans []int) {
	sort.Ints(changed)
	cnt := make([]int, changed[len(changed)-1]+1)
	for _, x := range changed {
		cnt[x]++
	}
	for _, x := range changed {
		if cnt[x] == 0 {
			continue
		}
		cnt[x]--
		y := x << 1
		if y >= len(cnt) || cnt[y] <= 0 {
			return []int{}
		}
		cnt[y]--
		ans = append(ans, x)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findOriginalArray(changed: number[]): number[] {
    changed.sort((a, b) => a - b);
    const cnt: number[] = Array(changed.at(-1)! + 1).fill(0);
    for (const x of changed) {
        ++cnt[x];
    }
    const ans: number[] = [];
    for (const x of changed) {
        if (cnt[x] === 0) {
            continue;
        }
        cnt[x]--;
        const y = x << 1;
        if (y >= cnt.length || cnt[y] <= 0) {
            return [];
        }
        cnt[y]--;
        ans.push(x);
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

<p>一个整数数组&nbsp;<code>original</code>&nbsp;可以转变成一个 <strong>双倍</strong>&nbsp;数组&nbsp;<code>changed</code>&nbsp;，转变方式为将 <code>original</code>&nbsp;中每个元素 <strong>值乘以 2 </strong>加入数组中，然后将所有元素 <strong>随机打乱</strong>&nbsp;。</p>

<p>给你一个数组&nbsp;<code>changed</code>&nbsp;，如果&nbsp;<code>change</code>&nbsp;是&nbsp;<strong>双倍</strong>&nbsp;数组，那么请你返回&nbsp;<code>original</code>数组，否则请返回空数组。<code>original</code>&nbsp;的元素可以以&nbsp;<strong>任意</strong>&nbsp;顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>changed = [1,3,4,2,6,8]
<b>输出：</b>[1,3,4]
<b>解释：</b>一个可能的 original 数组为 [1,3,4] :
- 将 1 乘以 2 ，得到 1 * 2 = 2 。
- 将 3 乘以 2 ，得到 3 * 2 = 6 。
- 将 4 乘以 2 ，得到 4 * 2 = 8 。
其他可能的原数组方案为 [4,3,1] 或者 [3,1,4] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>changed = [6,3,0,1]
<b>输出：</b>[]
<b>解释：</b>changed 不是一个双倍数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>changed = [1]
<b>输出：</b>[]
<b>解释：</b>changed 不是一个双倍数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= changed.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= changed[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们注意到，如果数组 `changed` 是一个双倍数组，那么数组 `changed` 中最小的元素也一定是原数组中的元素，因此，我们可以先对数组 `changed` 进行排序，然后以第一个元素作为起点，从小到大遍历数组 `changed`。

我们使用一个哈希表或数组 $cnt$ 来统计数组 `changed` 中每个元素的出现次数。对于数组 `changed` 中的每个元素 $x$，我们首先检查 $x$ 是否存在于 $cnt$ 中。如果不存在，我们直接跳过这个元素。否则，我们将 $cnt[x]$ 减一，并检查 $x \times 2$ 是否存在于 $cnt$ 中。如果不存在，我们直接返回一个空数组。否则，我们将 $cnt[x \times 2]$ 减一，并将 $x$ 加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$，其中 $n$ 为数组 `changed` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        cnt = Counter(changed)
        ans = []
        for x in changed:
            if cnt[x] == 0:
                continue
            cnt[x] -= 1
            if cnt[x << 1] <= 0:
                return []
            cnt[x << 1] -= 1
            ans.append(x)
        return ans
```

#### Java

```java
class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        Arrays.sort(changed);
        int[] cnt = new int[changed[n - 1] + 1];
        for (int x : changed) {
            ++cnt[x];
        }
        int[] ans = new int[n >> 1];
        int i = 0;
        for (int x : changed) {
            if (cnt[x] == 0) {
                continue;
            }
            --cnt[x];
            int y = x << 1;
            if (y >= cnt.length || cnt[y] <= 0) {
                return new int[0];
            }
            --cnt[y];
            ans[i++] = x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> cnt(changed.back() + 1);
        for (int x : changed) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x : changed) {
            if (cnt[x] == 0) {
                continue;
            }
            --cnt[x];
            int y = x << 1;
            if (y >= cnt.size() || cnt[y] <= 0) {
                return {};
            }
            --cnt[y];
            ans.push_back(x);
        }
        return ans;
    }
};
```

#### Go

```go
func findOriginalArray(changed []int) (ans []int) {
	sort.Ints(changed)
	cnt := make([]int, changed[len(changed)-1]+1)
	for _, x := range changed {
		cnt[x]++
	}
	for _, x := range changed {
		if cnt[x] == 0 {
			continue
		}
		cnt[x]--
		y := x << 1
		if y >= len(cnt) || cnt[y] <= 0 {
			return []int{}
		}
		cnt[y]--
		ans = append(ans, x)
	}
	return
}
```

#### TypeScript

```ts
function findOriginalArray(changed: number[]): number[] {
    changed.sort((a, b) => a - b);
    const cnt: number[] = Array(changed.at(-1)! + 1).fill(0);
    for (const x of changed) {
        ++cnt[x];
    }
    const ans: number[] = [];
    for (const x of changed) {
        if (cnt[x] === 0) {
            continue;
        }
        cnt[x]--;
        const y = x << 1;
        if (y >= cnt.length || cnt[y] <= 0) {
            return [];
        }
        cnt[y]--;
        ans.push(x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2008. 出租车的最大盈利](https://leetcode.cn/problems/maximum-earnings-from-taxi){#2008}

{{< tabs "2008" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        rides.sort(key=lambda x: x[1])
        f = [0] * (len(rides) + 1)
        for i, (st, ed, tip) in enumerate(rides, 1):
            j = bisect_left(rides, st + 1, hi=i, key=lambda x: x[1])
            f[i] = max(f[i - 1], f[j] + ed - st + tip)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[1] - b[1]);
        int m = rides.length;
        long[] f = new long[m + 1];
        for (int i = 1; i <= m; ++i) {
            int[] r = rides[i - 1];
            int st = r[0], ed = r[1], tip = r[2];
            int j = search(rides, st + 1, i);
            f[i] = Math.max(f[i - 1], f[j] + ed - st + tip);
        }
        return f[m];
    }

    private int search(int[][] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int m = rides.size();
        vector<long long> f(m + 1);
        for (int i = 1; i <= m; ++i) {
            auto& r = rides[i - 1];
            int st = r[0], ed = r[1], tip = r[2];
            auto it = lower_bound(rides.begin(), rides.begin() + i, st + 1, [](auto& a, int val) { return a[1] < val; });
            int j = distance(rides.begin(), it);
            f[i] = max(f[i - 1], f[j] + ed - st + tip);
        }
        return f.back();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTaxiEarnings(n int, rides [][]int) int64 {
	sort.Slice(rides, func(i, j int) bool { return rides[i][1] < rides[j][1] })
	m := len(rides)
	f := make([]int64, m+1)
	for i := 1; i <= m; i++ {
		r := rides[i-1]
		st, ed, tip := r[0], r[1], r[2]
		j := sort.Search(m, func(j int) bool { return rides[j][1] >= st+1 })
		f[i] = max(f[i-1], f[j]+int64(ed-st+tip))
	}
	return f[m]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTaxiEarnings(n: number, rides: number[][]): number {
    rides.sort((a, b) => a[1] - b[1]);
    const m = rides.length;
    const f: number[] = Array(m + 1).fill(0);
    const search = (x: number, r: number): number => {
        let l = 0;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (rides[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= m; ++i) {
        const [st, ed, tip] = rides[i - 1];
        const j = search(st + 1, i);
        f[i] = Math.max(f[i - 1], f[j] + ed - st + tip);
    }
    return f[m];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你驾驶出租车行驶在一条有 <code>n</code>&nbsp;个地点的路上。这 <code>n</code>&nbsp;个地点从近到远编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;，你想要从 <code>1</code>&nbsp;开到 <code>n</code>&nbsp;，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。</p>

<p>乘客信息用一个下标从 <strong>0</strong>&nbsp;开始的二维数组&nbsp;<code>rides</code>&nbsp;表示，其中&nbsp;<code>rides[i] = [start<sub>i</sub>, end<sub>i</sub>, tip<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;位乘客需要从地点&nbsp;<code>start<sub>i</sub></code>&nbsp;前往&nbsp;<code>end<sub>i</sub></code>&nbsp;，愿意支付&nbsp;<code>tip<sub>i</sub></code>&nbsp;元的小费。</p>

<p><strong>每一位</strong> 你选择接单的乘客&nbsp;<code>i</code>&nbsp;，你可以 <strong>盈利</strong>&nbsp;<code>end<sub>i</sub> - start<sub>i</sub> + tip<sub>i</sub></code>&nbsp;元。你同时&nbsp;<strong>最多</strong>&nbsp;只能接一个订单。</p>

<p>给你 <code>n</code>&nbsp;和 <code>rides</code>&nbsp;，请你返回在最优接单方案下，你能盈利&nbsp;<strong>最多</strong>&nbsp;多少元。</p>

<p><strong>注意：</strong>你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 5, rides = [<em><strong>[2,5,4]</strong></em>,[1,5,1]]
<b>输出：</b>7
<b>解释：</b>我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 20, rides = [[1,6,1],<strong><em>[3,10,2]</em></strong>,<em><strong>[10,12,3]</strong></em>,[11,12,2],[12,15,2],<strong><em>[13,18,1]</em></strong>]
<b>输出：</b>20
<b>解释：</b>我们可以接以下乘客的订单：
- 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
- 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
- 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
我们总共获得 9 + 5 + 6 = 20 元。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= rides.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>rides[i].length == 3</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= tip<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二分查找

我们先将 $rides$ 按照$start$ 从小到大排序，然后设计一个函数 $dfs(i)$，表示从第 $i$ 个乘客开始接单，最多能获得的小费。答案即为 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

对于第 $i$ 个乘客，我们可以选择接单，也可以选择不接单。如果不接单，那么最多能获得的小费为 $dfs(i + 1)$；如果接单，那么我们可以通过二分查找，找到在第 $i$ 个乘客下车地点之后遇到的第一个乘客，记为 $j$，那么最多能获得的小费为 $dfs(j) + end_i - start_i + tip_i$。取两者的较大值即可。即：

$$
dfs(i) = \max(dfs(i + 1), dfs(j) + end_i - start_i + tip_i)
$$

其中 $j$ 是满足 $start_j \ge end_i$ 的最小的下标，可以通过二分查找得到。

此过程中，我们可以使用记忆化搜索，将每个状态的答案保存下来，避免重复计算。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 为$rides$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(rides):
                return 0
            st, ed, tip = rides[i]
            j = bisect_left(rides, ed, lo=i + 1, key=lambda x: x[0])
            return max(dfs(i + 1), dfs(j) + ed - st + tip)

        rides.sort()
        return dfs(0)
```

#### Java

```java
class Solution {
    private int m;
    private int[][] rides;
    private Long[] f;

    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[0] - b[0]);
        m = rides.length;
        f = new Long[m];
        this.rides = rides;
        return dfs(0);
    }

    private long dfs(int i) {
        if (i >= m) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int[] r = rides[i];
        int st = r[0], ed = r[1], tip = r[2];
        int j = search(ed, i + 1);
        return f[i] = Math.max(dfs(i + 1), dfs(j) + ed - st + tip);
    }

    private int search(int x, int l) {
        int r = m;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (rides[mid][0] >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int m = rides.size();
        long long f[m];
        memset(f, -1, sizeof(f));
        function<long long(int)> dfs = [&](int i) -> long long {
            if (i >= m) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            auto& r = rides[i];
            int st = r[0], ed = r[1], tip = r[2];
            int j = lower_bound(rides.begin() + i + 1, rides.end(), ed, [](auto& a, int val) { return a[0] < val; }) - rides.begin();
            return f[i] = max(dfs(i + 1), dfs(j) + ed - st + tip);
        };
        return dfs(0);
    }
};
```

#### Go

```go
func maxTaxiEarnings(n int, rides [][]int) int64 {
	sort.Slice(rides, func(i, j int) bool { return rides[i][0] < rides[j][0] })
	m := len(rides)
	f := make([]int64, m)
	var dfs func(int) int64
	dfs = func(i int) int64 {
		if i >= m {
			return 0
		}
		if f[i] == 0 {
			st, ed, tip := rides[i][0], rides[i][1], rides[i][2]
			j := sort.Search(m, func(j int) bool { return rides[j][0] >= ed })
			f[i] = max(dfs(i+1), int64(ed-st+tip)+dfs(j))
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function maxTaxiEarnings(n: number, rides: number[][]): number {
    rides.sort((a, b) => a[0] - b[0]);
    const m = rides.length;
    const f: number[] = Array(m).fill(-1);
    const search = (x: number, l: number): number => {
        let r = m;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (rides[mid][0] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const dfs = (i: number): number => {
        if (i >= m) {
            return 0;
        }
        if (f[i] === -1) {
            const [st, ed, tip] = rides[i];
            const j = search(ed, i + 1);
            f[i] = Math.max(dfs(i + 1), dfs(j) + ed - st + tip);
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 二分查找

我们可以将方法一中的记忆化搜索改为动态规划。

先将 $rides$ 排序，这次我们按照 $end$ 从小到大排序。然后定义 $f[i]$，表示前 $i$ 个乘客中，最多能获得的小费。初始时 $f[0] = 0$，答案为 $f[m]$。

对于第 $i$ 个乘客，我们可以选择接单，也可以选择不接单。如果不接单，那么最多能获得的小费为 $f[i-1]$；如果接单，我们可以通过二分查找，找到在第 $i$ 个乘客上车地点之前，最后一个下车地点不大于 $start_i$ 的乘客，记为 $j$，那么最多能获得的小费为 $f[j] + end_i - start_i + tip_i$。取两者的较大值即可。即：

$$
f[i] = \max(f[i - 1], f[j] + end_i - start_i + tip_i)
$$

其中 $j$ 是满足 $end_j \le start_i$ 的最大的下标，可以通过二分查找得到。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 为$rides$ 的长度。

相似题目：

-   [1235. 规划兼职工作](https://github.com/doocs/leetcode/blob/main/solution/1200-1299/1235.Maximum%20Profit%20in%20Job%20Scheduling/README.md)
-   [1751. 最多可以参加的会议数目 II](https://github.com/doocs/leetcode/blob/main/solution/1700-1799/1751.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        rides.sort(key=lambda x: x[1])
        f = [0] * (len(rides) + 1)
        for i, (st, ed, tip) in enumerate(rides, 1):
            j = bisect_left(rides, st + 1, hi=i, key=lambda x: x[1])
            f[i] = max(f[i - 1], f[j] + ed - st + tip)
        return f[-1]
```

#### Java

```java
class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[1] - b[1]);
        int m = rides.length;
        long[] f = new long[m + 1];
        for (int i = 1; i <= m; ++i) {
            int[] r = rides[i - 1];
            int st = r[0], ed = r[1], tip = r[2];
            int j = search(rides, st + 1, i);
            f[i] = Math.max(f[i - 1], f[j] + ed - st + tip);
        }
        return f[m];
    }

    private int search(int[][] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int m = rides.size();
        vector<long long> f(m + 1);
        for (int i = 1; i <= m; ++i) {
            auto& r = rides[i - 1];
            int st = r[0], ed = r[1], tip = r[2];
            auto it = lower_bound(rides.begin(), rides.begin() + i, st + 1, [](auto& a, int val) { return a[1] < val; });
            int j = distance(rides.begin(), it);
            f[i] = max(f[i - 1], f[j] + ed - st + tip);
        }
        return f.back();
    }
};
```

#### Go

```go
func maxTaxiEarnings(n int, rides [][]int) int64 {
	sort.Slice(rides, func(i, j int) bool { return rides[i][1] < rides[j][1] })
	m := len(rides)
	f := make([]int64, m+1)
	for i := 1; i <= m; i++ {
		r := rides[i-1]
		st, ed, tip := r[0], r[1], r[2]
		j := sort.Search(m, func(j int) bool { return rides[j][1] >= st+1 })
		f[i] = max(f[i-1], f[j]+int64(ed-st+tip))
	}
	return f[m]
}
```

#### TypeScript

```ts
function maxTaxiEarnings(n: number, rides: number[][]): number {
    rides.sort((a, b) => a[1] - b[1]);
    const m = rides.length;
    const f: number[] = Array(m + 1).fill(0);
    const search = (x: number, r: number): number => {
        let l = 0;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (rides[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= m; ++i) {
        const [st, ed, tip] = rides[i - 1];
        const j = search(st + 1, i);
        f[i] = Math.max(f[i - 1], f[j] + ed - st + tip);
    }
    return f[m];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2009. 使数组连续的最少操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous){#2009}

{{< tabs "2009" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        ans, j = n, 0
        for i, v in enumerate(nums):
            while j < len(nums) and nums[j] - v <= n - 1:
                j += 1
            ans = min(ans, n - (j - i))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int m = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[m++] = nums[i];
            }
        }
        int ans = n;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < m && nums[j] - nums[i] <= n - 1) {
                ++j;
            }
            ans = Math.min(ans, n - (j - i));
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
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int ans = n;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < m && nums[j] - nums[i] <= n - 1) {
                ++j;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	m := 1
	for i := 1; i < n; i++ {
		if nums[i] != nums[i-1] {
			nums[m] = nums[i]
			m++
		}
	}
	ans := n
	for i, j := 0, 0; i < m; i++ {
		for j < m && nums[j]-nums[i] <= n-1 {
			j++
		}
		ans = min(ans, n-(j-i))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let m = 1;
    for (let i = 1; i < n; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[m] = nums[i];
            m++;
        }
    }
    let ans = n;
    for (let i = 0, j = 0; i < m; i++) {
        while (j < m && nums[j] - nums[i] <= n - 1) {
            j++;
        }
        ans = Math.min(ans, n - (j - i));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        if n == 0 {
            return 0;
        }
        let mut m = 1usize;
        for i in 1..n {
            if nums[i] != nums[i - 1] {
                nums[m] = nums[i];
                m += 1;
            }
        }
        let mut ans = n as i32;
        let mut j = 0usize;
        for i in 0..m {
            while j < m && nums[j] - nums[i] <= n as i32 - 1 {
                j += 1;
            }
            ans = ans.min(n as i32 - (j as i32 - i as i32));
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。每一次操作中，你可以将&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>任意</strong>&nbsp;一个元素替换成 <strong>任意&nbsp;</strong>整数。</p>

<p>如果&nbsp;<code>nums</code>&nbsp;满足以下条件，那么它是 <strong>连续的</strong>&nbsp;：</p>

<ul>
	<li><code>nums</code>&nbsp;中所有元素都是 <b>互不相同</b>&nbsp;的。</li>
	<li><code>nums</code>&nbsp;中 <strong>最大</strong>&nbsp;元素与&nbsp;<strong>最小</strong>&nbsp;元素的差等于&nbsp;<code>nums.length - 1</code>&nbsp;。</li>
</ul>

<p>比方说，<code>nums = [4, 2, 5, 3]</code>&nbsp;是 <strong>连续的</strong>&nbsp;，但是&nbsp;<code>nums = [1, 2, 3, 5, 6]</code> <strong>不是连续的</strong>&nbsp;。</p>

<p>请你返回使 <code>nums</code>&nbsp;<strong>连续</strong>&nbsp;的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,2,5,3]
<b>输出：</b>0
<b>解释：</b>nums 已经是连续的了。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,5,6]
<b>输出：</b>1
<b>解释：</b>一个可能的解是将最后一个元素变为 4 。
结果数组为 [1,2,3,5,4] ，是连续数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,10,100,1000]
<b>输出：</b>3
<b>解释：</b>一个可能的解是：
- 将第二个元素变为 2 。
- 将第三个元素变为 3 。
- 将第四个元素变为 4 。
结果数组为 [1,2,3,4] ，是连续数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 去重 + 二分查找

我们先将数组排序，去重。

然后遍历数组，枚举以当前元素 $nums[i]$ 作为连续数组的最小值，通过二分查找找到第一个大于 $nums[i] + n - 1$ 的位置 $j$，那么 $j-i$ 就是当前元素作为最小值时，连续数组的长度，更新答案，即 $ans = \min(ans, n - (j - i))$。

最后返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = n = len(nums)
        nums = sorted(set(nums))
        for i, v in enumerate(nums):
            j = bisect_right(nums, v + n - 1)
            ans = min(ans, n - (j - i))
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int m = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[m++] = nums[i];
            }
        }
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int j = search(nums, nums[i] + n - 1, i, m);
            ans = Math.min(ans, n - (j - i));
        }
        return ans;
    }

    private int search(int[] nums, int x, int left, int right) {
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int j = upper_bound(nums.begin() + i, nums.begin() + m, nums[i] + n - 1) - nums.begin();
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	m := 1
	for i := 1; i < n; i++ {
		if nums[i] != nums[i-1] {
			nums[m] = nums[i]
			m++
		}
	}
	ans := n
	for i := 0; i < m; i++ {
		j := sort.Search(m, func(k int) bool { return nums[k] > nums[i]+n-1 })
		ans = min(ans, n-(j-i))
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    let m = 1;
    for (let i = 1; i < n; ++i) {
        if (nums[i] !== nums[i - 1]) {
            nums[m++] = nums[i];
        }
    }
    let ans = n;
    for (let i = 0; i < m; ++i) {
        const j = search(nums, nums[i] + n - 1, i, m);
        ans = Math.min(ans, n - (j - i));
    }
    return ans;
}

function search(nums: number[], x: number, left: number, right: number): number {
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

#### Rust

```rust
use std::collections::BTreeSet;

impl Solution {
    #[allow(dead_code)]
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let nums = nums.into_iter().collect::<BTreeSet<i32>>();

        let m = nums.len();
        let nums = nums.into_iter().collect::<Vec<i32>>();

        let mut ans = n;

        for i in 0..m {
            let j = match nums.binary_search(&(nums[i] + (n as i32))) {
                Ok(idx) => idx,
                Err(idx) => idx,
            };
            ans = std::cmp::min(ans, n - (j - i));
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 去重 + 双指针

与方法一类似，我们先将数组排序，去重。

然后遍历数组，枚举以当前元素 $nums[i]$ 作为连续数组的最小值，通过双指针找到第一个大于 $nums[i] + n - 1$ 的位置 $j$，那么 $j-i$ 就是当前元素作为最小值时，连续数组的长度，更新答案，即 $ans = \min(ans, n - (j - i))$。

最后返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        ans, j = n, 0
        for i, v in enumerate(nums):
            while j < len(nums) and nums[j] - v <= n - 1:
                j += 1
            ans = min(ans, n - (j - i))
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int m = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[m++] = nums[i];
            }
        }
        int ans = n;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < m && nums[j] - nums[i] <= n - 1) {
                ++j;
            }
            ans = Math.min(ans, n - (j - i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int ans = n;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < m && nums[j] - nums[i] <= n - 1) {
                ++j;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	m := 1
	for i := 1; i < n; i++ {
		if nums[i] != nums[i-1] {
			nums[m] = nums[i]
			m++
		}
	}
	ans := n
	for i, j := 0, 0; i < m; i++ {
		for j < m && nums[j]-nums[i] <= n-1 {
			j++
		}
		ans = min(ans, n-(j-i))
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let m = 1;
    for (let i = 1; i < n; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[m] = nums[i];
            m++;
        }
    }
    let ans = n;
    for (let i = 0, j = 0; i < m; i++) {
        while (j < m && nums[j] - nums[i] <= n - 1) {
            j++;
        }
        ans = Math.min(ans, n - (j - i));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        if n == 0 {
            return 0;
        }
        let mut m = 1usize;
        for i in 1..n {
            if nums[i] != nums[i - 1] {
                nums[m] = nums[i];
                m += 1;
            }
        }
        let mut ans = n as i32;
        let mut j = 0usize;
        for i in 0..m {
            while j < m && nums[j] - nums[i] <= n as i32 - 1 {
                j += 1;
            }
            ans = ans.min(n as i32 - (j as i32 - i as i32));
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
