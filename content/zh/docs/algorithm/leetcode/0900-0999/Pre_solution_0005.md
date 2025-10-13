---
title: "0940_不同的子序列 II"
date: 2025-10-08T18:36:43+08:00
weight: 5
tags: [位运算, 动态规划, 双指针, 哈希表, 回溯, 图, 字符串, 并查集, 排序, 数组, 枚举, 栈, 模拟, 深度优先搜索, 状态压缩, 计数, 贪心]
---

{{< markmap >}}
### [0940_不同的子序列 II](#940)
#### [字符串](#940)
#### [动态规划](#940)
### [0941_有效的山脉数组](#941)
#### [数组](#941)
### [0942_增减字符串匹配](#942)
#### [贪心](#942)
#### [数组](#942)
#### [双指针](#942)
#### [字符串](#942)
### [0943_最短超级串](#943)
#### [位运算](#943)
#### [数组](#943)
#### [字符串](#943)
#### [动态规划](#943)
#### [状态压缩](#943)
### [0944_删列造序](#944)
#### [数组](#944)
#### [字符串](#944)
### [0945_使数组唯一的最小增量](#945)
#### [贪心](#945)
#### [数组](#945)
#### [计数](#945)
#### [排序](#945)
### [0946_验证栈序列](#946)
#### [栈](#946)
#### [数组](#946)
#### [模拟](#946)
### [0947_移除最多的同行或同列石头](#947)
#### [深度优先搜索](#947)
#### [并查集](#947)
#### [图](#947)
#### [哈希表](#947)
### [0948_令牌放置](#948)
#### [贪心](#948)
#### [数组](#948)
#### [双指针](#948)
#### [排序](#948)
### [0949_给定数字能组成的最大时间](#949)
#### [数组](#949)
#### [字符串](#949)
#### [回溯](#949)
#### [枚举](#949)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0940_不同的子序列 II
___
#### 字符串
___
#### 动态规划
---
### 0941_有效的山脉数组
___
#### 数组
---
### 0942_增减字符串匹配
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 字符串
---
### 0943_最短超级串
___
#### 位运算
___
#### 数组
___
#### 字符串
___
#### 动态规划
___
#### 状态压缩
---
### 0944_删列造序
___
#### 数组
___
#### 字符串
---
### 0945_使数组唯一的最小增量
___
#### 贪心
___
#### 数组
___
#### 计数
___
#### 排序
---
### 0946_验证栈序列
___
#### 栈
___
#### 数组
___
#### 模拟
---
### 0947_移除最多的同行或同列石头
___
#### 深度优先搜索
___
#### 并查集
___
#### 图
___
#### 哈希表
---
### 0948_令牌放置
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0949_给定数字能组成的最大时间
___
#### 数组
___
#### 字符串
___
#### 回溯
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 图 |
| 字符串 | 并查集 | 排序 |
| 数组 | 枚举 | 栈 |
| 模拟 | 深度优先搜索 | 状态压缩 |
| 计数 | 贪心 |  |

# [940. 不同的子序列 II](https://leetcode.cn/problems/distinct-subsequences-ii){#940}

{{< tabs "940" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        dp = [0] * 26
        ans = 0
        for c in s:
            i = ord(c) - ord('a')
            add = ans - dp[i] + 1
            ans = (ans + add) % mod
            dp[i] += add
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int distinctSubseqII(String s) {
        int[] dp = new int[26];
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            int add = (ans - dp[j] + 1) % MOD;
            ans = (ans + add) % MOD;
            dp[j] = (dp[j] + add) % MOD;
        }
        return (ans + MOD) % MOD;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int distinctSubseqII(string s) {
        vector<long> dp(26);
        long ans = 0;
        for (char& c : s) {
            int i = c - 'a';
            long add = ans - dp[i] + 1;
            ans = (ans + add + mod) % mod;
            dp[i] = (dp[i] + add) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctSubseqII(s string) int {
	const mod int = 1e9 + 7
	dp := make([]int, 26)
	ans := 0
	for _, c := range s {
		c -= 'a'
		add := ans - dp[c] + 1
		ans = (ans + add) % mod
		dp[c] = (dp[c] + add) % mod
	}
	return (ans + mod) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctSubseqII(s: string): number {
    const mod = 1e9 + 7;
    const dp = new Array(26).fill(0);
    for (const c of s) {
        dp[c.charCodeAt(0) - 'a'.charCodeAt(0)] = dp.reduce((r, v) => (r + v) % mod, 0) + 1;
    }
    return dp.reduce((r, v) => (r + v) % mod, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        const MOD: i32 = (1e9 as i32) + 7;
        let mut dp = [0; 26];
        for u in s.as_bytes() {
            let i = (u - &b'a') as usize;
            dp[i] = ({
                let mut sum = 0;
                dp.iter().for_each(|&v| {
                    sum = (sum + v) % MOD;
                });
                sum
            }) + 1;
        }
        let mut res = 0;
        dp.iter().for_each(|&v| {
            res = (res + v) % MOD;
        });
        res
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int distinctSubseqII(char* s) {
    int mod = 1e9 + 7;
    int n = strlen(s);
    int dp[26] = {0};
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 26; j++) {
            sum = (sum + dp[j]) % mod;
        }
        dp[s[i] - 'a'] = sum + 1;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res = (res + dp[i]) % mod;
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code>，计算 <code>s</code> 的 <strong>不同非空子序列</strong> 的个数。因为结果可能很大，所以返回答案需要对<strong> </strong><strong><code>10^9 + 7</code> 取余</strong> 。</p>

<p>字符串的 <strong>子序列</strong> 是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。</p>

<ul>
	<li>例如，<code>"ace"</code> 是 <code>"<em><strong>a</strong></em>b<em><strong>c</strong></em>d<em><strong>e</strong></em>"</code> 的一个子序列，但 <code>"aec"</code> 不是。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc"
<strong>输出：</strong>7
<strong>解释：</strong>7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aba"
<strong>输出：</strong>6
<strong>解释：</strong>6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "aaa"
<strong>输出：</strong>3
<strong>解释：</strong>3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

定义 $dp[i]$ 表示以 $s[i]$ 结尾的不同子序列的个数。由于 $s$ 中只包含小写字母，因此我们可以直接创建一个长度为 $26$ 的数组。初始时 $dp$ 所有元素均为 $0$。答案为 $\sum_{i=0}^{25}dp[i]$。

遍历字符串 $s$，对于每个位置的字符 $s[i]$，我们需要更新以 $s[i]$ 结尾的不同子序列的个数，此时 $dp[i]=\sum_{j=0}^{25}dp[j]+1$。其中 $\sum_{j=0}^{25}dp[j]$ 是此前我们已经计算出所有不同子序列的个数，而 $+1$ 是指 $s[i]$ 本身也可以作为一个子序列。

最后，我们需要对 $dp$ 中的所有元素求和，再对 $10^9+7$ 取余，即为答案。

时间复杂度 $O(n\times C)$，其中 $n$ 是字符串 $s$ 的长度，而 $C$ 是字符集的大小，本题中 $C=26$。空间复杂度 $O(C)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        dp = [[0] * 26 for _ in range(n + 1)]
        for i, c in enumerate(s, 1):
            k = ord(c) - ord('a')
            for j in range(26):
                if j == k:
                    dp[i][j] = sum(dp[i - 1]) % mod + 1
                else:
                    dp[i][j] = dp[i - 1][j]
        return sum(dp[-1]) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int distinctSubseqII(String s) {
        int[] dp = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            dp[j] = sum(dp) + 1;
        }
        return sum(dp);
    }

    private int sum(int[] arr) {
        int x = 0;
        for (int v : arr) {
            x = (x + v) % MOD;
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int distinctSubseqII(string s) {
        vector<long> dp(26);
        for (char& c : s) {
            int i = c - 'a';
            dp[i] = accumulate(dp.begin(), dp.end(), 1l) % mod;
        }
        return accumulate(dp.begin(), dp.end(), 0l) % mod;
    }
};
```

#### Go

```go
func distinctSubseqII(s string) int {
	const mod int = 1e9 + 7
	sum := func(arr []int) int {
		x := 0
		for _, v := range arr {
			x = (x + v) % mod
		}
		return x
	}

	dp := make([]int, 26)
	for _, c := range s {
		c -= 'a'
		dp[c] = sum(dp) + 1
	}
	return sum(dp)
}
```

#### TypeScript

```ts
function distinctSubseqII(s: string): number {
    const mod = 1e9 + 7;
    const dp = new Array(26).fill(0);
    for (const c of s) {
        dp[c.charCodeAt(0) - 'a'.charCodeAt(0)] = dp.reduce((r, v) => (r + v) % mod, 0) + 1;
    }
    return dp.reduce((r, v) => (r + v) % mod, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        const MOD: i32 = (1e9 as i32) + 7;
        let mut dp = [0; 26];
        for u in s.as_bytes() {
            let i = (u - &b'a') as usize;
            dp[i] = ({
                let mut sum = 0;
                dp.iter().for_each(|&v| {
                    sum = (sum + v) % MOD;
                });
                sum
            }) + 1;
        }
        let mut res = 0;
        dp.iter().for_each(|&v| {
            res = (res + v) % MOD;
        });
        res
    }
}
```

#### C

```c
int distinctSubseqII(char* s) {
    int mod = 1e9 + 7;
    int n = strlen(s);
    int dp[26] = {0};
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 26; j++) {
            sum = (sum + dp[j]) % mod;
        }
        dp[s[i] - 'a'] = sum + 1;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res = (res + dp[i]) % mod;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：优化的动态规划

在方法一的基础上，我们还可以维护当前 $dp$ 数组中所有元素的和 $ans$，这样我们每次更新 $dp[i]$ 时，只需要将 $dp[i]$ 加上 $ans-dp[i]+1$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。

相似题目：

-   [1987. 不同的好子序列数目](https://github.com/doocs/leetcode/blob/main/solution/1900-1999/1987.Number%20of%20Unique%20Good%20Subsequences/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        dp = [0] * 26
        for c in s:
            i = ord(c) - ord('a')
            dp[i] = sum(dp) % mod + 1
        return sum(dp) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int distinctSubseqII(String s) {
        int[] dp = new int[26];
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            int add = (ans - dp[j] + 1) % MOD;
            ans = (ans + add) % MOD;
            dp[j] = (dp[j] + add) % MOD;
        }
        return (ans + MOD) % MOD;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int distinctSubseqII(string s) {
        vector<long> dp(26);
        long ans = 0;
        for (char& c : s) {
            int i = c - 'a';
            long add = ans - dp[i] + 1;
            ans = (ans + add + mod) % mod;
            dp[i] = (dp[i] + add) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func distinctSubseqII(s string) int {
	const mod int = 1e9 + 7
	dp := make([]int, 26)
	ans := 0
	for _, c := range s {
		c -= 'a'
		add := ans - dp[c] + 1
		ans = (ans + add) % mod
		dp[c] = (dp[c] + add) % mod
	}
	return (ans + mod) % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        dp = [0] * 26
        ans = 0
        for c in s:
            i = ord(c) - ord('a')
            add = ans - dp[i] + 1
            ans = (ans + add) % mod
            dp[i] += add
        return ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [941. 有效的山脉数组](https://leetcode.cn/problems/valid-mountain-array){#941}

{{< tabs "941" >}}

{{% tab "python" %}}
```python
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3:
            return False
        i, j = 0, n - 1
        while i + 1 < n - 1 and arr[i] < arr[i + 1]:
            i += 1
        while j - 1 > 0 and arr[j - 1] > arr[j]:
            j -= 1
        return i == j
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validMountainArray(int[] arr) {
        int n = arr.length;
        if (n < 3) {
            return false;
        }
        int i = 0, j = n - 1;
        while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 > 0 && arr[j - 1] > arr[j]) {
            --j;
        }
        return i == j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        int i = 0, j = n - 1;
        while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 > 0 && arr[j - 1] > arr[j]) {
            --j;
        }
        return i == j;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validMountainArray(arr []int) bool {
	n := len(arr)
	if n < 3 {
		return false
	}
	i, j := 0, n-1
	for i+1 < n-1 && arr[i] < arr[i+1] {
		i++
	}
	for j-1 > 0 && arr[j-1] > arr[j] {
		j--
	}
	return i == j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validMountainArray(arr: number[]): boolean {
    const n = arr.length;
    if (n < 3) {
        return false;
    }
    let [i, j] = [0, n - 1];
    while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    while (j - 1 > 0 && arr[j] < arr[j - 1]) {
        j--;
    }
    return i === j;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>arr</code>，如果它是有效的山脉数组就返回&nbsp;<code>true</code>，否则返回 <code>false</code>。</p>

<p>让我们回顾一下，如果 <code>arr</code>&nbsp;满足下述条件，那么它是一个山脉数组：</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>在&nbsp;<code>0 &lt; i&nbsp;&lt; arr.length - 1</code>&nbsp;条件下，存在&nbsp;<code>i</code>&nbsp;使得：
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... arr[i-1] &lt; arr[i] </code></li>
		<li><code>arr[i] &gt; arr[i+1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0941.Valid%20Mountain%20Array/images/hint_valid_mountain_array.png" style="height: 316px; width: 500px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,5,5]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,3,2,1]
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们首先判断数组的长度是否小于 $3$，如果小于 $3$，那么一定不是山脉数组，直接返回 `false`。

然后，我们使用指针 $i$ 从数组的左端开始向右移动，直到找到一个位置 $i$，使得 $arr[i] > arr[i + 1]$。然后，我们使用指针 $j$ 从数组的右端开始向左移动，直到找到一个位置 $j$，使得 $arr[j] > arr[j - 1]$。如果满足条件 $i = j$，那么就说明数组 $arr$ 是一个山脉数组。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3:
            return False
        i, j = 0, n - 1
        while i + 1 < n - 1 and arr[i] < arr[i + 1]:
            i += 1
        while j - 1 > 0 and arr[j - 1] > arr[j]:
            j -= 1
        return i == j
```

#### Java

```java
class Solution {
    public boolean validMountainArray(int[] arr) {
        int n = arr.length;
        if (n < 3) {
            return false;
        }
        int i = 0, j = n - 1;
        while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 > 0 && arr[j - 1] > arr[j]) {
            --j;
        }
        return i == j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        int i = 0, j = n - 1;
        while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 > 0 && arr[j - 1] > arr[j]) {
            --j;
        }
        return i == j;
    }
};
```

#### Go

```go
func validMountainArray(arr []int) bool {
	n := len(arr)
	if n < 3 {
		return false
	}
	i, j := 0, n-1
	for i+1 < n-1 && arr[i] < arr[i+1] {
		i++
	}
	for j-1 > 0 && arr[j-1] > arr[j] {
		j--
	}
	return i == j
}
```

#### TypeScript

```ts
function validMountainArray(arr: number[]): boolean {
    const n = arr.length;
    if (n < 3) {
        return false;
    }
    let [i, j] = [0, n - 1];
    while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    while (j - 1 > 0 && arr[j] < arr[j - 1]) {
        j--;
    }
    return i === j;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [942. 增减字符串匹配](https://leetcode.cn/problems/di-string-match){#942}

{{< tabs "942" >}}

{{% tab "python" %}}
```python
class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        low, high = 0, len(s)
        ans = []
        for c in s:
            if c == "I":
                ans.append(low)
                low += 1
            else:
                ans.append(high)
                high -= 1
        ans.append(low)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int low = 0, high = n;
        int[] ans = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'I') {
                ans[i] = low++;
            } else {
                ans[i] = high--;
            }
        }
        ans[n] = low;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0, high = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = low++;
            } else {
                ans[i] = high--;
            }
        }
        ans[n] = low;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func diStringMatch(s string) (ans []int) {
	low, high := 0, len(s)
	for _, c := range s {
		if c == 'I' {
			ans = append(ans, low)
			low++
		} else {
			ans = append(ans, high)
			high--
		}
	}
	ans = append(ans, low)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function diStringMatch(s: string): number[] {
    const ans: number[] = [];
    let [low, high] = [0, s.length];
    for (const c of s) {
        if (c === 'I') {
            ans.push(low++);
        } else {
            ans.push(high--);
        }
    }
    ans.push(low);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut low = 0;
        let mut high = s.len() as i32;
        let mut ans = Vec::with_capacity(s.len() + 1);

        for c in s.chars() {
            if c == 'I' {
                ans.push(low);
                low += 1;
            } else {
                ans.push(high);
                high -= 1;
            }
        }

        ans.push(low);
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

<p>由范围 <code>[0,n]</code> 内所有整数组成的 <code>n + 1</code> 个整数的排列序列可以表示为长度为 <code>n</code> 的字符串 <code>s</code> ，其中:</p>

<ul>
	<li>如果&nbsp;<code>perm[i] &lt; perm[i + 1]</code>&nbsp;，那么&nbsp;<code>s[i] == 'I'</code>&nbsp;</li>
	<li>如果&nbsp;<code>perm[i] &gt; perm[i + 1]</code>&nbsp;，那么 <code>s[i] == 'D'</code>&nbsp;</li>
</ul>

<p>给定一个字符串 <code>s</code> ，重构排列&nbsp;<code>perm</code> 并返回它。如果有多个有效排列perm，则返回其中 <strong>任何一个</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "IDID"
<strong>输出：</strong>[0,4,1,3,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "III"
<strong>输出：</strong>[0,1,2,3]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "DDI"
<strong>输出：</strong>[3,2,0,1]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code><font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">s</span></span></font></font></code> 只包含字符&nbsp;<code>"I"</code>&nbsp;或&nbsp;<code>"D"</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以使用两个指针 `low` 和 `high` 分别表示当前的最小值和最大值，然后遍历字符串 `s`，如果当前字符是 `I`，那么我们就将 `low` 加入到结果数组中，并且 `low` 自增 1；如果当前字符是 `D`，那么我们就将 `high` 加入到结果数组中，并且 `high` 自减 1。

最后，我们将 `low` 加入到结果数组中，返回结果数组即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        low, high = 0, len(s)
        ans = []
        for c in s:
            if c == "I":
                ans.append(low)
                low += 1
            else:
                ans.append(high)
                high -= 1
        ans.append(low)
        return ans
```

#### Java

```java
class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int low = 0, high = n;
        int[] ans = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'I') {
                ans[i] = low++;
            } else {
                ans[i] = high--;
            }
        }
        ans[n] = low;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0, high = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = low++;
            } else {
                ans[i] = high--;
            }
        }
        ans[n] = low;
        return ans;
    }
};
```

#### Go

```go
func diStringMatch(s string) (ans []int) {
	low, high := 0, len(s)
	for _, c := range s {
		if c == 'I' {
			ans = append(ans, low)
			low++
		} else {
			ans = append(ans, high)
			high--
		}
	}
	ans = append(ans, low)
	return
}
```

#### TypeScript

```ts
function diStringMatch(s: string): number[] {
    const ans: number[] = [];
    let [low, high] = [0, s.length];
    for (const c of s) {
        if (c === 'I') {
            ans.push(low++);
        } else {
            ans.push(high--);
        }
    }
    ans.push(low);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut low = 0;
        let mut high = s.len() as i32;
        let mut ans = Vec::with_capacity(s.len() + 1);

        for c in s.chars() {
            if c == 'I' {
                ans.push(low);
                low += 1;
            } else {
                ans.push(high);
                high -= 1;
            }
        }

        ans.push(low);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [943. 最短超级串](https://leetcode.cn/problems/find-the-shortest-superstring){#943}

{{< tabs "943" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        n = len(words)
        g = [[0] * n for _ in range(n)]
        for i, a in enumerate(words):
            for j, b in enumerate(words):
                if i != j:
                    for k in range(min(len(a), len(b)), 0, -1):
                        if a[-k:] == b[:k]:
                            g[i][j] = k
                            break
        dp = [[0] * n for _ in range(1 << n)]
        p = [[-1] * n for _ in range(1 << n)]
        for i in range(1 << n):
            for j in range(n):
                if (i >> j) & 1:
                    pi = i ^ (1 << j)
                    for k in range(n):
                        if (pi >> k) & 1:
                            v = dp[pi][k] + g[k][j]
                            if v > dp[i][j]:
                                dp[i][j] = v
                                p[i][j] = k
        j = 0
        for i in range(n):
            if dp[-1][i] > dp[-1][j]:
                j = i
        arr = [j]
        i = (1 << n) - 1
        while p[i][j] != -1:
            i, j = i ^ (1 << j), p[i][j]
            arr.append(j)
        arr = arr[::-1]
        vis = set(arr)
        arr.extend([j for j in range(n) if j not in vis])
        ans = [words[arr[0]]] + [words[j][g[i][j] :] for i, j in pairwise(arr)]
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestSuperstring(String[] words) {
        int n = words.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            String a = words[i];
            for (int j = 0; j < n; ++j) {
                String b = words[j];
                if (i != j) {
                    for (int k = Math.min(a.length(), b.length()); k > 0; --k) {
                        if (a.substring(a.length() - k).equals(b.substring(0, k))) {
                            g[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] p = new int[1 << n][n];
        for (int i = 0; i < 1 << n; ++i) {
            Arrays.fill(p[i], -1);
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    int pi = i ^ (1 << j);
                    for (int k = 0; k < n; ++k) {
                        if (((pi >> k) & 1) == 1) {
                            int v = dp[pi][k] + g[k][j];
                            if (v > dp[i][j]) {
                                dp[i][j] = v;
                                p[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][j]) {
                j = i;
            }
        }
        List<Integer> arr = new ArrayList<>();
        arr.add(j);
        for (int i = (1 << n) - 1; p[i][j] != -1;) {
            int k = i;
            i ^= (1 << j);
            j = p[k][j];
            arr.add(j);
        }
        Set<Integer> vis = new HashSet<>(arr);
        for (int i = 0; i < n; ++i) {
            if (!vis.contains(i)) {
                arr.add(i);
            }
        }
        Collections.reverse(arr);
        StringBuilder ans = new StringBuilder(words[arr.get(0)]);
        for (int i = 1; i < n; ++i) {
            int k = g[arr.get(i - 1)][arr.get(i)];
            ans.append(words[arr.get(i)].substring(k));
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
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            auto a = words[i];
            for (int j = 0; j < n; ++j) {
                auto b = words[j];
                if (i != j) {
                    for (int k = min(a.size(), b.size()); k > 0; --k) {
                        if (a.substr(a.size() - k) == b.substr(0, k)) {
                            g[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n));
        vector<vector<int>> p(1 << n, vector<int>(n, -1));
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    int pi = i ^ (1 << j);
                    for (int k = 0; k < n; ++k) {
                        if ((pi >> k) & 1) {
                            int v = dp[pi][k] + g[k][j];
                            if (v > dp[i][j]) {
                                dp[i][j] = v;
                                p[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][j]) {
                j = i;
            }
        }
        vector<int> arr = {j};
        for (int i = (1 << n) - 1; p[i][j] != -1;) {
            int k = i;
            i ^= (1 << j);
            j = p[k][j];
            arr.push_back(j);
        }
        unordered_set<int> vis(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (!vis.count(i)) {
                arr.push_back(i);
            }
        }
        reverse(arr.begin(), arr.end());
        string ans = words[arr[0]];
        for (int i = 1; i < n; ++i) {
            int k = g[arr[i - 1]][arr[i]];
            ans += words[arr[i]].substr(k);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestSuperstring(words []string) string {
	n := len(words)
	g := make([][]int, n)
	for i, a := range words {
		g[i] = make([]int, n)
		for j, b := range words {
			if i != j {
				for k := min(len(a), len(b)); k > 0; k-- {
					if a[len(a)-k:] == b[:k] {
						g[i][j] = k
						break
					}
				}
			}
		}
	}
	dp := make([][]int, 1<<n)
	p := make([][]int, 1<<n)
	for i := 0; i < 1<<n; i++ {
		dp[i] = make([]int, n)
		p[i] = make([]int, n)
		for j := 0; j < n; j++ {
			p[i][j] = -1
			if ((i >> j) & 1) == 1 {
				pi := i ^ (1 << j)
				for k := 0; k < n; k++ {
					if ((pi >> k) & 1) == 1 {
						v := dp[pi][k] + g[k][j]
						if v > dp[i][j] {
							dp[i][j] = v
							p[i][j] = k
						}
					}
				}
			}
		}
	}
	j := 0
	for i := 0; i < n; i++ {
		if dp[(1<<n)-1][i] > dp[(1<<n)-1][j] {
			j = i
		}
	}
	arr := []int{j}
	vis := make([]bool, n)
	vis[j] = true
	for i := (1 << n) - 1; p[i][j] != -1; {
		k := i
		i ^= (1 << j)
		j = p[k][j]
		arr = append(arr, j)
		vis[j] = true
	}
	for i := 0; i < n; i++ {
		if !vis[i] {
			arr = append(arr, i)
		}
	}
	ans := &strings.Builder{}
	ans.WriteString(words[arr[n-1]])
	for i := n - 2; i >= 0; i-- {
		k := g[arr[i+1]][arr[i]]
		ans.WriteString(words[arr[i]][k:])
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串数组 <code>words</code>，找到以 <code>words</code> 中每个字符串作为子字符串的最短字符串。如果有多个有效最短字符串满足题目条件，返回其中 <strong>任意一个</strong> 即可。</p>

<p>我们可以假设 <code>words</code> 中没有字符串是 <code>words</code> 中另一个字符串的子字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["alex","loves","leetcode"]
<strong>输出：</strong>"alexlovesleetcode"
<strong>解释：</strong>"alex"，"loves"，"leetcode" 的所有排列都会被接受。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["catg","ctaagt","gcta","ttca","atgcatc"]
<strong>输出：</strong>"gctaagttcatgcatc"</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 12</code></li>
	<li><code>1 <= words[i].length <= 20</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
	<li><code>words</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 动态规划

由于题目中字符串数组 `words` 的长度不超过 12，因此可以使用状态压缩的方法来表示字符串数组中的每个字符串是否被选中。

定义 $dp[i][j]$ 表示字符串当前选中状态为 $i$，且最后一个选中的字符串为 $s[j]$ 时，字符串重叠部分的最大长度。其中 $i$ 的二进制表示中的第 $j$ 位为 $1$ 表示字符串 $s[j]$ 被选中，为 $0$ 表示字符串 $s[j]$ 未被选中。重叠部分达到最大时，最终得到的字符串最短。我们只要求出重叠部分的最大值以及对应的字符串 $s[j]$，记录每一步状态转移，就能够逆推出最终的字符串。

字符串两两之间的重叠部分长度可以预处理出来，存储在二维数组 $g$ 中，其中 $g[i][j]$ 表示字符串 $s[i]$ 和字符串 $s[j]$ 之间的重叠部分长度。

动态规划的状态转移方程如下：

$$
dp[i][j] = \max_{k \in \{0, 1, \cdots, n - 1\}} \{dp[i - 2^j][k] + g[k][j]\}
$$

时间复杂度 $O(2^n \times n^2)$，空间复杂度 $O(2^n \times n)$。其中 $n$ 为字符串数组 `words` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        n = len(words)
        g = [[0] * n for _ in range(n)]
        for i, a in enumerate(words):
            for j, b in enumerate(words):
                if i != j:
                    for k in range(min(len(a), len(b)), 0, -1):
                        if a[-k:] == b[:k]:
                            g[i][j] = k
                            break
        dp = [[0] * n for _ in range(1 << n)]
        p = [[-1] * n for _ in range(1 << n)]
        for i in range(1 << n):
            for j in range(n):
                if (i >> j) & 1:
                    pi = i ^ (1 << j)
                    for k in range(n):
                        if (pi >> k) & 1:
                            v = dp[pi][k] + g[k][j]
                            if v > dp[i][j]:
                                dp[i][j] = v
                                p[i][j] = k
        j = 0
        for i in range(n):
            if dp[-1][i] > dp[-1][j]:
                j = i
        arr = [j]
        i = (1 << n) - 1
        while p[i][j] != -1:
            i, j = i ^ (1 << j), p[i][j]
            arr.append(j)
        arr = arr[::-1]
        vis = set(arr)
        arr.extend([j for j in range(n) if j not in vis])
        ans = [words[arr[0]]] + [words[j][g[i][j] :] for i, j in pairwise(arr)]
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String shortestSuperstring(String[] words) {
        int n = words.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            String a = words[i];
            for (int j = 0; j < n; ++j) {
                String b = words[j];
                if (i != j) {
                    for (int k = Math.min(a.length(), b.length()); k > 0; --k) {
                        if (a.substring(a.length() - k).equals(b.substring(0, k))) {
                            g[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] p = new int[1 << n][n];
        for (int i = 0; i < 1 << n; ++i) {
            Arrays.fill(p[i], -1);
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    int pi = i ^ (1 << j);
                    for (int k = 0; k < n; ++k) {
                        if (((pi >> k) & 1) == 1) {
                            int v = dp[pi][k] + g[k][j];
                            if (v > dp[i][j]) {
                                dp[i][j] = v;
                                p[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][j]) {
                j = i;
            }
        }
        List<Integer> arr = new ArrayList<>();
        arr.add(j);
        for (int i = (1 << n) - 1; p[i][j] != -1;) {
            int k = i;
            i ^= (1 << j);
            j = p[k][j];
            arr.add(j);
        }
        Set<Integer> vis = new HashSet<>(arr);
        for (int i = 0; i < n; ++i) {
            if (!vis.contains(i)) {
                arr.add(i);
            }
        }
        Collections.reverse(arr);
        StringBuilder ans = new StringBuilder(words[arr.get(0)]);
        for (int i = 1; i < n; ++i) {
            int k = g[arr.get(i - 1)][arr.get(i)];
            ans.append(words[arr.get(i)].substring(k));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            auto a = words[i];
            for (int j = 0; j < n; ++j) {
                auto b = words[j];
                if (i != j) {
                    for (int k = min(a.size(), b.size()); k > 0; --k) {
                        if (a.substr(a.size() - k) == b.substr(0, k)) {
                            g[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n));
        vector<vector<int>> p(1 << n, vector<int>(n, -1));
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    int pi = i ^ (1 << j);
                    for (int k = 0; k < n; ++k) {
                        if ((pi >> k) & 1) {
                            int v = dp[pi][k] + g[k][j];
                            if (v > dp[i][j]) {
                                dp[i][j] = v;
                                p[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][j]) {
                j = i;
            }
        }
        vector<int> arr = {j};
        for (int i = (1 << n) - 1; p[i][j] != -1;) {
            int k = i;
            i ^= (1 << j);
            j = p[k][j];
            arr.push_back(j);
        }
        unordered_set<int> vis(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (!vis.count(i)) {
                arr.push_back(i);
            }
        }
        reverse(arr.begin(), arr.end());
        string ans = words[arr[0]];
        for (int i = 1; i < n; ++i) {
            int k = g[arr[i - 1]][arr[i]];
            ans += words[arr[i]].substr(k);
        }
        return ans;
    }
};
```

#### Go

```go
func shortestSuperstring(words []string) string {
	n := len(words)
	g := make([][]int, n)
	for i, a := range words {
		g[i] = make([]int, n)
		for j, b := range words {
			if i != j {
				for k := min(len(a), len(b)); k > 0; k-- {
					if a[len(a)-k:] == b[:k] {
						g[i][j] = k
						break
					}
				}
			}
		}
	}
	dp := make([][]int, 1<<n)
	p := make([][]int, 1<<n)
	for i := 0; i < 1<<n; i++ {
		dp[i] = make([]int, n)
		p[i] = make([]int, n)
		for j := 0; j < n; j++ {
			p[i][j] = -1
			if ((i >> j) & 1) == 1 {
				pi := i ^ (1 << j)
				for k := 0; k < n; k++ {
					if ((pi >> k) & 1) == 1 {
						v := dp[pi][k] + g[k][j]
						if v > dp[i][j] {
							dp[i][j] = v
							p[i][j] = k
						}
					}
				}
			}
		}
	}
	j := 0
	for i := 0; i < n; i++ {
		if dp[(1<<n)-1][i] > dp[(1<<n)-1][j] {
			j = i
		}
	}
	arr := []int{j}
	vis := make([]bool, n)
	vis[j] = true
	for i := (1 << n) - 1; p[i][j] != -1; {
		k := i
		i ^= (1 << j)
		j = p[k][j]
		arr = append(arr, j)
		vis[j] = true
	}
	for i := 0; i < n; i++ {
		if !vis[i] {
			arr = append(arr, i)
		}
	}
	ans := &strings.Builder{}
	ans.WriteString(words[arr[n-1]])
	for i := n - 2; i >= 0; i-- {
		k := g[arr[i+1]][arr[i]]
		ans.WriteString(words[arr[i]][k:])
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [944. 删列造序](https://leetcode.cn/problems/delete-columns-to-make-sorted){#944}

{{< tabs "944" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs[0]), len(strs)
        ans = 0
        for j in range(m):
            for i in range(1, n):
                if strs[i][j] < strs[i - 1][j]:
                    ans += 1
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length(), n = strs.length;
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i].charAt(j) < strs[i - 1].charAt(j)) {
                    ++ans;
                    break;
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
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size(), n = strs.size();
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ++ans;
                    break;
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
func minDeletionSize(strs []string) (ans int) {
	m, n := len(strs[0]), len(strs)
	for j := 0; j < m; j++ {
		for i := 1; i < n; i++ {
			if strs[i][j] < strs[i-1][j] {
				ans++
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDeletionSize(strs: string[]): number {
    const [m, n] = [strs[0].length, strs.length];
    let ans = 0;
    for (let j = 0; j < m; ++j) {
        for (let i = 1; i < n; ++i) {
            if (strs[i][j] < strs[i - 1][j]) {
                ++ans;
                break;
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
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs.len();
        let m = strs[0].len();
        let mut ans = 0;
        for j in 0..m {
            for i in 1..n {
                if strs[i].as_bytes()[j] < strs[i - 1].as_bytes()[j] {
                    ans += 1;
                    break;
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

<p>给你由 <code>n</code> 个小写字母字符串组成的数组 <code>strs</code>，其中每个字符串长度相等。</p>

<p>这些字符串可以每个一行，排成一个网格。例如，<code>strs = ["abc", "bce", "cae"]</code> 可以排列为：</p>

<pre>
abc
bce
cae</pre>

<p>你需要找出并删除 <strong>不是按字典序非严格递增排列的</strong> 列。在上面的例子（下标从 0 开始）中，列 0（<code>'a'</code>, <code>'b'</code>, <code>'c'</code>）和列 2（<code>'c'</code>, <code>'e'</code>, <code>'e'</code>）都是按字典序非严格递增排列的，而列 1（<code>'b'</code>, <code>'c'</code>, <code>'a'</code>）不是，所以要删除列 1 。</p>

<p>返回你需要删除的列数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["cba","daf","ghi"]
<strong>输出：</strong>1
<strong>解释：</strong>网格示意如下：
  cba
  daf
  ghi
列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["a","b"]
<strong>输出：</strong>0
<strong>解释：</strong>网格示意如下：
  a
  b
只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["zyx","wvu","tsr"]
<strong>输出：</strong>3
<strong>解释：</strong>网格示意如下：
  zyx
  wvu
  tsr
所有 3 列都是非升序排列的，所以都要删除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 1000</code></li>
	<li><code>strs[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逐列比较

我们记字符串数组 $\textit{strs}$ 的行数为 $n$，列数为 $m$。

遍历每一列，从第二行开始，逐列比较当前行和上一行的字符，如果当前行的字符小于上一行的字符，说明当前列不是按字典序非严格递增排列的，需要删除，结果加一，然后跳出内层循环。

最后返回结果即可。

时间复杂度 $O(L)$，其中 $L$ 为字符串数组 $\textit{strs}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs[0]), len(strs)
        ans = 0
        for j in range(m):
            for i in range(1, n):
                if strs[i][j] < strs[i - 1][j]:
                    ans += 1
                    break
        return ans
```

#### Java

```java
class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length(), n = strs.length;
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i].charAt(j) < strs[i - 1].charAt(j)) {
                    ++ans;
                    break;
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
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size(), n = strs.size();
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minDeletionSize(strs []string) (ans int) {
	m, n := len(strs[0]), len(strs)
	for j := 0; j < m; j++ {
		for i := 1; i < n; i++ {
			if strs[i][j] < strs[i-1][j] {
				ans++
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function minDeletionSize(strs: string[]): number {
    const [m, n] = [strs[0].length, strs.length];
    let ans = 0;
    for (let j = 0; j < m; ++j) {
        for (let i = 1; i < n; ++i) {
            if (strs[i][j] < strs[i - 1][j]) {
                ++ans;
                break;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs.len();
        let m = strs[0].len();
        let mut ans = 0;
        for j in 0..m {
            for i in 1..n {
                if strs[i].as_bytes()[j] < strs[i - 1].as_bytes()[j] {
                    ans += 1;
                    break;
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

# [945. 使数组唯一的最小增量](https://leetcode.cn/problems/minimum-increment-to-make-array-unique){#945}

{{< tabs "945" >}}

{{% tab "python" %}}
```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        m = max(nums) + len(nums)
        cnt = Counter(nums)
        ans = 0
        for i in range(m - 1):
            if (diff := cnt[i] - 1) > 0:
                cnt[i + 1] += diff
                ans += diff
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minIncrementForUnique(int[] nums) {
        int m = Arrays.stream(nums).max().getAsInt() + nums.length;
        int[] cnt = new int[m];
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int diff = cnt[i] - 1;
            if (diff > 0) {
                cnt[i + 1] += diff;
                ans += diff;
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
    int minIncrementForUnique(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()) + nums.size();
        int cnt[m];
        memset(cnt, 0, sizeof(cnt));
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int diff = cnt[i] - 1;
            if (diff > 0) {
                cnt[i + 1] += diff;
                ans += diff;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minIncrementForUnique(nums []int) (ans int) {
	m := slices.Max(nums) + len(nums)
	cnt := make([]int, m)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 0; i < m-1; i++ {
		if diff := cnt[i] - 1; diff > 0 {
			cnt[i+1] += diff
			ans += diff
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minIncrementForUnique(nums: number[]): number {
    const m = Math.max(...nums) + nums.length;
    const cnt: number[] = Array(m).fill(0);
    for (const x of nums) {
        cnt[x]++;
    }
    let ans = 0;
    for (let i = 0; i < m - 1; ++i) {
        const diff = cnt[i] - 1;
        if (diff > 0) {
            cnt[i + 1] += diff;
            ans += diff;
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

<p>给你一个整数数组 <code>nums</code> 。每次 move 操作将会选择任意一个满足 <code>0 &lt;= i &lt; nums.length</code> 的下标 <code>i</code>，并将&nbsp;<code>nums[i]</code> 递增&nbsp;<code>1</code>。</p>

<p>返回使 <code>nums</code> 中的每个值都变成唯一的所需要的最少操作次数。</p>

<p>生成的测试用例保证答案在 32 位整数范围内。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>经过一次 <em>move</em> 操作，数组将变为 [1, 2, 3]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,2,1,7]
<strong>输出：</strong>6
<strong>解释：</strong>经过 6 次 <em>move</em> 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 <em>move</em> 操作是不能让数组的每个值唯一的。</pre>
</div>
</div>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们首先对数组 $\textit{nums}$ 进行排序，用一个变量 $\textit{y}$ 记录当前的最大值，初始时 $\textit{y} = -1$。

然后遍历数组 $\textit{nums}$，对于每个元素 $x$，我们将 $y$ 更新为 $\max(y + 1, x)$，并将操作次数 $y - x$ 累加到结果中。

遍历完成后，返回结果即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        ans, y = 0, -1
        for x in nums:
            y = max(y + 1, x)
            ans += y - x
        return ans
```

#### Java

```java
class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, y = -1;
        for (int x : nums) {
            y = Math.max(y + 1, x);
            ans += y - x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, y = -1;
        for (int x : nums) {
            y = max(y + 1, x);
            ans += y - x;
        }
        return ans;
    }
};
```

#### Go

```go
func minIncrementForUnique(nums []int) (ans int) {
	sort.Ints(nums)
	y := -1
	for _, x := range nums {
		y = max(y+1, x)
		ans += y - x
	}
	return
}
```

#### TypeScript

```ts
function minIncrementForUnique(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let [ans, y] = [0, -1];
    for (const x of nums) {
        y = Math.max(y + 1, x);
        ans += y - x;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数 + 贪心

根据题目描述，结果数组的最大值 $m = \max(\textit{nums}) + \textit{len}(\textit{nums})$，我们可以使用一个计数数组 $\textit{cnt}$ 来记录每个元素出现的次数。

然后从 $0$ 到 $m - 1$ 遍历，对于每个元素 $i$，如果它出现的次数 $\textit{cnt}[i]$ 大于 $1$，那么我们将 $\textit{cnt}[i] - 1$ 个元素增加到 $i + 1$，并将操作次数累加到结果中。

遍历完成后，返回结果即可。

时间复杂度 $O(m)$，空间复杂度 $O(m)$。其中 $m$ 是数组 $\textit{nums}$ 的长度加上数组的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        m = max(nums) + len(nums)
        cnt = Counter(nums)
        ans = 0
        for i in range(m - 1):
            if (diff := cnt[i] - 1) > 0:
                cnt[i + 1] += diff
                ans += diff
        return ans
```

#### Java

```java
class Solution {
    public int minIncrementForUnique(int[] nums) {
        int m = Arrays.stream(nums).max().getAsInt() + nums.length;
        int[] cnt = new int[m];
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int diff = cnt[i] - 1;
            if (diff > 0) {
                cnt[i + 1] += diff;
                ans += diff;
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
    int minIncrementForUnique(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()) + nums.size();
        int cnt[m];
        memset(cnt, 0, sizeof(cnt));
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int diff = cnt[i] - 1;
            if (diff > 0) {
                cnt[i + 1] += diff;
                ans += diff;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minIncrementForUnique(nums []int) (ans int) {
	m := slices.Max(nums) + len(nums)
	cnt := make([]int, m)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 0; i < m-1; i++ {
		if diff := cnt[i] - 1; diff > 0 {
			cnt[i+1] += diff
			ans += diff
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minIncrementForUnique(nums: number[]): number {
    const m = Math.max(...nums) + nums.length;
    const cnt: number[] = Array(m).fill(0);
    for (const x of nums) {
        cnt[x]++;
    }
    let ans = 0;
    for (let i = 0; i < m - 1; ++i) {
        const diff = cnt[i] - 1;
        if (diff > 0) {
            cnt[i + 1] += diff;
            ans += diff;
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

# [946. 验证栈序列](https://leetcode.cn/problems/validate-stack-sequences){#946}

{{< tabs "946" >}}

{{% tab "python" %}}
```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stk = []
        i = 0
        for x in pushed:
            stk.append(x)
            while stk and stk[-1] == popped[i]:
                stk.pop()
                i += 1
        return i == len(popped)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stk = new ArrayDeque<>();
        int i = 0;
        for (int x : pushed) {
            stk.push(x);
            while (!stk.isEmpty() && stk.peek() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return i == popped.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (int x : pushed) {
            stk.push(x);
            while (stk.size() && stk.top() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return i == popped.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validateStackSequences(pushed []int, popped []int) bool {
	stk := []int{}
	i := 0
	for _, x := range pushed {
		stk = append(stk, x)
		for len(stk) > 0 && stk[len(stk)-1] == popped[i] {
			stk = stk[:len(stk)-1]
			i++
		}
	}
	return i == len(popped)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validateStackSequences(pushed: number[], popped: number[]): boolean {
    const stk: number[] = [];
    let i = 0;
    for (const x of pushed) {
        stk.push(x);
        while (stk.length && stk.at(-1)! === popped[i]) {
            stk.pop();
            i++;
        }
    }
    return i === popped.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
        let mut stk: Vec<i32> = Vec::new();
        let mut i = 0;
        for &x in &pushed {
            stk.push(x);
            while !stk.is_empty() && *stk.last().unwrap() == popped[i] {
                stk.pop();
                i += 1;
            }
        }
        i == popped.len()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function (pushed, popped) {
    const stk = [];
    let i = 0;
    for (const x of pushed) {
        stk.push(x);
        while (stk.length && stk.at(-1) === popped[i]) {
            stk.pop();
            i++;
        }
    }
    return i === popped.length;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        Stack<int> stk = new Stack<int>();
        int i = 0;

        foreach (int x in pushed) {
            stk.Push(x);
            while (stk.Count > 0 && stk.Peek() == popped[i]) {
                stk.Pop();
                i++;
            }
        }

        return i == popped.Length;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定&nbsp;<code>pushed</code>&nbsp;和&nbsp;<code>popped</code>&nbsp;两个序列，每个序列中的 <strong>值都不重复</strong>，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 <code>true</code>；否则，返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -&gt; 4,
push(5), pop() -&gt; 5, pop() -&gt; 3, pop() -&gt; 2, pop() -&gt; 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>1 不能在 2 之前弹出。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pushed.length &lt;= 1000</code></li>
	<li><code>0 &lt;= pushed[i] &lt;= 1000</code></li>
	<li><code>pushed</code> 的所有元素 <strong>互不相同</strong></li>
	<li><code>popped.length == pushed.length</code></li>
	<li><code>popped</code> 是 <code>pushed</code> 的一个排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈模拟

我们遍历 $\textit{pushed}$ 数组，对于当前遍历到的元素 $x$，我们将其压入栈 $\textit{stk}$ 中，然后判断栈顶元素是否和 $\textit{popped}$ 数组中下一个要弹出的元素相等，如果相等，我们就将栈顶元素弹出并将 $\textit{popped}$ 数组中下一个要弹出的元素的索引 $i$ 加一。最后，如果要弹出的元素都能按照 $\textit{popped}$ 数组的顺序弹出，返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 $\textit{pushed}$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stk = []
        i = 0
        for x in pushed:
            stk.append(x)
            while stk and stk[-1] == popped[i]:
                stk.pop()
                i += 1
        return i == len(popped)
```

#### Java

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stk = new ArrayDeque<>();
        int i = 0;
        for (int x : pushed) {
            stk.push(x);
            while (!stk.isEmpty() && stk.peek() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return i == popped.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (int x : pushed) {
            stk.push(x);
            while (stk.size() && stk.top() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return i == popped.size();
    }
};
```

#### Go

```go
func validateStackSequences(pushed []int, popped []int) bool {
	stk := []int{}
	i := 0
	for _, x := range pushed {
		stk = append(stk, x)
		for len(stk) > 0 && stk[len(stk)-1] == popped[i] {
			stk = stk[:len(stk)-1]
			i++
		}
	}
	return i == len(popped)
}
```

#### TypeScript

```ts
function validateStackSequences(pushed: number[], popped: number[]): boolean {
    const stk: number[] = [];
    let i = 0;
    for (const x of pushed) {
        stk.push(x);
        while (stk.length && stk.at(-1)! === popped[i]) {
            stk.pop();
            i++;
        }
    }
    return i === popped.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
        let mut stk: Vec<i32> = Vec::new();
        let mut i = 0;
        for &x in &pushed {
            stk.push(x);
            while !stk.is_empty() && *stk.last().unwrap() == popped[i] {
                stk.pop();
                i += 1;
            }
        }
        i == popped.len()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function (pushed, popped) {
    const stk = [];
    let i = 0;
    for (const x of pushed) {
        stk.push(x);
        while (stk.length && stk.at(-1) === popped[i]) {
            stk.pop();
            i++;
        }
    }
    return i === popped.length;
};
```

#### C#

```cs
public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        Stack<int> stk = new Stack<int>();
        int i = 0;

        foreach (int x in pushed) {
            stk.Push(x);
            while (stk.Count > 0 && stk.Peek() == popped[i]) {
                stk.Pop();
                i++;
            }
        }

        return i == popped.Length;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [947. 移除最多的同行或同列石头](https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column){#947}

{{< tabs "947" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        m = 10001
        uf = UnionFind(m << 1)
        for x, y in stones:
            uf.union(x, y + m)
        return len(stones) - len({uf.find(x) for x, _ in stones})
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int removeStones(int[][] stones) {
        int m = 10001;
        UnionFind uf = new UnionFind(m << 1);
        for (var st : stones) {
            uf.union(st[0], st[1] + m);
        }
        Set<Integer> s = new HashSet<>();
        for (var st : stones) {
            s.add(uf.find(st[0]));
        }
        return stones.length - s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 10001;
        UnionFind uf(m << 1);
        for (auto& st : stones) {
            uf.unite(st[0], st[1] + m);
        }
        unordered_set<int> s;
        for (auto& st : stones) {
            s.insert(uf.find(st[0]));
        }
        return stones.size() - s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func removeStones(stones [][]int) (ans int) {
	m := 10001
	uf := newUnionFind(m << 1)
	for _, st := range stones {
		uf.union(st[0], st[1]+m)
	}
	s := map[int]bool{}
	for _, st := range stones {
		s[uf.find(st[0])] = true
	}
	return len(stones) - len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeStones(stones: number[][]): number {
    const n = stones.length;
    const g: number[][] = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const [y, x] = stones[i];
        for (let j = i + 1; j < n; j++) {
            if (y === stones[j][0] || x === stones[j][1]) {
                g[i].push(j);
                g[j].push(i);
            }
        }
    }

    const dfs = (i: number) => {
        const seen = new Set<number>();

        let q = [i];
        while (q.length) {
            const qNext: number[] = [];

            for (const i of q) {
                if (seen.has(i)) continue;
                seen.add(i);
                set.delete(i);
                qNext.push(...g[i]);
            }

            q = qNext;
        }
    };

    const set = new Set(Array.from({ length: n }, (_, i) => i));
    let ans = n;
    for (const i of set) {
        dfs(i);
        ans--;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function removeStones(stones) {
    const n = stones.length;
    const g = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const [y, x] = stones[i];
        for (let j = i + 1; j < n; j++) {
            if (y === stones[j][0] || x === stones[j][1]) {
                g[i].push(j);
                g[j].push(i);
            }
        }
    }

    const dfs = i => {
        const seen = new Set();

        let q = [i];
        while (q.length) {
            const qNext = [];

            for (const i of q) {
                if (seen.has(i)) continue;
                seen.add(i);
                set.delete(i);
                qNext.push(...g[i]);
            }

            q = qNext;
        }
    };

    const set = new Set(Array.from({ length: n }, (_, i) => i));
    let ans = n;
    for (const i of set) {
        dfs(i);
        ans--;
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

<p><code>n</code> 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。</p>

<p>如果一块石头的 <strong>同行或者同列</strong> 上有其他石头存在，那么就可以移除这块石头。</p>

<p>给你一个长度为 <code>n</code> 的数组 <code>stones</code> ，其中 <code>stones[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示第 <code>i</code> 块石头的位置，返回 <strong>可以移除的石子</strong> 的最大数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
<strong>输出：</strong>5
<strong>解释：</strong>一种移除 5 块石头的方法如下所示：
1. 移除石头 [2,2] ，因为它和 [2,1] 同行。
2. 移除石头 [2,1] ，因为它和 [0,1] 同列。
3. 移除石头 [1,2] ，因为它和 [1,0] 同行。
4. 移除石头 [1,0] ，因为它和 [0,0] 同列。
5. 移除石头 [0,1] ，因为它和 [0,0] 同行。
石头 [0,0] 不能移除，因为它没有与另一块石头同行/列。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
<strong>输出：</strong>3
<strong>解释：</strong>一种移除 3 块石头的方法如下所示：
1. 移除石头 [2,2] ，因为它和 [2,0] 同行。
2. 移除石头 [2,0] ，因为它和 [0,0] 同列。
3. 移除石头 [0,2] ，因为它和 [0,0] 同行。
石头 [0,0] 和 [1,1] 不能移除，因为它们没有与另一块石头同行/列。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>stones = [[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>[0,0] 是平面上唯一一块石头，所以不可以移除它。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= stones.length <= 1000</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>4</sup></code></li>
	<li>不会有两块石头放在同一个坐标点上</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以用并查集维护石头之间的关系。如果两块石头在同一行或同一列，我们就认为它们之间有关系，可以通过并查集将它们连接起来。最后，我们统计并查集中有多少个连通分量，这个数值就是可以剩余的石头的数量，那么总共可以移除的石头数量就是石头总数减去剩余的石头数量。我们也可以在合并的时候，记录成功合并的次数，这个次数就是可以移除的石头的数量。

时间复杂度 $O(n^2 \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 为石头的数量。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        uf = UnionFind(len(stones))
        ans = 0
        for i, (x1, y1) in enumerate(stones):
            for j, (x2, y2) in enumerate(stones[:i]):
                if x1 == x2 or y1 == y2:
                    ans += uf.union(i, j)
        return ans
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ans += uf.union(i, j) ? 1 : 0;
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ans += uf.unite(i, j);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func removeStones(stones [][]int) (ans int) {
	n := len(stones)
	uf := newUnionFind(n)
	for i, s1 := range stones {
		for j, s2 := range stones[:i] {
			if s1[0] == s2[0] || s1[1] == s2[1] {
				if uf.union(i, j) {
					ans++
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function removeStones(stones: number[][]): number {
    const n = stones.length;
    const uf = new UnionFind(n);
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (stones[i][0] === stones[j][0] || stones[i][1] === stones[j][1]) {
                ans += uf.union(i, j) ? 1 : 0;
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集（优化）

我们可以将石头的纵坐标加上一个偏移量，这样就可以将横坐标和纵坐标统一起来，然后用并查集维护横坐标和纵坐标之间的关系。

我们遍历每一块石头，将横坐标与纵坐标进行合并。

最后，我们再遍历所有石头，将每块石头的横坐标的根节点放到一个集合中，那么这个集合的数量就是可以剩余的石头的数量，总共可以移除的石头数量就是石头总数减去剩余的石头数量。

时间复杂度 $O(n \times \alpha(m))$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为石头的数量和横纵坐标的最大值。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        m = 10001
        uf = UnionFind(m << 1)
        for x, y in stones:
            uf.union(x, y + m)
        return len(stones) - len({uf.find(x) for x, _ in stones})
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int removeStones(int[][] stones) {
        int m = 10001;
        UnionFind uf = new UnionFind(m << 1);
        for (var st : stones) {
            uf.union(st[0], st[1] + m);
        }
        Set<Integer> s = new HashSet<>();
        for (var st : stones) {
            s.add(uf.find(st[0]));
        }
        return stones.length - s.size();
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 10001;
        UnionFind uf(m << 1);
        for (auto& st : stones) {
            uf.unite(st[0], st[1] + m);
        }
        unordered_set<int> s;
        for (auto& st : stones) {
            s.insert(uf.find(st[0]));
        }
        return stones.size() - s.size();
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func removeStones(stones [][]int) (ans int) {
	m := 10001
	uf := newUnionFind(m << 1)
	for _, st := range stones {
		uf.union(st[0], st[1]+m)
	}
	s := map[int]bool{}
	for _, st := range stones {
		s[uf.find(st[0])] = true
	}
	return len(stones) - len(s)
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function removeStones(stones: number[][]): number {
    const m = 10001;
    const uf = new UnionFind(m << 1);
    for (const [x, y] of stones) {
        uf.union(x, y + m);
    }
    const s = new Set<number>();
    for (const [x, _] of stones) {
        s.add(uf.find(x));
    }
    return stones.length - s.size;
}
```

<!-- tabs:end -->

<!--- solution:end --->

<!-- solution:start -->

### Solution 3: DFS

<!-- tabs:start -->

#### TypeScript

```ts
function removeStones(stones: number[][]): number {
    const n = stones.length;
    const g: number[][] = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const [y, x] = stones[i];
        for (let j = i + 1; j < n; j++) {
            if (y === stones[j][0] || x === stones[j][1]) {
                g[i].push(j);
                g[j].push(i);
            }
        }
    }

    const dfs = (i: number) => {
        const seen = new Set<number>();

        let q = [i];
        while (q.length) {
            const qNext: number[] = [];

            for (const i of q) {
                if (seen.has(i)) continue;
                seen.add(i);
                set.delete(i);
                qNext.push(...g[i]);
            }

            q = qNext;
        }
    };

    const set = new Set(Array.from({ length: n }, (_, i) => i));
    let ans = n;
    for (const i of set) {
        dfs(i);
        ans--;
    }

    return ans;
}
```

#### JavaScript

```js
function removeStones(stones) {
    const n = stones.length;
    const g = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const [y, x] = stones[i];
        for (let j = i + 1; j < n; j++) {
            if (y === stones[j][0] || x === stones[j][1]) {
                g[i].push(j);
                g[j].push(i);
            }
        }
    }

    const dfs = i => {
        const seen = new Set();

        let q = [i];
        while (q.length) {
            const qNext = [];

            for (const i of q) {
                if (seen.has(i)) continue;
                seen.add(i);
                set.delete(i);
                qNext.push(...g[i]);
            }

            q = qNext;
        }
    };

    const set = new Set(Array.from({ length: n }, (_, i) => i));
    let ans = n;
    for (const i of set) {
        dfs(i);
        ans--;
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [948. 令牌放置](https://leetcode.cn/problems/bag-of-tokens){#948}

{{< tabs "948" >}}

{{% tab "python" %}}
```python
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        ans = score = 0
        i, j = 0, len(tokens) - 1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                score, i = score + 1, i + 1
                ans = max(ans, score)
            elif score:
                power += tokens[j]
                score, j = score - 1, j - 1
            else:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int ans = 0, score = 0;
        for (int i = 0, j = tokens.length - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = Math.max(ans, ++score);
            } else if (score > 0) {
                power += tokens[j--];
                --score;
            } else {
                break;
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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int ans = 0, score = 0;
        for (int i = 0, j = tokens.size() - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = max(ans, ++score);
            } else if (score > 0) {
                power += tokens[j--];
                --score;
            } else {
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bagOfTokensScore(tokens []int, power int) (ans int) {
	sort.Ints(tokens)
	i, j := 0, len(tokens)-1
	score := 0
	for i <= j {
		if power >= tokens[i] {
			power -= tokens[i]
			i++
			score++
			ans = max(ans, score)
		} else if score > 0 {
			power += tokens[j]
			j--
			score--
		} else {
			break
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function bagOfTokensScore(tokens: number[], power: number): number {
    tokens.sort((a, b) => a - b);
    let [i, j] = [0, tokens.length - 1];
    let [ans, score] = [0, 0];
    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i++];
            ans = Math.max(ans, ++score);
        } else if (score) {
            power += tokens[j--];
            score--;
        } else {
            break;
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

<p>你的初始 <strong>能量</strong> 为 <code>power</code>，初始 <strong>分数</strong> 为&nbsp;<code>0</code>，只有一包令牌以整数数组&nbsp;<code>tokens</code>&nbsp;给出。其中 <code>tokens[i]</code> 是第 <code>i</code> 个令牌的值（下标从 0 开始）。</p>

<p>你的目标是通过有策略地使用这些令牌以&nbsp;<strong>最大化</strong>&nbsp;总 <strong>分数</strong>。在一次行动中，你可以用两种方式中的一种来使用一个&nbsp;<strong>未被使用的</strong> 令牌（但不是对同一个令牌使用两种方式）：</p>

<ul>
	<li><strong>朝上</strong>：如果你当前&nbsp;<strong>至少</strong> 有&nbsp;<code>tokens[i]</code>&nbsp;点 <strong>能量</strong> ，可以使用令牌 <code>i</code> ，失去&nbsp;<code>tokens[i]</code>&nbsp;点 <strong>能量</strong> ，并得到&nbsp;<code>1</code>&nbsp;<strong>分</strong> 。</li>
	<li><strong>朝下</strong>：如果你当前至少有&nbsp;<code>1</code>&nbsp;<strong>分 </strong>，可以使用令牌 <code>i</code> ，获得&nbsp;<code>tokens[i]</code> 点 <strong>能量</strong> ，并失去&nbsp;<code>1</code>&nbsp;<strong>分</strong> 。</li>
</ul>

<p>在使用 <strong>任意</strong> 数量的令牌后，返回我们可以得到的最大 <strong>分数</strong> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>tokens = [100], power = 50
<strong>输出：</strong>0
<strong>解释：</strong>因为你的初始分数为 <code>0，</code>无法使令牌朝下。你也不能使令牌朝上因为你的能量（<code>50</code>）比 <code>tokens[0]</code>&nbsp;少（<code>100</code>）。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>tokens = [200,100], power = 150
<strong>输出：</strong>1
<strong>解释：</strong>使令牌 1 正面朝上，能量变为 50，分数变为 1 。
不必使用令牌 0，因为你无法使用它来提高分数。可得到的最大分数是 <code>1</code>。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>tokens = [100,200,300,400], power = 200
<strong>输出：</strong>2
<strong>解释：</strong>按下面顺序使用令牌可以得到 2 分：
1. 令牌 0 (<code>100</code>)正面朝上，能量变为 <code>100</code> ，分数变为 <code>1</code>
2. 令牌 3 (<code>400</code>)正面朝下，能量变为 <code>500</code> ，分数变为 <code>0</code>
3. 令牌 1 (<code>200</code>)正面朝上，能量变为 <code>300</code> ，分数变为 <code>1</code>
4. 令牌 2 (<code>300</code>)正面朝上，能量变为 <code>0</code> ，分数变为 <code>2</code>

可得的最大分数是 2。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= tokens.length &lt;= 1000</code></li>
	<li><code>0 &lt;= tokens[i],&nbsp;power &lt; 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序 + 双指针

令牌的使用方法有两种，一种是消耗能量得到分数，一种是消耗分数得到能量。显然，我们应该消耗尽可能少的能量来得到尽可能多的分数。

因此，我们可以将令牌按照消耗能量的多少进行排序，然后使用双指针，一个指针从左向右遍历，一个指针从右向左遍历，每次遍历都尽可能地消耗能量得到分数，然后更新最大分数。如果当前能量不足以消耗当前令牌，那么我们就尝试使用分数来消耗当前令牌，如果分数不足以消耗当前令牌，那么我们就停止遍历。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是令牌的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        ans = score = 0
        i, j = 0, len(tokens) - 1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                score, i = score + 1, i + 1
                ans = max(ans, score)
            elif score:
                power += tokens[j]
                score, j = score - 1, j - 1
            else:
                break
        return ans
```

#### Java

```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int ans = 0, score = 0;
        for (int i = 0, j = tokens.length - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = Math.max(ans, ++score);
            } else if (score > 0) {
                power += tokens[j--];
                --score;
            } else {
                break;
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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int ans = 0, score = 0;
        for (int i = 0, j = tokens.size() - 1; i <= j;) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = max(ans, ++score);
            } else if (score > 0) {
                power += tokens[j--];
                --score;
            } else {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func bagOfTokensScore(tokens []int, power int) (ans int) {
	sort.Ints(tokens)
	i, j := 0, len(tokens)-1
	score := 0
	for i <= j {
		if power >= tokens[i] {
			power -= tokens[i]
			i++
			score++
			ans = max(ans, score)
		} else if score > 0 {
			power += tokens[j]
			j--
			score--
		} else {
			break
		}
	}
	return
}
```

#### TypeScript

```ts
function bagOfTokensScore(tokens: number[], power: number): number {
    tokens.sort((a, b) => a - b);
    let [i, j] = [0, tokens.length - 1];
    let [ans, score] = [0, 0];
    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i++];
            ans = Math.max(ans, ++score);
        } else if (score) {
            power += tokens[j--];
            score--;
        } else {
            break;
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

# [949. 给定数字能组成的最大时间](https://leetcode.cn/problems/largest-time-for-given-digits){#949}

{{< tabs "949" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        ans = -1
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    if i != j and i != k and j != k:
                        h = arr[i] * 10 + arr[j]
                        m = arr[k] * 10 + arr[6 - i - j - k]
                        if h < 24 and m < 60:
                            ans = max(ans, h * 60 + m)
        return '' if ans < 0 else f'{ans // 60:02}:{ans % 60:02}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestTimeFromDigits(int[] arr) {
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i != j && j != k && i != k) {
                        int h = arr[i] * 10 + arr[j];
                        int m = arr[k] * 10 + arr[6 - i - j - k];
                        if (h < 24 && m < 60) {
                            ans = Math.max(ans, h * 60 + m);
                        }
                    }
                }
            }
        }
        return ans < 0 ? "" : String.format("%02d:%02d", ans / 60, ans % 60);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i != j && j != k && i != k) {
                        int h = arr[i] * 10 + arr[j];
                        int m = arr[k] * 10 + arr[6 - i - j - k];
                        if (h < 24 && m < 60) {
                            ans = max(ans, h * 60 + m);
                        }
                    }
                }
            }
        }
        if (ans < 0) return "";
        int h = ans / 60, m = ans % 60;
        return to_string(h / 10) + to_string(h % 10) + ":" + to_string(m / 10) + to_string(m % 10);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestTimeFromDigits(arr []int) string {
	ans := -1
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				if i != j && j != k && i != k {
					h := arr[i]*10 + arr[j]
					m := arr[k]*10 + arr[6-i-j-k]
					if h < 24 && m < 60 {
						ans = max(ans, h*60+m)
					}
				}
			}
		}
	}
	if ans < 0 {
		return ""
	}
	return fmt.Sprintf("%02d:%02d", ans/60, ans%60)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。</p>

<p>24 小时格式为 <code>"HH:MM"</code> ，其中 <code>HH</code> 在 <code>00</code> 到 <code>23</code> 之间，<code>MM</code> 在 <code>00</code> 到 <code>59</code> 之间。最小的 24 小时制时间是 <code>00:00</code> ，而最大的是 <code>23:59</code> 。从 00:00 （午夜）开始算起，过得越久，时间越大。</p>

<p>以长度为 5 的字符串，按 <code>"HH:MM"</code> 格式返回答案。如果不能确定有效时间，则返回空字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4]
<strong>输出：</strong>"23:41"
<strong>解释：</strong>有效的 24 小时制时间是 "12:34"，"12:43"，"13:24"，"13:42"，"14:23"，"14:32"，"21:34"，"21:43"，"23:14" 和 "23:41" 。这些时间中，"23:41" 是最大时间。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [5,5,5,5]
<strong>输出：</strong>""
<strong>解释：</strong>不存在有效的 24 小时制时间，因为 "55:55" 无效。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,0,0,0]
<strong>输出：</strong>"00:00"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,0,1,0]
<strong>输出：</strong>"10:00"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr.length == 4</code></li>
	<li><code>0 <= arr[i] <= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们可以枚举所有的 4 个数字的排列，然后判断每个排列是否满足题目要求，如果满足则更新答案。

时间复杂度 $O(4^3)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        cnt = [0] * 10
        for v in arr:
            cnt[v] += 1
        for h in range(23, -1, -1):
            for m in range(59, -1, -1):
                t = [0] * 10
                t[h // 10] += 1
                t[h % 10] += 1
                t[m // 10] += 1
                t[m % 10] += 1
                if cnt == t:
                    return f'{h:02}:{m:02}'
        return ''
```

#### Java

```java
class Solution {
    public String largestTimeFromDigits(int[] arr) {
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i != j && j != k && i != k) {
                        int h = arr[i] * 10 + arr[j];
                        int m = arr[k] * 10 + arr[6 - i - j - k];
                        if (h < 24 && m < 60) {
                            ans = Math.max(ans, h * 60 + m);
                        }
                    }
                }
            }
        }
        return ans < 0 ? "" : String.format("%02d:%02d", ans / 60, ans % 60);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i != j && j != k && i != k) {
                        int h = arr[i] * 10 + arr[j];
                        int m = arr[k] * 10 + arr[6 - i - j - k];
                        if (h < 24 && m < 60) {
                            ans = max(ans, h * 60 + m);
                        }
                    }
                }
            }
        }
        if (ans < 0) return "";
        int h = ans / 60, m = ans % 60;
        return to_string(h / 10) + to_string(h % 10) + ":" + to_string(m / 10) + to_string(m % 10);
    }
};
```

#### Go

```go
func largestTimeFromDigits(arr []int) string {
	ans := -1
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				if i != j && j != k && i != k {
					h := arr[i]*10 + arr[j]
					m := arr[k]*10 + arr[6-i-j-k]
					if h < 24 && m < 60 {
						ans = max(ans, h*60+m)
					}
				}
			}
		}
	}
	if ans < 0 {
		return ""
	}
	return fmt.Sprintf("%02d:%02d", ans/60, ans%60)
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
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        ans = -1
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    if i != j and i != k and j != k:
                        h = arr[i] * 10 + arr[j]
                        m = arr[k] * 10 + arr[6 - i - j - k]
                        if h < 24 and m < 60:
                            ans = max(ans, h * 60 + m)
        return '' if ans < 0 else f'{ans // 60:02}:{ans % 60:02}'
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
