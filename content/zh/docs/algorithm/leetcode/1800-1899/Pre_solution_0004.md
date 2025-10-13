---
title: "1830_使字符串有序的最少操作次数"
date: 2025-10-08T18:38:27+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 滑动窗口, 组合数学, 计数排序, 贪心, 链表]
---

{{< markmap >}}
### [1830_使字符串有序的最少操作次数](#1830)
#### [数学](#1830)
#### [字符串](#1830)
#### [组合数学](#1830)
### [1831_每天的最大交易 🔒](#1831)
#### [数据库](#1831)
### [1832_判断句子是否为全字母句](#1832)
#### [哈希表](#1832)
#### [字符串](#1832)
### [1833_雪糕的最大数量](#1833)
#### [贪心](#1833)
#### [数组](#1833)
#### [计数排序](#1833)
#### [排序](#1833)
### [1834_单线程 CPU](#1834)
#### [数组](#1834)
#### [排序](#1834)
#### [堆（优先队列）](#1834)
### [1835_所有数对按位与结果的异或和](#1835)
#### [位运算](#1835)
#### [数组](#1835)
#### [数学](#1835)
### [1836_从未排序的链表中移除重复元素 🔒](#1836)
#### [哈希表](#1836)
#### [链表](#1836)
### [1837_K 进制表示下的各位数字总和](#1837)
#### [数学](#1837)
### [1838_最高频元素的频数](#1838)
#### [贪心](#1838)
#### [数组](#1838)
#### [二分查找](#1838)
#### [前缀和](#1838)
#### [排序](#1838)
#### [滑动窗口](#1838)
### [1839_所有元音按顺序排布的最长子字符串](#1839)
#### [字符串](#1839)
#### [滑动窗口](#1839)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1830_使字符串有序的最少操作次数
___
#### 数学
___
#### 字符串
___
#### 组合数学
---
### 1831_每天的最大交易 🔒
___
#### 数据库
---
### 1832_判断句子是否为全字母句
___
#### 哈希表
___
#### 字符串
---
### 1833_雪糕的最大数量
___
#### 贪心
___
#### 数组
___
#### 计数排序
___
#### 排序
---
### 1834_单线程 CPU
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1835_所有数对按位与结果的异或和
___
#### 位运算
___
#### 数组
___
#### 数学
---
### 1836_从未排序的链表中移除重复元素 🔒
___
#### 哈希表
___
#### 链表
---
### 1837_K 进制表示下的各位数字总和
___
#### 数学
---
### 1838_最高频元素的频数
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
___
#### 滑动窗口
---
### 1839_所有元音按顺序排布的最长子字符串
___
#### 字符串
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 滑动窗口 | 组合数学 |
| 计数排序 | 贪心 | 链表 |

# [1830. 使字符串有序的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-string-sorted){#1830}

{{< tabs "1830" >}}

{{% tab "python" %}}
```python
n = 3010
mod = 10**9 + 7
f = [1] + [0] * n
g = [1] + [0] * n

for i in range(1, n):
    f[i] = f[i - 1] * i % mod
    g[i] = pow(f[i], mod - 2, mod)


class Solution:
    def makeStringSorted(self, s: str) -> int:
        cnt = Counter(s)
        ans, n = 0, len(s)
        for i, c in enumerate(s):
            m = sum(v for a, v in cnt.items() if a < c)
            t = f[n - i - 1] * m
            for v in cnt.values():
                t = t * g[v] % mod
            ans = (ans + t) % mod
            cnt[c] -= 1
            if cnt[c] == 0:
                cnt.pop(c)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int N = 3010;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] f = new long[N];
    private static final long[] g = new long[N];

    static {
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < N; ++i) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = qmi(f[i], MOD - 2);
        }
    }

    public static long qmi(long a, int k) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % MOD;
            }
            k >>= 1;
            a = a * a % MOD;
        }
        return res;
    }

    public int makeStringSorted(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = s.charAt(i) - 'a' - 1; j >= 0; --j) {
                m += cnt[j];
            }
            long t = m * f[n - i - 1] % MOD;
            for (int v : cnt) {
                t = t * g[v] % MOD;
            }
            --cnt[s.charAt(i) - 'a'];
            ans = (ans + t + MOD) % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int N = 3010;
const int MOD = 1e9 + 7;
long f[N];
long g[N];

long qmi(long a, int k) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % MOD;
        }
        k >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int init = []() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2);
    }
    return 0;
}();

class Solution {
public:
    int makeStringSorted(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = s[i] - 'a' - 1; ~j; --j) {
                m += cnt[j];
            }
            long t = m * f[n - i - 1] % MOD;
            for (int& v : cnt) {
                t = t * g[v] % MOD;
            }
            ans = (ans + t + MOD) % MOD;
            --cnt[s[i] - 'a'];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const n = 3010
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)

func qmi(a, k int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % mod
		}
		k >>= 1
		a = a * a % mod
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2)
	}
}

func makeStringSorted(s string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for i, c := range s {
		m := 0
		for j := int(c-'a') - 1; j >= 0; j-- {
			m += cnt[j]
		}
		t := m * f[len(s)-i-1] % mod
		for _, v := range cnt {
			t = t * g[v] % mod
		}
		ans = (ans + t + mod) % mod
		cnt[c-'a']--
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

<p>给你一个字符串 <code>s</code> （<strong>下标从 0 开始</strong>）。你需要对 <code>s</code> 执行以下操作直到它变为一个有序字符串：</p>

<ol>
	<li>找到 <strong>最大下标</strong> <code>i</code> ，使得 <code>1 &lt;= i &lt; s.length</code> 且 <code>s[i] &lt; s[i - 1]</code> 。</li>
	<li>找到 <strong>最大下标</strong> <code>j</code> ，使得 <code>i &lt;= j &lt; s.length</code> 且对于所有在闭区间 <code>[i, j]</code> 之间的 <code>k</code> 都有 <code>s[k] &lt; s[i - 1]</code> 。</li>
	<li>交换下标为 <code>i - 1</code>​​​​ 和 <code>j</code>​​​​ 处的两个字符。</li>
	<li>将下标 <code>i</code> 开始的字符串后缀反转。</li>
</ol>

<p>请你返回将字符串变成有序的最少操作次数。由于答案可能会很大，请返回它对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "cba"
<b>输出：</b>5
<b>解释：</b>模拟过程如下所示：
操作 1：i=2，j=2。交换 s[1] 和 s[2] 得到 s="cab" ，然后反转下标从 2 开始的后缀字符串，得到 s="cab" 。
操作 2：i=1，j=2。交换 s[0] 和 s[2] 得到 s="bac" ，然后反转下标从 1 开始的后缀字符串，得到 s="bca" 。
操作 3：i=2，j=2。交换 s[1] 和 s[2] 得到 s="bac" ，然后反转下标从 2 开始的后缀字符串，得到 s="bac" 。
操作 4：i=1，j=1。交换 s[0] 和 s[1] 得到 s="abc" ，然后反转下标从 1 开始的后缀字符串，得到 s="acb" 。
操作 5：i=2，j=2。交换 s[1] 和 s[2] 得到 s="abc" ，然后反转下标从 2 开始的后缀字符串，得到 s="abc" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabaa"
<b>输出：</b>2
<b>解释：</b>模拟过程如下所示：
操作 1：i=3，j=4。交换 s[2] 和 s[4] 得到 s="aaaab" ，然后反转下标从 3 开始的后缀字符串，得到 s="aaaba" 。
操作 2：i=4，j=4。交换 s[3] 和 s[4] 得到 s="aaaab" ，然后反转下标从 4 开始的后缀字符串，得到 s="aaaab" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "cdbea"
<b>输出：</b>63</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>s = "leetcodeleetcodeleetcode"
<b>输出：</b>982157772
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>​ 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 排列组合 + 预处理

题目中的操作实际上是求当前排列的上一个字典序排列，因此，我们只需要求出比当前排列小的排列的数量，就是答案。

这里我们需要考虑一个问题，给定每一种字母的频率，我们可以构造出多少种不同的排列？

假设总共有 $n$ 个字母，其中字母 $a$ 有 $n_1$ 个，字母 $b$ 有 $n_2$ 个，字母 $c$ 有 $n_3$ 个，那么我们可以构造出 $\frac{n!}{n_1! \times n_2! \times n_3!}$ 种不同的排列。其中 $n=n_1+n_2+n_3$。

我们可以通过预处理的方式，预先计算出所有的阶乘 $f$ 和阶乘的逆元 $g$。其中阶乘的逆元可以通过费马小定理求得。

接下来，我们从左到右遍历字符串 $s$，对于每一个位置 $i$，我们需要求出当前总共有多少个比 $s[i]$ 小的字母，记为 $m$。那么，我们可以构造出 $m \times \frac{(n - i - 1)!}{n_1! \times n_2! \cdots \times n_k!}$ 种不同的排列，其中 $k$ 为字母的种类数，累加到答案中。接下来，我们将 $s[i]$ 的频率减一，继续遍历下一个位置。

遍历完整个字符串后，即可得到答案。注意答案的取模操作。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n)$。其中 $n$ 和 $k$ 分别为字符串的长度和字母的种类数。

<!-- tabs:start -->

#### Python3

```python
n = 3010
mod = 10**9 + 7
f = [1] + [0] * n
g = [1] + [0] * n

for i in range(1, n):
    f[i] = f[i - 1] * i % mod
    g[i] = pow(f[i], mod - 2, mod)


class Solution:
    def makeStringSorted(self, s: str) -> int:
        cnt = Counter(s)
        ans, n = 0, len(s)
        for i, c in enumerate(s):
            m = sum(v for a, v in cnt.items() if a < c)
            t = f[n - i - 1] * m
            for v in cnt.values():
                t = t * g[v] % mod
            ans = (ans + t) % mod
            cnt[c] -= 1
            if cnt[c] == 0:
                cnt.pop(c)
        return ans
```

#### Java

```java
class Solution {
    private static final int N = 3010;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] f = new long[N];
    private static final long[] g = new long[N];

    static {
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < N; ++i) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = qmi(f[i], MOD - 2);
        }
    }

    public static long qmi(long a, int k) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % MOD;
            }
            k >>= 1;
            a = a * a % MOD;
        }
        return res;
    }

    public int makeStringSorted(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = s.charAt(i) - 'a' - 1; j >= 0; --j) {
                m += cnt[j];
            }
            long t = m * f[n - i - 1] % MOD;
            for (int v : cnt) {
                t = t * g[v] % MOD;
            }
            --cnt[s.charAt(i) - 'a'];
            ans = (ans + t + MOD) % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
const int N = 3010;
const int MOD = 1e9 + 7;
long f[N];
long g[N];

long qmi(long a, int k) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % MOD;
        }
        k >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int init = []() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2);
    }
    return 0;
}();

class Solution {
public:
    int makeStringSorted(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = s[i] - 'a' - 1; ~j; --j) {
                m += cnt[j];
            }
            long t = m * f[n - i - 1] % MOD;
            for (int& v : cnt) {
                t = t * g[v] % MOD;
            }
            ans = (ans + t + MOD) % MOD;
            --cnt[s[i] - 'a'];
        }
        return ans;
    }
};
```

#### Go

```go
const n = 3010
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)

func qmi(a, k int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % mod
		}
		k >>= 1
		a = a * a % mod
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2)
	}
}

func makeStringSorted(s string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for i, c := range s {
		m := 0
		for j := int(c-'a') - 1; j >= 0; j-- {
			m += cnt[j]
		}
		t := m * f[len(s)-i-1] % mod
		for _, v := range cnt {
			t = t * g[v] % mod
		}
		ans = (ans + t + mod) % mod
		cnt[c-'a']--
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1831. 每天的最大交易 🔒](https://leetcode.cn/problems/maximum-transaction-each-day){#1831}

{{< tabs "1831" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            transaction_id,
            RANK() OVER (
                PARTITION BY DAY(day)
                ORDER BY amount DESC
            ) AS rk
        FROM Transactions
    )
SELECT transaction_id
FROM T
WHERE rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Transactions</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| transaction_id | int      |
| day            | datetime |
| amount         | int      |
+----------------+----------+
transaction_id 是该表具有唯一值的列。
每行包括了该次交易的信息。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，报告每天交易金额 <code>amount</code> <strong>最大</strong> 的交易 ID 。如果一天中有多个这样的交易，返回这些交易的 ID 。</p>

<p><span style="">返回结果根据 </span><code>transaction_id</code>&nbsp;<strong>升序排列</strong>。</p>

<p>返回格式如下示例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Transactions table:
+----------------+--------------------+--------+
| transaction_id | day                | amount |
+----------------+--------------------+--------+
| 8              | 2021-4-3 15:57:28  | 57     |
| 9              | 2021-4-28 08:47:25 | 21     |
| 1              | 2021-4-29 13:28:30 | 58     |
| 5              | 2021-4-28 16:39:59 | 40     |
| 6              | 2021-4-29 23:39:28 | 58     |
+----------------+--------------------+--------+
<strong>输出：</strong>
+----------------+
| transaction_id |
+----------------+
| 1              |
| 5              |
| 6              |
| 8              |
+----------------+
<strong>解释：</strong>
"2021-4-3"  --&gt; 有一个 id 是 8 的交易，因此，把它加入结果表。 
"2021-4-28" --&gt; 有两个交易，id 是 5 和 9 ，交易 5 的金额是 40 ，而交易 9 的数量是 21 。只需要将交易 5 加入结果表，因为它是当天金额最大的交易。
"2021-4-29" --&gt; 有两个交易，id 是 1 和 6 ，这两个交易的金额都是 58 ，因此需要把它们都写入结果表。
最后，把交易 id 按照升序排列。</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以不使用&nbsp;<code>MAX()</code>&nbsp;函数解决这道题目吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

我们可以使用窗口函数 `RANK`，按照每天的交易金额 `amount` 降序排列，然后选择排名为 $1$ 的交易。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            transaction_id,
            RANK() OVER (
                PARTITION BY DAY(day)
                ORDER BY amount DESC
            ) AS rk
        FROM Transactions
    )
SELECT transaction_id
FROM T
WHERE rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1832. 判断句子是否为全字母句](https://leetcode.cn/problems/check-if-the-sentence-is-pangram){#1832}

{{< tabs "1832" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        mask = 0
        for c in sentence:
            mask |= 1 << (ord(c) - ord('a'))
        return mask == (1 << 26) - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        int mask = 0;
        for (int i = 0; i < sentence.length(); ++i) {
            mask |= 1 << (sentence.charAt(i) - 'a');
        }
        return mask == (1 << 26) - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0;
        for (char& c : sentence) mask |= 1 << (c - 'a');
        return mask == (1 << 26) - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkIfPangram(sentence string) bool {
	mask := 0
	for _, c := range sentence {
		mask |= 1 << int(c-'a')
	}
	return mask == 1<<26-1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkIfPangram(sentence: string): boolean {
    let mark = 0;
    for (const c of sentence) {
        mark |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
    }
    return mark === (1 << 26) - 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut mark = 0;
        for c in sentence.as_bytes() {
            mark |= 1 << (*c - b'a');
        }
        mark == (1 << 26) - 1
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool checkIfPangram(char* sentence) {
    int mark = 0;
    for (int i = 0; sentence[i]; i++) {
        mark |= 1 << (sentence[i] - 'a');
    }
    return mark == (1 << 26) - 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>全字母句</strong> 指包含英语字母表中每个字母至少一次的句子。</p>

<p>给你一个仅由小写英文字母组成的字符串 <code>sentence</code> ，请你判断 <code>sentence</code> 是否为 <strong>全字母句</strong> 。</p>

<p>如果是，返回<em> </em><code>true</code> ；否则，返回<em> </em><code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "thequickbrownfoxjumpsoverthelazydog"
<strong>输出：</strong>true
<strong>解释：</strong><code>sentence</code> 包含英语字母表中每个字母至少一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "leetcode"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= sentence.length <= 1000</code></li>
	<li><code>sentence</code> 由小写英语字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

遍历字符串 `sentence`，用数组或哈希表记录出现过的字母，最后判断数组或哈希表中是否有 $26$ 个字母即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 `sentence` 的长度，而 $C$ 为字符集大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(set(sentence)) == 26
```

#### Java

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        boolean[] vis = new boolean[26];
        for (int i = 0; i < sentence.length(); ++i) {
            vis[sentence.charAt(i) - 'a'] = true;
        }
        for (boolean v : vis) {
            if (!v) {
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
    bool checkIfPangram(string sentence) {
        int vis[26] = {0};
        for (char& c : sentence) vis[c - 'a'] = 1;
        for (int& v : vis)
            if (!v) return false;
        return true;
    }
};
```

#### Go

```go
func checkIfPangram(sentence string) bool {
	vis := [26]bool{}
	for _, c := range sentence {
		vis[c-'a'] = true
	}
	for _, v := range vis {
		if !v {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkIfPangram(sentence: string): boolean {
    const vis = new Array(26).fill(false);
    for (const c of sentence) {
        vis[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }
    return vis.every(v => v);
}
```

#### Rust

```rust
impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut vis = [false; 26];
        for c in sentence.as_bytes() {
            vis[(*c - b'a') as usize] = true;
        }
        vis.iter().all(|v| *v)
    }
}
```

#### C

```c
bool checkIfPangram(char* sentence) {
    int vis[26] = {0};
    for (int i = 0; sentence[i]; i++) {
        vis[sentence[i] - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            return 0;
        }
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

我们也可以用一个整数 $mask$ 记录出现过的字母，其中 $mask$ 的第 $i$ 位表示第 $i$ 个字母是否出现过。

最后判断 $mask$ 的二进制表示中是否有 $26$ 个 $1$，也即判断 $mask$ 是否等于 $2^{26} - 1$。若是，返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 为字符串 `sentence` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        mask = 0
        for c in sentence:
            mask |= 1 << (ord(c) - ord('a'))
        return mask == (1 << 26) - 1
```

#### Java

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        int mask = 0;
        for (int i = 0; i < sentence.length(); ++i) {
            mask |= 1 << (sentence.charAt(i) - 'a');
        }
        return mask == (1 << 26) - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0;
        for (char& c : sentence) mask |= 1 << (c - 'a');
        return mask == (1 << 26) - 1;
    }
};
```

#### Go

```go
func checkIfPangram(sentence string) bool {
	mask := 0
	for _, c := range sentence {
		mask |= 1 << int(c-'a')
	}
	return mask == 1<<26-1
}
```

#### TypeScript

```ts
function checkIfPangram(sentence: string): boolean {
    let mark = 0;
    for (const c of sentence) {
        mark |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
    }
    return mark === (1 << 26) - 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut mark = 0;
        for c in sentence.as_bytes() {
            mark |= 1 << (*c - b'a');
        }
        mark == (1 << 26) - 1
    }
}
```

#### C

```c
bool checkIfPangram(char* sentence) {
    int mark = 0;
    for (int i = 0; sentence[i]; i++) {
        mark |= 1 << (sentence[i] - 'a');
    }
    return mark == (1 << 26) - 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1833. 雪糕的最大数量](https://leetcode.cn/problems/maximum-ice-cream-bars){#1833}

{{< tabs "1833" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        for i, c in enumerate(costs):
            if coins < c:
                return i
            coins -= c
        return len(costs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int n = costs.length;
        for (int i = 0; i < n; ++i) {
            if (coins < costs[i]) {
                return i;
            }
            coins -= costs[i];
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        for (int i = 0; i < n; ++i) {
            if (coins < costs[i]) return i;
            coins -= costs[i];
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxIceCream(costs []int, coins int) int {
	sort.Ints(costs)
	for i, c := range costs {
		if coins < c {
			return i
		}
		coins -= c
	}
	return len(costs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxIceCream(costs: number[], coins: number): number {
    costs.sort((a, b) => a - b);
    const n = costs.length;
    for (let i = 0; i < n; ++i) {
        if (coins < costs[i]) {
            return i;
        }
        coins -= costs[i];
    }
    return n;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {
    costs.sort((a, b) => a - b);
    const n = costs.length;
    for (let i = 0; i < n; ++i) {
        if (coins < costs[i]) {
            return i;
        }
        coins -= costs[i];
    }
    return n;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。</p>

<p>商店中新到 <code>n</code> 支雪糕，用长度为 <code>n</code> 的数组 <code>costs</code> 表示雪糕的定价，其中 <code>costs[i]</code> 表示第 <code>i</code> 支雪糕的现金价格。Tony 一共有 <code>coins</code> 现金可以用于消费，他想要买尽可能多的雪糕。</p>

<p><strong>注意：</strong>Tony 可以按任意顺序购买雪糕。</p>

<p>给你价格数组 <code>costs</code> 和现金量 <code>coins</code> ，请你计算并返回 Tony 用 <code>coins</code> 现金能够买到的雪糕的 <strong>最大数量</strong> 。</p>

<p>你必须使用计数排序解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>costs = [1,3,2,4,1], coins = 7
<strong>输出：</strong>4
<strong>解释：</strong>Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>costs = [10,6,8,7,7,8], coins = 5
<strong>输出：</strong>0
<strong>解释：</strong>Tony 没有足够的钱买任何一支雪糕。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>costs = [1,6,3,1,2,5], coins = 20
<strong>输出：</strong>6
<strong>解释：</strong>Tony 可以买下所有的雪糕，总价为 1 + 6 + 3 + 1 + 2 + 5 = 18 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

要买尽可能多的雪糕，且可以按任意顺序购买，因此，我们应该优先选择定价小的雪糕。

对数组 `costs` 进行排序，然后从定价最小的雪糕开始，依次购买，直到不能购买为止，返回能购买的雪糕数量。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `costs` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        for i, c in enumerate(costs):
            if coins < c:
                return i
            coins -= c
        return len(costs)
```

#### Java

```java
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int n = costs.length;
        for (int i = 0; i < n; ++i) {
            if (coins < costs[i]) {
                return i;
            }
            coins -= costs[i];
        }
        return n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        for (int i = 0; i < n; ++i) {
            if (coins < costs[i]) return i;
            coins -= costs[i];
        }
        return n;
    }
};
```

#### Go

```go
func maxIceCream(costs []int, coins int) int {
	sort.Ints(costs)
	for i, c := range costs {
		if coins < c {
			return i
		}
		coins -= c
	}
	return len(costs)
}
```

#### TypeScript

```ts
function maxIceCream(costs: number[], coins: number): number {
    costs.sort((a, b) => a - b);
    const n = costs.length;
    for (let i = 0; i < n; ++i) {
        if (coins < costs[i]) {
            return i;
        }
        coins -= costs[i];
    }
    return n;
}
```

#### JavaScript

```js
/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {
    costs.sort((a, b) => a - b);
    const n = costs.length;
    for (let i = 0; i < n; ++i) {
        if (coins < costs[i]) {
            return i;
        }
        coins -= costs[i];
    }
    return n;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1834. 单线程 CPU](https://leetcode.cn/problems/single-threaded-cpu){#1834}

{{< tabs "1834" >}}

{{% tab "python" %}}
```python
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i, task in enumerate(tasks):
            task.append(i)
        tasks.sort()
        ans = []
        q = []
        n = len(tasks)
        i = t = 0
        while q or i < n:
            if not q:
                t = max(t, tasks[i][0])
            while i < n and tasks[i][0] <= t:
                heappush(q, (tasks[i][1], tasks[i][2]))
                i += 1
            pt, j = heappop(q)
            ans.append(j)
            t += pt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        int[][] ts = new int[n][3];
        for (int i = 0; i < n; ++i) {
            ts[i] = new int[] {tasks[i][0], tasks[i][1], i};
        }
        Arrays.sort(ts, (a, b) -> a[0] - b[0]);
        int[] ans = new int[n];
        PriorityQueue<int[]> q
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int i = 0, t = 0, k = 0;
        while (!q.isEmpty() || i < n) {
            if (q.isEmpty()) {
                t = Math.max(t, ts[i][0]);
            }
            while (i < n && ts[i][0] <= t) {
                q.offer(new int[] {ts[i][1], ts[i][2]});
                ++i;
            }
            var p = q.poll();
            ans[k++] = p[1];
            t += p[0];
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
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = 0;
        for (auto& task : tasks) task.push_back(n++);
        sort(tasks.begin(), tasks.end());
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int i = 0;
        long long t = 0;
        vector<int> ans;
        while (!q.empty() || i < n) {
            if (q.empty()) t = max(t, (long long) tasks[i][0]);
            while (i < n && tasks[i][0] <= t) {
                q.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto [pt, j] = q.top();
            q.pop();
            ans.push_back(j);
            t += pt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getOrder(tasks [][]int) (ans []int) {
	for i := range tasks {
		tasks[i] = append(tasks[i], i)
	}
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][0] < tasks[j][0] })
	q := hp{}
	i, t, n := 0, 0, len(tasks)
	for len(q) > 0 || i < n {
		if len(q) == 0 {
			t = max(t, tasks[i][0])
		}
		for i < n && tasks[i][0] <= t {
			heap.Push(&q, pair{tasks[i][1], tasks[i][2]})
			i++
		}
		p := heap.Pop(&q).(pair)
		ans = append(ans, p.i)
		t += p.t
	}
	return
}

type pair struct{ t, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].t < h[j].t || (h[i].t == h[j].t && h[i].i < h[j].i) }
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

<p>给你一个二维数组 <code>tasks</code> ，用于表示 <code>n</code>​​​​​​ 项从 <code>0</code> 到 <code>n - 1</code> 编号的任务。其中 <code>tasks[i] = [enqueueTime<sub>i</sub>, processingTime<sub>i</sub>]</code> 意味着第 <code>i<sup>​​​​​​</sup></code>​​​​ 项任务将会于 <code>enqueueTime<sub>i</sub></code> 时进入任务队列，需要 <code>processingTime<sub>i</sub></code><sub> </sub>的时长完成执行。</p>

<p>现有一个单线程 CPU ，同一时间只能执行 <strong>最多一项</strong> 任务，该 CPU 将会按照下述方式运行：</p>

<ul>
	<li>如果 CPU 空闲，且任务队列中没有需要执行的任务，则 CPU 保持空闲状态。</li>
	<li>如果 CPU 空闲，但任务队列中有需要执行的任务，则 CPU 将会选择 <strong>执行时间最短</strong> 的任务开始执行。如果多个任务具有同样的最短执行时间，则选择下标最小的任务开始执行。</li>
	<li>一旦某项任务开始执行，CPU 在 <strong>执行完整个任务</strong> 前都不会停止。</li>
	<li>CPU 可以在完成一项任务后，立即开始执行一项新任务。</li>
</ul>

<p>返回<em> </em>CPU<em> </em>处理任务的顺序。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tasks = [[1,2],[2,4],[3,2],[4,1]]
<strong>输出：</strong>[0,2,3,1]
<strong>解释：</strong>事件按下述流程运行： 
- time = 1 ，任务 0 进入任务队列，可执行任务项 = {0}
- 同样在 time = 1 ，空闲状态的 CPU 开始执行任务 0 ，可执行任务项 = {}
- time = 2 ，任务 1 进入任务队列，可执行任务项 = {1}
- time = 3 ，任务 2 进入任务队列，可执行任务项 = {1, 2}
- 同样在 time = 3 ，CPU 完成任务 0 并开始执行队列中用时最短的任务 2 ，可执行任务项 = {1}
- time = 4 ，任务 3 进入任务队列，可执行任务项 = {1, 3}
- time = 5 ，CPU 完成任务 2 并开始执行队列中用时最短的任务 3 ，可执行任务项 = {1}
- time = 6 ，CPU 完成任务 3 并开始执行任务 1 ，可执行任务项 = {}
- time = 10 ，CPU 完成任务 1 并进入空闲状态
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
<strong>输出：</strong>[4,3,2,0,1]
<strong>解释：</strong>事件按下述流程运行： 
- time = 7 ，所有任务同时进入任务队列，可执行任务项  = {0,1,2,3,4}
- 同样在 time = 7 ，空闲状态的 CPU 开始执行任务 4 ，可执行任务项 = {0,1,2,3}
- time = 9 ，CPU 完成任务 4 并开始执行任务 3 ，可执行任务项 = {0,1,2}
- time = 13 ，CPU 完成任务 3 并开始执行任务 2 ，可执行任务项 = {0,1}
- time = 18 ，CPU 完成任务 2 并开始执行任务 0 ，可执行任务项 = {1}
- time = 28 ，CPU 完成任务 0 并开始执行任务 1 ，可执行任务项 = {}
- time = 40 ，CPU 完成任务 1 并进入空闲状态</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>tasks.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= enqueueTime<sub>i</sub>, processingTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 优先队列（小根堆）

我们先将任务按照 `enqueueTime` 从小到大排序，接下来用一个优先队列（小根堆）维护当前可执行的任务，队列中的元素为 `(processingTime, index)`，即任务的执行时间和任务的编号。另外用一个变量 $t$ 表示当前时间，初始值为 $0$。

接下来我们模拟任务的执行过程。

如果当前队列为空，说明当前没有可执行的任务，我们将 $t$ 更新为下一个任务的 `enqueueTime` 与当前时间 $t$ 中的较大值。接下来将所有 `enqueueTime` 小于等于 $t$ 的任务加入队列。

然后从队列中取出一个任务，将其编号加入答案数组，然后将 $t$ 更新为当前时间 $t$ 与当前任务的执行时间之和。

循环上述过程，直到队列为空，且所有任务都已经加入过队列。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为任务的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        for i, task in enumerate(tasks):
            task.append(i)
        tasks.sort()
        ans = []
        q = []
        n = len(tasks)
        i = t = 0
        while q or i < n:
            if not q:
                t = max(t, tasks[i][0])
            while i < n and tasks[i][0] <= t:
                heappush(q, (tasks[i][1], tasks[i][2]))
                i += 1
            pt, j = heappop(q)
            ans.append(j)
            t += pt
        return ans
```

#### Java

```java
class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        int[][] ts = new int[n][3];
        for (int i = 0; i < n; ++i) {
            ts[i] = new int[] {tasks[i][0], tasks[i][1], i};
        }
        Arrays.sort(ts, (a, b) -> a[0] - b[0]);
        int[] ans = new int[n];
        PriorityQueue<int[]> q
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int i = 0, t = 0, k = 0;
        while (!q.isEmpty() || i < n) {
            if (q.isEmpty()) {
                t = Math.max(t, ts[i][0]);
            }
            while (i < n && ts[i][0] <= t) {
                q.offer(new int[] {ts[i][1], ts[i][2]});
                ++i;
            }
            var p = q.poll();
            ans[k++] = p[1];
            t += p[0];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = 0;
        for (auto& task : tasks) task.push_back(n++);
        sort(tasks.begin(), tasks.end());
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int i = 0;
        long long t = 0;
        vector<int> ans;
        while (!q.empty() || i < n) {
            if (q.empty()) t = max(t, (long long) tasks[i][0]);
            while (i < n && tasks[i][0] <= t) {
                q.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto [pt, j] = q.top();
            q.pop();
            ans.push_back(j);
            t += pt;
        }
        return ans;
    }
};
```

#### Go

```go
func getOrder(tasks [][]int) (ans []int) {
	for i := range tasks {
		tasks[i] = append(tasks[i], i)
	}
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][0] < tasks[j][0] })
	q := hp{}
	i, t, n := 0, 0, len(tasks)
	for len(q) > 0 || i < n {
		if len(q) == 0 {
			t = max(t, tasks[i][0])
		}
		for i < n && tasks[i][0] <= t {
			heap.Push(&q, pair{tasks[i][1], tasks[i][2]})
			i++
		}
		p := heap.Pop(&q).(pair)
		ans = append(ans, p.i)
		t += p.t
	}
	return
}

type pair struct{ t, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].t < h[j].t || (h[i].t == h[j].t && h[i].i < h[j].i) }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1835. 所有数对按位与结果的异或和](https://leetcode.cn/problems/find-xor-sum-of-all-pairs-bitwise-and){#1835}

{{< tabs "1835" >}}

{{% tab "python" %}}
```python
class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        a = reduce(xor, arr1)
        b = reduce(xor, arr2)
        return a & b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getXORSum(int[] arr1, int[] arr2) {
        int a = 0, b = 0;
        for (int v : arr1) {
            a ^= v;
        }
        for (int v : arr2) {
            b ^= v;
        }
        return a & b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>());
        int b = accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
        return a & b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getXORSum(arr1 []int, arr2 []int) int {
	var a, b int
	for _, v := range arr1 {
		a ^= v
	}
	for _, v := range arr2 {
		b ^= v
	}
	return a & b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getXORSum(arr1: number[], arr2: number[]): number {
    const a = arr1.reduce((acc, x) => acc ^ x);
    const b = arr2.reduce((acc, x) => acc ^ x);
    return a & b;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>列表的 <strong>异或和</strong>（<strong>XOR sum</strong>）指对所有元素进行按位 <code>XOR</code> 运算的结果。如果列表中仅有一个元素，那么其 <strong>异或和</strong> 就等于该元素。</p>

<ul>
	<li>例如，<code>[1,2,3,4]</code> 的 <strong>异或和</strong> 等于 <code>1 XOR 2 XOR 3 XOR 4 = 4</code> ，而 <code>[3]</code> 的 <strong>异或和</strong> 等于 <code>3</code> 。</li>
</ul>

<p>给你两个下标 <strong>从 0 开始</strong> 计数的数组 <code>arr1</code> 和 <code>arr2</code> ，两数组均由非负整数组成。</p>

<p>根据每个 <code>(i, j)</code> 数对，构造一个由 <code>arr1[i] AND arr2[j]</code>（按位 <code>AND</code> 运算）结果组成的列表。其中 <code>0 &lt;= i &lt; arr1.length</code> 且 <code>0 &lt;= j &lt; arr2.length</code> 。</p>

<p>返回上述列表的 <strong>异或和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr1 = [1,2,3], arr2 = [6,5]
<strong>输出：</strong>0
<strong>解释：</strong>列表 = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1] ，
异或和 = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr1 = [12], arr2 = [4]
<strong>输出：</strong>4
<strong>解释：</strong>列表 = [12 AND 4] = [4] ，异或和 = 4 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr1[i], arr2[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

假设数组 $arr1$ 的元素分别为 $a_1, a_2, \cdots, a_n$，数组 $arr2$ 的元素分别为 $b_1, b_2, \cdots, b_m$，那么题目答案为：

$$
\begin{aligned}
\textit{ans} &= (a_1 \wedge b_1) \oplus (a_1 \wedge b_2) ... (a_1 \wedge b_m) \\
&\quad \oplus (a_2 \wedge b_1) \oplus (a_2 \wedge b_2) ... (a_2 \wedge b_m) \\
&\quad \oplus \cdots \\
&\quad \oplus (a_n \wedge b_1) \oplus (a_n \wedge b_2) ... (a_n \wedge b_m) \\
\end{aligned}
$$

由于布尔代数中，异或运算就是不进位的加法，与运算就是乘法，所以上式可以简化为：

$$
\textit{ans} = (a_1 \oplus a_2 \oplus \cdots \oplus a_n) \wedge (b_1 \oplus b_2 \oplus \cdots \oplus b_m)
$$

即，数组 $arr1$ 的异或和与数组 $arr2$ 的异或和的与运算结果。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别为数组 $arr1$ 和 $arr2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        a = reduce(xor, arr1)
        b = reduce(xor, arr2)
        return a & b
```

#### Java

```java
class Solution {
    public int getXORSum(int[] arr1, int[] arr2) {
        int a = 0, b = 0;
        for (int v : arr1) {
            a ^= v;
        }
        for (int v : arr2) {
            b ^= v;
        }
        return a & b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = accumulate(arr1.begin(), arr1.end(), 0, bit_xor<int>());
        int b = accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>());
        return a & b;
    }
};
```

#### Go

```go
func getXORSum(arr1 []int, arr2 []int) int {
	var a, b int
	for _, v := range arr1 {
		a ^= v
	}
	for _, v := range arr2 {
		b ^= v
	}
	return a & b
}
```

#### TypeScript

```ts
function getXORSum(arr1: number[], arr2: number[]): number {
    const a = arr1.reduce((acc, x) => acc ^ x);
    const b = arr2.reduce((acc, x) => acc ^ x);
    return a & b;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1836. 从未排序的链表中移除重复元素 🔒](https://leetcode.cn/problems/remove-duplicates-from-an-unsorted-linked-list){#1836}

{{< tabs "1836" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        cnt = Counter()
        cur = head
        while cur:
            cnt[cur.val] += 1
            cur = cur.next
        dummy = ListNode(0, head)
        pre, cur = dummy, head
        while cur:
            if cnt[cur.val] > 1:
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            cnt.put(cur.val, cnt.getOrDefault(cur.val, 0) + 1);
        }
        ListNode dummy = new ListNode(0, head);
        for (ListNode pre = dummy, cur = head; cur != null; cur = cur.next) {
            if (cnt.get(cur.val) > 1) {
                pre.next = cur.next;
            } else {
                pre = cur;
            }
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> cnt;
        for (ListNode* cur = head; cur; cur = cur->next) {
            cnt[cur->val]++;
        }
        ListNode* dummy = new ListNode(0, head);
        for (ListNode *pre = dummy, *cur = head; cur; cur = cur->next) {
            if (cnt[cur->val] > 1) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicatesUnsorted(head *ListNode) *ListNode {
	cnt := map[int]int{}
	for cur := head; cur != nil; cur = cur.Next {
		cnt[cur.Val]++
	}
	dummy := &ListNode{0, head}
	for pre, cur := dummy, head; cur != nil; cur = cur.Next {
		if cnt[cur.Val] > 1 {
			pre.Next = cur.Next
		} else {
			pre = cur
		}
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteDuplicatesUnsorted(head: ListNode | null): ListNode | null {
    const cnt: Map<number, number> = new Map();
    for (let cur = head; cur; cur = cur.next) {
        const x = cur.val;
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const dummy = new ListNode(0, head);
    for (let pre = dummy, cur = head; cur; cur = cur.next) {
        if (cnt.get(cur.val)! > 1) {
            pre.next = cur.next;
        } else {
            pre = cur;
        }
    }
    return dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个链表的第一个节点 <code>head</code> ，找到链表中所有出现<strong>多于一次</strong>的元素，并删除这些元素所在的节点。</p>

<p>返回删除后的链表。</p>

<p> </p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1836.Remove%20Duplicates%20From%20an%20Unsorted%20Linked%20List/images/tmp-linked-list.jpg" style="width: 422px; height: 222px;">
<pre><strong>输入:</strong> head = [1,2,3,2]
<strong>输出:</strong> [1,3]
<strong>解释:</strong> 2 在链表中出现了两次，所以所有的 2 都需要被删除。删除了所有的 2 之后，我们还剩下 [1,3] 。
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1836.Remove%20Duplicates%20From%20an%20Unsorted%20Linked%20List/images/tmp-linked-list-1.jpg" style="width: 422px; height: 151px;">
<pre><strong>输入:</strong> head = [2,1,1,2]
<strong>输出:</strong> []
<strong>解释:</strong> 2 和 1 都出现了两次。所有元素都需要被删除。
</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1836.Remove%20Duplicates%20From%20an%20Unsorted%20Linked%20List/images/tmp-linked-list-2.jpg" style="width: 500px; height: 142px;">
<pre><strong>输入:</strong> head = [3,2,2,1,3,2,4]
<strong>输出:</strong> [1,4]
<strong>解释: </strong>3 出现了两次，且 2 出现了三次。移除了所有的 3 和 2 后，我们还剩下 [1,4] 。
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li>链表中节点个数的范围是 <code>[1, 10<sup>5</sup>]</code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用哈希表 $cnt$ 统计链表中每个元素出现的次数，然后遍历链表，删除出现次数大于 1 的元素。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        cnt = Counter()
        cur = head
        while cur:
            cnt[cur.val] += 1
            cur = cur.next
        dummy = ListNode(0, head)
        pre, cur = dummy, head
        while cur:
            if cnt[cur.val] > 1:
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            cnt.put(cur.val, cnt.getOrDefault(cur.val, 0) + 1);
        }
        ListNode dummy = new ListNode(0, head);
        for (ListNode pre = dummy, cur = head; cur != null; cur = cur.next) {
            if (cnt.get(cur.val) > 1) {
                pre.next = cur.next;
            } else {
                pre = cur;
            }
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> cnt;
        for (ListNode* cur = head; cur; cur = cur->next) {
            cnt[cur->val]++;
        }
        ListNode* dummy = new ListNode(0, head);
        for (ListNode *pre = dummy, *cur = head; cur; cur = cur->next) {
            if (cnt[cur->val] > 1) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicatesUnsorted(head *ListNode) *ListNode {
	cnt := map[int]int{}
	for cur := head; cur != nil; cur = cur.Next {
		cnt[cur.Val]++
	}
	dummy := &ListNode{0, head}
	for pre, cur := dummy, head; cur != nil; cur = cur.Next {
		if cnt[cur.Val] > 1 {
			pre.Next = cur.Next
		} else {
			pre = cur
		}
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteDuplicatesUnsorted(head: ListNode | null): ListNode | null {
    const cnt: Map<number, number> = new Map();
    for (let cur = head; cur; cur = cur.next) {
        const x = cur.val;
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const dummy = new ListNode(0, head);
    for (let pre = dummy, cur = head; cur; cur = cur.next) {
        if (cnt.get(cur.val)! > 1) {
            pre.next = cur.next;
        } else {
            pre = cur;
        }
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1837. K 进制表示下的各位数字总和](https://leetcode.cn/problems/sum-of-digits-in-base-k){#1837}

{{< tabs "1837" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        while n:
            ans += n % k
            n //= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0) {
            ans += n % k;
            n /= k;
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
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumBase(n int, k int) (ans int) {
	for n > 0 {
		ans += n % k
		n /= k
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumBase(n: number, k: number): number {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_base(mut n: i32, k: i32) -> i32 {
        let mut ans = 0;
        while n != 0 {
            ans += n % k;
            n /= k;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var sumBase = function (n, k) {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int sumBase(int n, int k) {
    int ans = 0;
    while (n) {
        ans += n % k;
        n /= k;
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

<p>给你一个整数 <code>n</code>（<code>10</code> 进制）和一个基数 <code>k</code> ，请你将 <code>n</code> 从 <code>10</code> 进制表示转换为 <code>k</code> 进制表示，计算并返回转换后各位数字的 <strong>总和</strong> 。</p>

<p>转换后，各位数字应当视作是 <code>10</code> 进制数字，且它们的总和也应当按 <code>10</code> 进制表示返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 34, k = 6
<strong>输出：</strong>9
<strong>解释：</strong>34 (10 进制) 在 6 进制下表示为 54 。5 + 4 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10, k = 10
<strong>输出：</strong>1
<strong>解释：</strong>n 本身就是 10 进制。 1 + 0 = 1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 100</code></li>
	<li><code>2 <= k <= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们将 $n$ 除 $k$ 取余，直至为 $0$，余数相加即可得到结果。

时间复杂度 $O(\log_{k}n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        while n:
            ans += n % k
            n //= k
        return ans
```

#### Java

```java
class Solution {
    public int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};
```

#### Go

```go
func sumBase(n int, k int) (ans int) {
	for n > 0 {
		ans += n % k
		n /= k
	}
	return
}
```

#### TypeScript

```ts
function sumBase(n: number, k: number): number {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_base(mut n: i32, k: i32) -> i32 {
        let mut ans = 0;
        while n != 0 {
            ans += n % k;
            n /= k;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var sumBase = function (n, k) {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
};
```

#### C

```c
int sumBase(int n, int k) {
    int ans = 0;
    while (n) {
        ans += n % k;
        n /= k;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1838. 最高频元素的频数](https://leetcode.cn/problems/frequency-of-the-most-frequent-element){#1838}

{{< tabs "1838" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 1
        s = j = 0
        for i in range(1, len(nums)):
            s += (nums[i] - nums[i - 1]) * (i - j)
            while s > k:
                s -= nums[i] - nums[j]
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        long s = 0;
        for (int i = 1, j = 0; i < nums.length; ++i) {
            s += 1L * (nums[i] - nums[i - 1]) * (i - j);
            while (s > k) {
                s -= nums[i] - nums[j++];
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
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        long long s = 0;
        for (int i = 1, j = 0; i < nums.size(); ++i) {
            s += 1LL * (nums[i] - nums[i - 1]) * (i - j);
            while (s > k) {
                s -= nums[i] - nums[j++];
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
func maxFrequency(nums []int, k int) int {
	sort.Ints(nums)
	ans := 1
	s := 0
	for i, j := 1, 0; i < len(nums); i++ {
		s += (nums[i] - nums[i-1]) * (i - j)
		for ; s > k; j++ {
			s -= nums[i] - nums[j]
		}
		ans = max(ans, i-j+1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxFrequency(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let [s, j] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        s += (nums[i] - nums[i - 1]) * (i - j);
        while (s > k) {
            s -= nums[i] - nums[j++];
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

<p>元素的 <strong>频数</strong> 是该元素在一个数组中出现的次数。</p>

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。在一步操作中，你可以选择 <code>nums</code> 的一个下标，并将该下标对应元素的值增加 <code>1</code> 。</p>

<p>执行最多 <code>k</code> 次操作后，返回数组中最高频元素的 <strong>最大可能频数</strong> <em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4], k = 5
<strong>输出：</strong>3<strong>
解释：</strong>对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
4 是数组中最高频元素，频数是 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,8,13], k = 5
<strong>输出：</strong>2
<strong>解释：</strong>存在多种最优解决方案：
- 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
- 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
- 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,9,6], k = 2
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>5</sup></code></li>
	<li><code>1 <= k <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找

根据题目描述，我们可以得出三个结论：

1. 经过若干次操作后，数组中最高频元素一定是原数组中的某个元素。为什么呢？我们不妨假设操作的若干个元素分别为 $a_1, a_2, \cdots, a_m$，其中最大值为 $a_m$，这几个元素都变成了同一个值 $x$，其中 $x \geq a_m$，那么也一定可以将这些元素全部变成 $a_m$，这样操作次数不会增加。
1. 操作的若干个元素一定是排序后的数组的一段连续子数组。
1. 如果一个频数 $m$ 满足条件，那么所有 $m' \lt m$ 也满足条件。这启发我们可以考虑使用二分查找，找到最大的满足条件的频数。

因此，我们可以对数组 $nums$ 进行排序，然后计算排序后的数组的前缀和数组 $s$，其中 $s[i]$ 表示前 $i$ 个元素的和。

接下来，我们定义二分查找的左边界 $l=1$，右边界 $r=n$。每一次二分查找，我们取中间值 $m=(l+r+1)/2$，然后检查是否存在一个长度为 $m$ 的连续子数组，使得这个子数组中的元素都可以变成数组中的某个元素，且操作次数不超过 $k$。如果存在这样的子数组，那么我们就可以将左边界 $l$ 更新为 $m$，否则将右边界 $r$ 更新为 $m-1$。

最后返回左边界 $l$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        def check(m: int) -> bool:
            for i in range(m, n + 1):
                if nums[i - 1] * m - (s[i] - s[i - m]) <= k:
                    return True
            return False

        n = len(nums)
        nums.sort()
        s = list(accumulate(nums, initial=0))
        l, r = 1, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int[] nums;
    private long[] s;
    private int k;

    public int maxFrequency(int[] nums, int k) {
        this.k = k;
        this.nums = nums;
        Arrays.sort(nums);
        int n = nums.length;
        s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int m) {
        for (int i = m; i <= nums.length; ++i) {
            if (1L * nums[i - 1] * m - (s[i] - s[i - m]) <= k) {
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
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int l = 1, r = n;
        auto check = [&](int m) {
            for (int i = m; i <= n; ++i) {
                if (1LL * nums[i - 1] * m - (s[i] - s[i - m]) <= k) {
                    return true;
                }
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maxFrequency(nums []int, k int) int {
	n := len(nums)
	sort.Ints(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	check := func(m int) bool {
		for i := m; i <= n; i++ {
			if nums[i-1]*m-(s[i]-s[i-m]) <= k {
				return true
			}
		}
		return false
	}
	l, r := 1, n
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maxFrequency(nums: number[], k: number): number {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + nums[i - 1];
    }
    let [l, r] = [1, n];
    const check = (m: number): boolean => {
        for (let i = m; i <= n; ++i) {
            if (nums[i - 1] * m - (s[i] - s[i - m]) <= k) {
                return true;
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 双指针

我们也可以使用双指针来维护一个滑动窗口，窗口内中的元素都可以变成窗口中的最大值，窗口内元素的操作次数为 $s$，且 $s \leq k$。

初始时，我们将左指针 $j$ 指向数组的第一个元素，右指针 $i$ 也指向数组的第一个元素。接下来，我们每一次移动右指针 $i$，将窗口中的元素都变成 $nums[i]$，此时需要增加的操作次数为 $(nums[i] - nums[i - 1]) \times (i - j)$。如果这个操作次数超过了 $k$，那么我们就需要移动左指针 $j$，直到窗口内元素的操作次数不超过 $k$。然后，我们更新答案为窗口的长度的最大值。

时间复杂度 $O(n \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 1
        s = j = 0
        for i in range(1, len(nums)):
            s += (nums[i] - nums[i - 1]) * (i - j)
            while s > k:
                s -= nums[i] - nums[j]
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        long s = 0;
        for (int i = 1, j = 0; i < nums.length; ++i) {
            s += 1L * (nums[i] - nums[i - 1]) * (i - j);
            while (s > k) {
                s -= nums[i] - nums[j++];
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
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        long long s = 0;
        for (int i = 1, j = 0; i < nums.size(); ++i) {
            s += 1LL * (nums[i] - nums[i - 1]) * (i - j);
            while (s > k) {
                s -= nums[i] - nums[j++];
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maxFrequency(nums []int, k int) int {
	sort.Ints(nums)
	ans := 1
	s := 0
	for i, j := 1, 0; i < len(nums); i++ {
		s += (nums[i] - nums[i-1]) * (i - j)
		for ; s > k; j++ {
			s -= nums[i] - nums[j]
		}
		ans = max(ans, i-j+1)
	}
	return ans
}
```

#### TypeScript

```ts
function maxFrequency(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let [s, j] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        s += (nums[i] - nums[i - 1]) * (i - j);
        while (s > k) {
            s -= nums[i] - nums[j++];
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

# [1839. 所有元音按顺序排布的最长子字符串](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order){#1839}

{{< tabs "1839" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        arr = []
        n = len(word)
        i = 0
        while i < n:
            j = i
            while j < n and word[j] == word[i]:
                j += 1
            arr.append((word[i], j - i))
            i = j
        ans = 0
        for i in range(len(arr) - 4):
            a, b, c, d, e = arr[i : i + 5]
            if a[0] + b[0] + c[0] + d[0] + e[0] == "aeiou":
                ans = max(ans, a[1] + b[1] + c[1] + d[1] + e[1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestBeautifulSubstring(String word) {
        int n = word.length();
        List<Node> arr = new ArrayList<>();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            arr.add(new Node(word.charAt(i), j - i));
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < arr.size() - 4; ++i) {
            Node a = arr.get(i), b = arr.get(i + 1), c = arr.get(i + 2), d = arr.get(i + 3),
                 e = arr.get(i + 4);
            if (a.c == 'a' && b.c == 'e' && c.c == 'i' && d.c == 'o' && e.c == 'u') {
                ans = Math.max(ans, a.v + b.v + c.v + d.v + e.v);
            }
        }
        return ans;
    }
}

class Node {
    char c;
    int v;

    Node(char c, int v) {
        this.c = c;
        this.v = v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<pair<char, int>> arr;
        int n = word.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) ++j;
            arr.push_back({word[i], j - i});
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < (int) arr.size() - 4; ++i) {
            auto& [a, v1] = arr[i];
            auto& [b, v2] = arr[i + 1];
            auto& [c, v3] = arr[i + 2];
            auto& [d, v4] = arr[i + 3];
            auto& [e, v5] = arr[i + 4];
            if (a == 'a' && b == 'e' && c == 'i' && d == 'o' && e == 'u') {
                ans = max(ans, v1 + v2 + v3 + v4 + v5);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestBeautifulSubstring(word string) (ans int) {
	arr := []pair{}
	n := len(word)
	for i := 0; i < n; {
		j := i
		for j < n && word[j] == word[i] {
			j++
		}
		arr = append(arr, pair{word[i], j - i})
		i = j
	}
	for i := 0; i < len(arr)-4; i++ {
		a, b, c, d, e := arr[i], arr[i+1], arr[i+2], arr[i+3], arr[i+4]
		if a.c == 'a' && b.c == 'e' && c.c == 'i' && d.c == 'o' && e.c == 'u' {
			ans = max(ans, a.v+b.v+c.v+d.v+e.v)
		}
	}
	return
}

type pair struct {
	c byte
	v int
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>当一个字符串满足如下条件时，我们称它是 <b>美丽的</b> ：</p>

<ul>
	<li>所有 5 个英文元音字母（<code>'a'</code> ，<code>'e'</code> ，<code>'i'</code> ，<code>'o'</code> ，<code>'u'</code>）都必须 <strong>至少</strong> 出现一次。</li>
	<li>这些元音字母的顺序都必须按照 <strong>字典序</strong> 升序排布（也就是说所有的 <code>'a'</code> 都在 <code>'e'</code> 前面，所有的 <code>'e'</code> 都在 <code>'i'</code> 前面，以此类推）</li>
</ul>

<p>比方说，字符串 <code>"aeiou"</code> 和 <code>"aaaaaaeiiiioou"</code> 都是 <strong>美丽的</strong> ，但是 <code>"uaeio"</code> ，<code>"aeoiu"</code> 和 <code>"aaaeeeooo"</code> <strong>不是美丽的</strong> 。</p>

<p>给你一个只包含英文元音字母的字符串 <code>word</code> ，请你返回 <code>word</code> 中 <strong>最长美丽子字符串的长度</strong> 。如果不存在这样的子字符串，请返回 <code>0</code> 。</p>

<p><strong>子字符串</strong> 是字符串中一个连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>word = "aeiaaio<strong>aaaaeiiiiouuu</strong>ooaauuaeiu"
<b>输出：</b>13
<b>解释：</b>最长子字符串是 "aaaaeiiiiouuu" ，长度为 13 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>word = "aeeeiiiioooauuu<strong>aeiou</strong>"
<b>输出：</b>5
<b>解释：</b>最长子字符串是 "aeiou" ，长度为 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>word = "a"
<b>输出：</b>0
<b>解释：</b>没有美丽子字符串，所以返回 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word.length <= 5 * 10<sup>5</sup></code></li>
	<li><code>word</code> 只包含字符 <code>'a'</code>，<code>'e'</code>，<code>'i'</code>，<code>'o'</code> 和 <code>'u'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 模拟

我们可以先将字符串 `word` 做个转化，比如对于 `word="aaaeiouu"`，我们可以将其转化为数据项 `('a', 3)`, `('e', 1)`, `('i', 1)`, `('o', 1)`, `('u', 2)`，存放在数组 `arr` 中。其中每个数据项的第一个元素表示元音字母，第二个元素表示该元音字母连续出现的次数。这部分转化可以通过双指针来实现。

接下来，我们遍历数组 `arr`，每次取相邻的 $5$ 个数据项，判断这些数据项中的元音字母是否分别为 `'a'`, `'e'`, `'i'`, `'o'`, `'u'`，如果是，则计算这 $5$ 个数据项中元音字母的总次数，即为当前的美丽子字符串的长度，更新答案的最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        arr = []
        n = len(word)
        i = 0
        while i < n:
            j = i
            while j < n and word[j] == word[i]:
                j += 1
            arr.append((word[i], j - i))
            i = j
        ans = 0
        for i in range(len(arr) - 4):
            a, b, c, d, e = arr[i : i + 5]
            if a[0] + b[0] + c[0] + d[0] + e[0] == "aeiou":
                ans = max(ans, a[1] + b[1] + c[1] + d[1] + e[1])
        return ans
```

#### Java

```java
class Solution {
    public int longestBeautifulSubstring(String word) {
        int n = word.length();
        List<Node> arr = new ArrayList<>();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            arr.add(new Node(word.charAt(i), j - i));
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < arr.size() - 4; ++i) {
            Node a = arr.get(i), b = arr.get(i + 1), c = arr.get(i + 2), d = arr.get(i + 3),
                 e = arr.get(i + 4);
            if (a.c == 'a' && b.c == 'e' && c.c == 'i' && d.c == 'o' && e.c == 'u') {
                ans = Math.max(ans, a.v + b.v + c.v + d.v + e.v);
            }
        }
        return ans;
    }
}

class Node {
    char c;
    int v;

    Node(char c, int v) {
        this.c = c;
        this.v = v;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<pair<char, int>> arr;
        int n = word.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) ++j;
            arr.push_back({word[i], j - i});
            i = j;
        }
        int ans = 0;
        for (int i = 0; i < (int) arr.size() - 4; ++i) {
            auto& [a, v1] = arr[i];
            auto& [b, v2] = arr[i + 1];
            auto& [c, v3] = arr[i + 2];
            auto& [d, v4] = arr[i + 3];
            auto& [e, v5] = arr[i + 4];
            if (a == 'a' && b == 'e' && c == 'i' && d == 'o' && e == 'u') {
                ans = max(ans, v1 + v2 + v3 + v4 + v5);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestBeautifulSubstring(word string) (ans int) {
	arr := []pair{}
	n := len(word)
	for i := 0; i < n; {
		j := i
		for j < n && word[j] == word[i] {
			j++
		}
		arr = append(arr, pair{word[i], j - i})
		i = j
	}
	for i := 0; i < len(arr)-4; i++ {
		a, b, c, d, e := arr[i], arr[i+1], arr[i+2], arr[i+3], arr[i+4]
		if a.c == 'a' && b.c == 'e' && c.c == 'i' && d.c == 'o' && e.c == 'u' {
			ans = max(ans, a.v+b.v+c.v+d.v+e.v)
		}
	}
	return
}

type pair struct {
	c byte
	v int
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
