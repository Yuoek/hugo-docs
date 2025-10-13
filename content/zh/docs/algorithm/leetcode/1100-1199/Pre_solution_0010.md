---
title: "1190_反转每对括号间的子串"
date: 2025-10-08T18:36:57+08:00
weight: 10
tags: [二分查找, 动态规划, 双连通分量, 哈希表, 图, 堆（优先队列）, 多线程, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1190_反转每对括号间的子串](#1190)
#### [栈](#1190)
#### [字符串](#1190)
### [1191_K 次串联后最大子数组之和](#1191)
#### [数组](#1191)
#### [动态规划](#1191)
### [1192_查找集群内的关键连接](#1192)
#### [深度优先搜索](#1192)
#### [图](#1192)
#### [双连通分量](#1192)
### [1193_每月交易 I](#1193)
#### [数据库](#1193)
### [1194_锦标赛优胜者 🔒](#1194)
#### [数据库](#1194)
### [1195_交替打印字符串](#1195)
#### [多线程](#1195)
### [1196_最多可以买到的苹果数量 🔒](#1196)
#### [贪心](#1196)
#### [数组](#1196)
#### [排序](#1196)
### [1197_进击的骑士 🔒](#1197)
#### [广度优先搜索](#1197)
### [1198_找出所有行中最小公共元素 🔒](#1198)
#### [数组](#1198)
#### [哈希表](#1198)
#### [二分查找](#1198)
#### [计数](#1198)
#### [矩阵](#1198)
### [1199_建造街区的最短时间 🔒](#1199)
#### [贪心](#1199)
#### [数组](#1199)
#### [数学](#1199)
#### [堆（优先队列）](#1199)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1190_反转每对括号间的子串
___
#### 栈
___
#### 字符串
---
### 1191_K 次串联后最大子数组之和
___
#### 数组
___
#### 动态规划
---
### 1192_查找集群内的关键连接
___
#### 深度优先搜索
___
#### 图
___
#### 双连通分量
---
### 1193_每月交易 I
___
#### 数据库
---
### 1194_锦标赛优胜者 🔒
___
#### 数据库
---
### 1195_交替打印字符串
___
#### 多线程
---
### 1196_最多可以买到的苹果数量 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1197_进击的骑士 🔒
___
#### 广度优先搜索
---
### 1198_找出所有行中最小公共元素 🔒
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 计数
___
#### 矩阵
---
### 1199_建造街区的最短时间 🔒
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双连通分量 |
| 哈希表 | 图 | 堆（优先队列） |
| 多线程 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 栈 | 深度优先搜索 |
| 矩阵 | 计数 | 贪心 |

# [1190. 反转每对括号间的子串](https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses){#1190}

{{< tabs "1190" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        d = [0] * n
        stk = []
        for i, c in enumerate(s):
            if c == "(":
                stk.append(i)
            elif c == ")":
                j = stk.pop()
                d[i], d[j] = j, i
        i, x = 0, 1
        ans = []
        while i < n:
            if s[i] in "()":
                i = d[i]
                x = -x
            else:
                ans.append(s[i])
            i += x
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        int[] d = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                stk.push(i);
            } else if (s.charAt(i) == ')') {
                int j = stk.pop();
                d[i] = j;
                d[j] = i;
            }
        }
        StringBuilder ans = new StringBuilder();
        int i = 0, x = 1;
        while (i < n) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = d[i];
                x = -x;
            } else {
                ans.append(s.charAt(i));
            }
            i += x;
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
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> d(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                d[i] = j;
                d[j] = i;
            }
        }
        int i = 0, x = 1;
        string ans;
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = d[i];
                x = -x;
            } else {
                ans.push_back(s[i]);
            }
            i += x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseParentheses(s string) string {
	n := len(s)
	d := make([]int, n)
	stk := []int{}
	for i, c := range s {
		if c == '(' {
			stk = append(stk, i)
		} else if c == ')' {
			j := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			d[i], d[j] = j, i
		}
	}
	ans := []byte{}
	i, x := 0, 1
	for i < n {
		if s[i] == '(' || s[i] == ')' {
			i = d[i]
			x = -x
		} else {
			ans = append(ans, s[i])
		}
		i += x
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reverseParentheses(s: string): string {
    const n = s.length;
    const d: number[] = Array(n).fill(0);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(') {
            stk.push(i);
        } else if (s[i] === ')') {
            const j = stk.pop()!;
            d[i] = j;
            d[j] = i;
        }
    }
    let i = 0;
    let x = 1;
    const ans: string[] = [];
    while (i < n) {
        const c = s.charAt(i);
        if ('()'.includes(c)) {
            i = d[i];
            x = -x;
        } else {
            ans.push(c);
        }
        i += x;
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
    const n = s.length;
    const d = Array(n).fill(0);
    const stk = [];
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(') {
            stk.push(i);
        } else if (s[i] === ')') {
            const j = stk.pop();
            d[i] = j;
            d[j] = i;
        }
    }
    let i = 0;
    let x = 1;
    const ans = [];
    while (i < n) {
        const c = s.charAt(i);
        if ('()'.includes(c)) {
            i = d[i];
            x = -x;
        } else {
            ans.push(c);
        }
        i += x;
    }
    return ans.join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个字符串&nbsp;<code>s</code>（仅含有小写英文字母和括号）。</p>

<p>请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。</p>

<p>注意，您的结果中 <strong>不应</strong> 包含任何括号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "(abcd)"
<strong>输出：</strong>"dcba"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(u(love)i)"
<strong>输出：</strong>"iloveu"
<strong>解释：</strong>先反转子字符串 "love" ，然后反转整个字符串。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "(ed(et(oc))el)"
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 中只有小写英文字母和括号</li>
	<li>题目测试用例确保所有括号都是成对出现的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接用栈来模拟反转的过程。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseParentheses(self, s: str) -> str:
        stk = []
        for c in s:
            if c == ")":
                t = []
                while stk[-1] != "(":
                    t.append(stk.pop())
                stk.pop()
                stk.extend(t)
            else:
                stk.append(c)
        return "".join(stk)
```

#### Java

```java
class Solution {
    public String reverseParentheses(String s) {
        StringBuilder stk = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                StringBuilder t = new StringBuilder();
                while (stk.charAt(stk.length() - 1) != '(') {
                    t.append(stk.charAt(stk.length() - 1));
                    stk.deleteCharAt(stk.length() - 1);
                }
                stk.deleteCharAt(stk.length() - 1);
                stk.append(t);
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
    string reverseParentheses(string s) {
        string stk;
        for (char& c : s) {
            if (c == ')') {
                string t;
                while (stk.back() != '(') {
                    t.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                stk += t;
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
func reverseParentheses(s string) string {
	stk := []byte{}
	for i := range s {
		if s[i] == ')' {
			t := []byte{}
			for stk[len(stk)-1] != '(' {
				t = append(t, stk[len(stk)-1])
				stk = stk[:len(stk)-1]
			}
			stk = stk[:len(stk)-1]
			stk = append(stk, t...)
		} else {
			stk = append(stk, s[i])
		}
	}
	return string(stk)
}
```

#### TypeScript

```ts
function reverseParentheses(s: string): string {
    const stk: string[] = [];
    for (const c of s) {
        if (c === ')') {
            const t: string[] = [];
            while (stk.at(-1)! !== '(') {
                t.push(stk.pop()!);
            }
            stk.pop();
            stk.push(...t);
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
    const stk = [];
    for (const c of s) {
        if (c === ')') {
            const t = [];
            while (stk.at(-1) !== '(') {
                t.push(stk.pop());
            }
            stk.pop();
            stk.push(...t);
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：脑筋急转弯

我们观察发现，遍历字符串时，每一次遇到 `(` 或者 `)`，都是跳到对应的 `)` 或者 `(`，然后反转遍历的方向，继续遍历。

因此，我们可以用一个数组 $d$ 来记录每个 `(` 或者 `)` 对应的另一个括号的位置，即 $d[i]$ 表示 $i$ 处的括号对应的另一个括号的位置。直接用栈就可以求出 $d$ 数组。

然后，我们从左到右遍历字符串，遇到 `(` 或者 `)` 时，根据 $d$ 数组跳到对应的位置，然后反转方向，继续遍历，直到遍历完整个字符串。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        d = [0] * n
        stk = []
        for i, c in enumerate(s):
            if c == "(":
                stk.append(i)
            elif c == ")":
                j = stk.pop()
                d[i], d[j] = j, i
        i, x = 0, 1
        ans = []
        while i < n:
            if s[i] in "()":
                i = d[i]
                x = -x
            else:
                ans.append(s[i])
            i += x
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        int[] d = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                stk.push(i);
            } else if (s.charAt(i) == ')') {
                int j = stk.pop();
                d[i] = j;
                d[j] = i;
            }
        }
        StringBuilder ans = new StringBuilder();
        int i = 0, x = 1;
        while (i < n) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = d[i];
                x = -x;
            } else {
                ans.append(s.charAt(i));
            }
            i += x;
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> d(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                d[i] = j;
                d[j] = i;
            }
        }
        int i = 0, x = 1;
        string ans;
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = d[i];
                x = -x;
            } else {
                ans.push_back(s[i]);
            }
            i += x;
        }
        return ans;
    }
};
```

#### Go

```go
func reverseParentheses(s string) string {
	n := len(s)
	d := make([]int, n)
	stk := []int{}
	for i, c := range s {
		if c == '(' {
			stk = append(stk, i)
		} else if c == ')' {
			j := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			d[i], d[j] = j, i
		}
	}
	ans := []byte{}
	i, x := 0, 1
	for i < n {
		if s[i] == '(' || s[i] == ')' {
			i = d[i]
			x = -x
		} else {
			ans = append(ans, s[i])
		}
		i += x
	}
	return string(ans)
}
```

#### TypeScript

```ts
function reverseParentheses(s: string): string {
    const n = s.length;
    const d: number[] = Array(n).fill(0);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(') {
            stk.push(i);
        } else if (s[i] === ')') {
            const j = stk.pop()!;
            d[i] = j;
            d[j] = i;
        }
    }
    let i = 0;
    let x = 1;
    const ans: string[] = [];
    while (i < n) {
        const c = s.charAt(i);
        if ('()'.includes(c)) {
            i = d[i];
            x = -x;
        } else {
            ans.push(c);
        }
        i += x;
    }
    return ans.join('');
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
    const n = s.length;
    const d = Array(n).fill(0);
    const stk = [];
    for (let i = 0; i < n; ++i) {
        if (s[i] === '(') {
            stk.push(i);
        } else if (s[i] === ')') {
            const j = stk.pop();
            d[i] = j;
            d[j] = i;
        }
    }
    let i = 0;
    let x = 1;
    const ans = [];
    while (i < n) {
        const c = s.charAt(i);
        if ('()'.includes(c)) {
            i = d[i];
            x = -x;
        } else {
            ans.push(c);
        }
        i += x;
    }
    return ans.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1191. K 次串联后最大子数组之和](https://leetcode.cn/problems/k-concatenation-maximum-sum){#1191}

{{< tabs "1191" >}}

{{% tab "python" %}}
```python
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        s = mx_pre = mi_pre = mx_sub = 0
        for x in arr:
            s += x
            mx_pre = max(mx_pre, s)
            mi_pre = min(mi_pre, s)
            mx_sub = max(mx_sub, s - mi_pre)
        ans = mx_sub
        mod = 10**9 + 7
        if k == 1:
            return ans % mod
        mx_suf = s - mi_pre
        ans = max(ans, mx_pre + mx_suf)
        if s > 0:
            ans = max(ans, (k - 2) * s + mx_pre + mx_suf)
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long s = 0, mxPre = 0, miPre = 0, mxSub = 0;
        for (int x : arr) {
            s += x;
            mxPre = Math.max(mxPre, s);
            miPre = Math.min(miPre, s);
            mxSub = Math.max(mxSub, s - miPre);
        }
        long ans = mxSub;
        final int mod = (int) 1e9 + 7;
        if (k == 1) {
            return (int) (ans % mod);
        }
        long mxSuf = s - miPre;
        ans = Math.max(ans, mxPre + mxSuf);
        if (s > 0) {
            ans = Math.max(ans, (k - 2) * s + mxPre + mxSuf);
        }
        return (int) (ans % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long s = 0, mxPre = 0, miPre = 0, mxSub = 0;
        for (int x : arr) {
            s += x;
            mxPre = max(mxPre, s);
            miPre = min(miPre, s);
            mxSub = max(mxSub, s - miPre);
        }
        long ans = mxSub;
        const int mod = 1e9 + 7;
        if (k == 1) {
            return ans % mod;
        }
        long mxSuf = s - miPre;
        ans = max(ans, mxPre + mxSuf);
        if (s > 0) {
            ans = max(ans, mxPre + (k - 2) * s + mxSuf);
        }
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kConcatenationMaxSum(arr []int, k int) int {
	var s, mxPre, miPre, mxSub int
	for _, x := range arr {
		s += x
		mxPre = max(mxPre, s)
		miPre = min(miPre, s)
		mxSub = max(mxSub, s-miPre)
	}
	const mod = 1e9 + 7
	ans := mxSub
	if k == 1 {
		return ans % mod
	}
	mxSuf := s - miPre
	ans = max(ans, mxSuf+mxPre)
	if s > 0 {
		ans = max(ans, mxSuf+(k-2)*s+mxPre)
	}
	return ans % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;<code>arr</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，通过重复&nbsp;<code>k</code>&nbsp;次来修改数组。</p>

<p>例如，如果&nbsp;<code>arr = [1, 2]</code>&nbsp;，<meta charset="UTF-8" />&nbsp;<code>k = 3</code>&nbsp;，那么修改后的数组将是 <code>[1, 2, 1, 2, 1, 2]</code> 。</p>

<p>返回修改后的数组中的最大的子数组之和。注意，子数组长度可以是 <code>0</code>，在这种情况下它的总和也是 <code>0</code>。</p>

<p>由于&nbsp;<strong>结果可能会很大</strong>，需要返回的<meta charset="UTF-8" />&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;的&nbsp;<strong>模</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2], k = 3
<strong>输出：</strong>9
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,-2,1], k = 5
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [-1,-2], k = 7
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 分类讨论

我们记数组 $arr$ 所有元素之和为 $s$，最大前缀和为 $mxPre$，最小前缀和为 $miPre$，最大子数组和为 $mxSub$。

遍历数组 $arr$，对于每个元素 $x$，我们更新 $s = s + x$, $mxPre = \max(mxPre, s)$, $miPre = \min(miPre, s)$, $mxSub = \max(mxSub, s - miPre)$。

接下来，我们考虑 $k$ 的取值情况：

-   当 $k = 1$ 时，答案为 $mxSub$。
-   当 $k \ge 2$ 时，如果最大子数组横跨两个 $arr$，那么答案为 $mxPre + mxSuf$，其中 $mxSuf = s - miPre$。
-   当 $k \ge 2$ 且 $s > 0$ 时，如果最大子数组横跨三个 $arr$，那么答案为 $(k - 2) \times s + mxPre + mxSuf$。

最后，我们返回答案对 $10^9 + 7$ 取模的结果。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        s = mx_pre = mi_pre = mx_sub = 0
        for x in arr:
            s += x
            mx_pre = max(mx_pre, s)
            mi_pre = min(mi_pre, s)
            mx_sub = max(mx_sub, s - mi_pre)
        ans = mx_sub
        mod = 10**9 + 7
        if k == 1:
            return ans % mod
        mx_suf = s - mi_pre
        ans = max(ans, mx_pre + mx_suf)
        if s > 0:
            ans = max(ans, (k - 2) * s + mx_pre + mx_suf)
        return ans % mod
```

#### Java

```java
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long s = 0, mxPre = 0, miPre = 0, mxSub = 0;
        for (int x : arr) {
            s += x;
            mxPre = Math.max(mxPre, s);
            miPre = Math.min(miPre, s);
            mxSub = Math.max(mxSub, s - miPre);
        }
        long ans = mxSub;
        final int mod = (int) 1e9 + 7;
        if (k == 1) {
            return (int) (ans % mod);
        }
        long mxSuf = s - miPre;
        ans = Math.max(ans, mxPre + mxSuf);
        if (s > 0) {
            ans = Math.max(ans, (k - 2) * s + mxPre + mxSuf);
        }
        return (int) (ans % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long s = 0, mxPre = 0, miPre = 0, mxSub = 0;
        for (int x : arr) {
            s += x;
            mxPre = max(mxPre, s);
            miPre = min(miPre, s);
            mxSub = max(mxSub, s - miPre);
        }
        long ans = mxSub;
        const int mod = 1e9 + 7;
        if (k == 1) {
            return ans % mod;
        }
        long mxSuf = s - miPre;
        ans = max(ans, mxPre + mxSuf);
        if (s > 0) {
            ans = max(ans, mxPre + (k - 2) * s + mxSuf);
        }
        return ans % mod;
    }
};
```

#### Go

```go
func kConcatenationMaxSum(arr []int, k int) int {
	var s, mxPre, miPre, mxSub int
	for _, x := range arr {
		s += x
		mxPre = max(mxPre, s)
		miPre = min(miPre, s)
		mxSub = max(mxSub, s-miPre)
	}
	const mod = 1e9 + 7
	ans := mxSub
	if k == 1 {
		return ans % mod
	}
	mxSuf := s - miPre
	ans = max(ans, mxSuf+mxPre)
	if s > 0 {
		ans = max(ans, mxSuf+(k-2)*s+mxPre)
	}
	return ans % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1192. 查找集群内的关键连接](https://leetcode.cn/problems/critical-connections-in-a-network){#1192}

{{< tabs "1192" >}}

{{% tab "python" %}}
```python
class Solution:
    def criticalConnections(
        self, n: int, connections: List[List[int]]
    ) -> List[List[int]]:
        def tarjan(a: int, fa: int):
            nonlocal now
            now += 1
            dfn[a] = low[a] = now
            for b in g[a]:
                if b == fa:
                    continue
                if not dfn[b]:
                    tarjan(b, a)
                    low[a] = min(low[a], low[b])
                    if low[b] > dfn[a]:
                        ans.append([a, b])
                else:
                    low[a] = min(low[a], dfn[b])

        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append(b)
            g[b].append(a)

        dfn = [0] * n
        low = [0] * n
        now = 0
        ans = []
        tarjan(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int now;
    private List<Integer>[] g;
    private List<List<Integer>> ans = new ArrayList<>();
    private int[] dfn;
    private int[] low;

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        dfn = new int[n];
        low = new int[n];
        for (var e : connections) {
            int a = e.get(0), b = e.get(1);
            g[a].add(b);
            g[b].add(a);
        }
        tarjan(0, -1);
        return ans;
    }

    private void tarjan(int a, int fa) {
        dfn[a] = low[a] = ++now;
        for (int b : g[a]) {
            if (b == fa) {
                continue;
            }
            if (dfn[b] == 0) {
                tarjan(b, a);
                low[a] = Math.min(low[a], low[b]);
                if (low[b] > dfn[a]) {
                    ans.add(List.of(a, b));
                }
            } else {
                low[a] = Math.min(low[a], dfn[b]);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int now = 0;
        vector<int> dfn(n);
        vector<int> low(n);
        vector<int> g[n];
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<vector<int>> ans;
        function<void(int, int)> tarjan = [&](int a, int fa) -> void {
            dfn[a] = low[a] = ++now;
            for (int b : g[a]) {
                if (b == fa) {
                    continue;
                }
                if (!dfn[b]) {
                    tarjan(b, a);
                    low[a] = min(low[a], low[b]);
                    if (low[b] > dfn[a]) {
                        ans.push_back({a, b});
                    }
                } else {
                    low[a] = min(low[a], dfn[b]);
                }
            }
        };
        tarjan(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func criticalConnections(n int, connections [][]int) (ans [][]int) {
	now := 0
	g := make([][]int, n)
	dfn := make([]int, n)
	low := make([]int, n)
	for _, e := range connections {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var tarjan func(int, int)
	tarjan = func(a, fa int) {
		now++
		dfn[a], low[a] = now, now
		for _, b := range g[a] {
			if b == fa {
				continue
			}
			if dfn[b] == 0 {
				tarjan(b, a)
				low[a] = min(low[a], low[b])
				if low[b] > dfn[a] {
					ans = append(ans, []int{a, b})
				}
			} else {
				low[a] = min(low[a], dfn[b])
			}
		}
	}
	tarjan(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function criticalConnections(n: number, connections: number[][]): number[][] {
    let now: number = 0;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => []);
    const dfn: number[] = Array(n).fill(0);
    const low: number[] = Array(n).fill(0);
    for (const [a, b] of connections) {
        g[a].push(b);
        g[b].push(a);
    }
    const ans: number[][] = [];
    const tarjan = (a: number, fa: number) => {
        dfn[a] = low[a] = ++now;
        for (const b of g[a]) {
            if (b === fa) {
                continue;
            }
            if (!dfn[b]) {
                tarjan(b, a);
                low[a] = Math.min(low[a], low[b]);
                if (low[b] > dfn[a]) {
                    ans.push([a, b]);
                }
            } else {
                low[a] = Math.min(low[a], dfn[b]);
            }
        }
    };
    tarjan(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>力扣数据中心有&nbsp;<code>n</code>&nbsp;台服务器，分别按从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>&nbsp;的方式进行了编号。它们之间以 <strong>服务器到服务器</strong> 的形式相互连接组成了一个内部集群，连接是无向的。用 &nbsp;<code>connections</code> 表示集群网络，<code>connections[i] = [a, b]</code>&nbsp;表示服务器 <code>a</code>&nbsp;和 <code>b</code>&nbsp;之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。</p>

<p><strong>关键连接</strong><em> </em>是在该集群中的重要连接，假如我们将它移除，便会导致某些服务器无法访问其他服务器。</p>

<p>请你以任意顺序返回该集群内的所有 <strong>关键连接</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1192.Critical%20Connections%20in%20a%20Network/images/critical-connections-in-a-network.png" style="height: 205px; width: 200px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
<strong>输出：</strong>[[1,3]]
<strong>解释：</strong>[[3,1]] 也是正确的。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>n = 2, connections = [[0,1]]
<b>输出：</b>[[0,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n - 1 &lt;= connections.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不存在重复的连接</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Tarjan 算法

此题中的「关键连接」即为「桥」。

「桥」：在一连通的无向图中，若去除某一边后会使得图不再连通，则这条边可以视作「桥」。

与之相应的概念还有「割点」。

「割点」：在一连通的无向图中，若去除某一点及所有与其相连的边后会使得图不再连通，则这个点可以视作「割点」。

用于求图中的「桥」与「割点」有一算法：tarjan 算法，这个算法使用先递归的访问相邻节点后访问节点自身的 dfs 方法，通过记录「访问的顺序：DFN」以及在递归结束后访问节点自身时探索其可以回溯到的最早被访问的节点来更新「最早可回溯的节点：low」，可以实现在 $O(n)$ 时间内找到图的「桥」与「割点」。同时，此种算法可以用于查找有向图中的强连通分量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def criticalConnections(
        self, n: int, connections: List[List[int]]
    ) -> List[List[int]]:
        def tarjan(a: int, fa: int):
            nonlocal now
            now += 1
            dfn[a] = low[a] = now
            for b in g[a]:
                if b == fa:
                    continue
                if not dfn[b]:
                    tarjan(b, a)
                    low[a] = min(low[a], low[b])
                    if low[b] > dfn[a]:
                        ans.append([a, b])
                else:
                    low[a] = min(low[a], dfn[b])

        g = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append(b)
            g[b].append(a)

        dfn = [0] * n
        low = [0] * n
        now = 0
        ans = []
        tarjan(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private int now;
    private List<Integer>[] g;
    private List<List<Integer>> ans = new ArrayList<>();
    private int[] dfn;
    private int[] low;

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        dfn = new int[n];
        low = new int[n];
        for (var e : connections) {
            int a = e.get(0), b = e.get(1);
            g[a].add(b);
            g[b].add(a);
        }
        tarjan(0, -1);
        return ans;
    }

    private void tarjan(int a, int fa) {
        dfn[a] = low[a] = ++now;
        for (int b : g[a]) {
            if (b == fa) {
                continue;
            }
            if (dfn[b] == 0) {
                tarjan(b, a);
                low[a] = Math.min(low[a], low[b]);
                if (low[b] > dfn[a]) {
                    ans.add(List.of(a, b));
                }
            } else {
                low[a] = Math.min(low[a], dfn[b]);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int now = 0;
        vector<int> dfn(n);
        vector<int> low(n);
        vector<int> g[n];
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<vector<int>> ans;
        function<void(int, int)> tarjan = [&](int a, int fa) -> void {
            dfn[a] = low[a] = ++now;
            for (int b : g[a]) {
                if (b == fa) {
                    continue;
                }
                if (!dfn[b]) {
                    tarjan(b, a);
                    low[a] = min(low[a], low[b]);
                    if (low[b] > dfn[a]) {
                        ans.push_back({a, b});
                    }
                } else {
                    low[a] = min(low[a], dfn[b]);
                }
            }
        };
        tarjan(0, -1);
        return ans;
    }
};
```

#### Go

```go
func criticalConnections(n int, connections [][]int) (ans [][]int) {
	now := 0
	g := make([][]int, n)
	dfn := make([]int, n)
	low := make([]int, n)
	for _, e := range connections {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var tarjan func(int, int)
	tarjan = func(a, fa int) {
		now++
		dfn[a], low[a] = now, now
		for _, b := range g[a] {
			if b == fa {
				continue
			}
			if dfn[b] == 0 {
				tarjan(b, a)
				low[a] = min(low[a], low[b])
				if low[b] > dfn[a] {
					ans = append(ans, []int{a, b})
				}
			} else {
				low[a] = min(low[a], dfn[b])
			}
		}
	}
	tarjan(0, -1)
	return
}
```

#### TypeScript

```ts
function criticalConnections(n: number, connections: number[][]): number[][] {
    let now: number = 0;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => []);
    const dfn: number[] = Array(n).fill(0);
    const low: number[] = Array(n).fill(0);
    for (const [a, b] of connections) {
        g[a].push(b);
        g[b].push(a);
    }
    const ans: number[][] = [];
    const tarjan = (a: number, fa: number) => {
        dfn[a] = low[a] = ++now;
        for (const b of g[a]) {
            if (b === fa) {
                continue;
            }
            if (!dfn[b]) {
                tarjan(b, a);
                low[a] = Math.min(low[a], low[b]);
                if (low[b] > dfn[a]) {
                    ans.push([a, b]);
                }
            } else {
                low[a] = Math.min(low[a], dfn[b]);
            }
        }
    };
    tarjan(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1193. 每月交易 I](https://leetcode.cn/problems/monthly-transactions-i){#1193}

{{< tabs "1193" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(1) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Transactions</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| country       | varchar |
| state         | enum    |
| amount        | int     |
| trans_date    | date    |
+---------------+---------+
id 是这个表的主键。
该表包含有关传入事务的信息。
state 列类型为 ["approved", "declined"] 之一。
</pre>

<p>&nbsp;</p>

<p>编写一个 sql 查询来查找每个月和每个国家/地区的事务数及其总金额、已批准的事务数及其总金额。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Transactions</code> table:
+------+---------+----------+--------+------------+
| id   | country | state    | amount | trans_date |
+------+---------+----------+--------+------------+
| 121  | US      | approved | 1000   | 2018-12-18 |
| 122  | US      | declined | 2000   | 2018-12-19 |
| 123  | US      | approved | 2000   | 2019-01-01 |
| 124  | DE      | approved | 2000   | 2019-01-07 |
+------+---------+----------+--------+------------+
<strong>输出：</strong>
+----------+---------+-------------+----------------+--------------------+-----------------------+
| month    | country | trans_count | approved_count | trans_total_amount | approved_total_amount |
+----------+---------+-------------+----------------+--------------------+-----------------------+
| 2018-12  | US      | 2           | 1              | 3000               | 1000                  |
| 2019-01  | US      | 1           | 1              | 2000               | 2000                  |
| 2019-01  | DE      | 1           | 1              | 2000               | 2000                  |
+----------+---------+-------------+----------------+--------------------+-----------------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和

我们可以先按照月份和国家分组，然后利用 `COUNT` 和 `SUM` 函数分别求出每个分组的事务数、已批准的事务数、总金额和已批准的总金额。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(1) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1194. 锦标赛优胜者 🔒](https://leetcode.cn/problems/tournament-winners){#1194}

{{< tabs "1194" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT first_player AS player_id, first_score AS score, group_id
        FROM
            Matches AS m
            JOIN Players AS p ON m.first_player = p.player_id
        UNION ALL
        SELECT second_player AS player_id, second_score AS score, group_id
        FROM
            Matches AS m
            JOIN Players AS p ON m.second_player = p.player_id
    ),
    t AS (
        SELECT group_id, player_id, SUM(score) AS scores
        FROM s
        GROUP BY player_id
    ),
    p AS (
        SELECT
            group_id,
            player_id,
            RANK() OVER (
                PARTITION BY group_id
                ORDER BY scores DESC, player_id
            ) AS rk
        FROM t
    )
SELECT group_id, player_id
FROM p
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Players</code>&nbsp;玩家表</p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| player_id   | int   |
| group_id    | int   |
+-------------+-------+
player_id 是此表的主键(具有唯一值的列)。
此表的每一行表示每个玩家的组。
</pre>

<p><code>Matches</code>&nbsp;赛事表</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| match_id      | int     |
| first_player  | int     |
| second_player | int     | 
| first_score   | int     |
| second_score  | int     |
+---------------+---------+
match_id 是此表的主键(具有唯一值的列)。
每一行是一场比赛的记录，first_player 和 second_player 表示该场比赛的球员 ID。
first_score 和 second_score 分别表示 first_player 和 second_player 的得分。
你可以假设，在每一场比赛中，球员都属于同一组。
</pre>

<p>&nbsp;</p>

<p>每组的获胜者是在组内累积得分最高的选手。如果平局，<code>player_id</code> <strong>最小&nbsp;</strong>的选手获胜。</p>

<p>编写解决方案来查找每组中的获胜者。</p>

<p>返回的结果表单 <strong>没有顺序要求</strong>&nbsp;。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Players 表</code>:
+-----------+------------+
| player_id | group_id   |
+-----------+------------+
| 15        | 1          |
| 25        | 1          |
| 30        | 1          |
| 45        | 1          |
| 10        | 2          |
| 35        | 2          |
| 50        | 2          |
| 20        | 3          |
| 40        | 3          |
+-----------+------------+
<code>Matches 表</code>:
+------------+--------------+---------------+-------------+--------------+
| match_id   | first_player | second_player | first_score | second_score |
+------------+--------------+---------------+-------------+--------------+
| 1          | 15           | 45            | 3           | 0            |
| 2          | 30           | 25            | 1           | 2            |
| 3          | 30           | 15            | 2           | 0            |
| 4          | 40           | 20            | 5           | 2            |
| 5          | 35           | 50            | 1           | 1            |
+------------+--------------+---------------+-------------+--------------+
<strong>输出：</strong>
+-----------+------------+
| group_id  | player_id  |
+-----------+------------+ 
| 1         | 15         |
| 2         | 35         |
| 3         | 40         |
+-----------+------------+</pre>

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
    s AS (
        SELECT first_player AS player_id, first_score AS score, group_id
        FROM
            Matches AS m
            JOIN Players AS p ON m.first_player = p.player_id
        UNION ALL
        SELECT second_player AS player_id, second_score AS score, group_id
        FROM
            Matches AS m
            JOIN Players AS p ON m.second_player = p.player_id
    ),
    t AS (
        SELECT group_id, player_id, SUM(score) AS scores
        FROM s
        GROUP BY player_id
    ),
    p AS (
        SELECT
            group_id,
            player_id,
            RANK() OVER (
                PARTITION BY group_id
                ORDER BY scores DESC, player_id
            ) AS rk
        FROM t
    )
SELECT group_id, player_id
FROM p
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1195. 交替打印字符串](https://leetcode.cn/problems/fizz-buzz-multithreaded){#1195}

{{< tabs "1195" >}}

{{% tab "java" %}}
```java
class FizzBuzz {
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    private Semaphore fSema = new Semaphore(0);
    private Semaphore bSema = new Semaphore(0);
    private Semaphore fbSema = new Semaphore(0);
    private Semaphore nSema = new Semaphore(1);

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i = i + 3) {
            if (i % 5 != 0) {
                fSema.acquire();
                printFizz.run();
                nSema.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i = i + 5) {
            if (i % 3 != 0) {
                bSema.acquire();
                printBuzz.run();
                nSema.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i = i + 15) {
            fbSema.acquire();
            printFizzBuzz.run();
            nSema.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            nSema.acquire();
            if (i % 3 == 0 && i % 5 == 0) {
                fbSema.release();
            } else if (i % 3 == 0) {
                fSema.release();
            } else if (i % 5 == 0) {
                bSema.release();
            } else {
                printNumber.accept(i);
                nSema.release();
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FizzBuzz {
private:
    std::mutex mtx;
    atomic<int> index;
    int n;

    // 这里主要运用到了C++11中的RAII锁(lock_guard)的知识。
    // 需要强调的一点是，在进入循环后，要时刻不忘加入index <= n的逻辑
public:
    FizzBuzz(int n) {
        this->n = n;
        index = 1;
    }

    void fizz(function<void()> printFizz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 3 && 0 != index % 5 && index <= n) {
                printFizz();
                index++;
            }
        }
    }

    void buzz(function<void()> printBuzz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 5 && 0 != index % 3 && index <= n) {
                printBuzz();
                index++;
            }
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 15 && index <= n) {
                printFizzBuzz();
                index++;
            }
        }
    }

    void number(function<void(int)> printNumber) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 != index % 3 && 0 != index % 5 && index <= n) {
                printNumber(index);
                index++;
            }
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个可以从 1 到 n 输出代表这个数字的字符串的程序，但是：</p>

<ul>
	<li>如果这个数字可以被 3 整除，输出 "fizz"。</li>
	<li>如果这个数字可以被 5 整除，输出 "buzz"。</li>
	<li>如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"。</li>
</ul>

<p>例如，当 <code>n = 15</code>，输出： <code>1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz</code>。</p>

<p>假设有这么一个类：</p>

<pre>
class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}</pre>

<p>请你实现一个有四个线程的多线程版  <code>FizzBuzz</code>， 同一个 <code>FizzBuzz</code> 实例会被如下四个线程使用：</p>

<ol>
	<li>线程A将调用 <code>fizz()</code> 来判断是否能被 3 整除，如果可以，则输出 <code>fizz</code>。</li>
	<li>线程B将调用 <code>buzz()</code> 来判断是否能被 5 整除，如果可以，则输出 <code>buzz</code>。</li>
	<li>线程C将调用 <code>fizzbuzz()</code> 来判断是否同时能被 3 和 5 整除，如果可以，则输出 <code>fizzbuzz</code>。</li>
	<li>线程D将调用 <code>number()</code> 来实现输出既不能被 3 整除也不能被 5 整除的数字。</li>
</ol>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>本题已经提供了打印字符串的相关方法，如 <code>printFizz()</code> 等，具体方法名请参考答题模板中的注释部分。</li>
</ul>

<p> </p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Java

```java
class FizzBuzz {
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    private Semaphore fSema = new Semaphore(0);
    private Semaphore bSema = new Semaphore(0);
    private Semaphore fbSema = new Semaphore(0);
    private Semaphore nSema = new Semaphore(1);

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i = i + 3) {
            if (i % 5 != 0) {
                fSema.acquire();
                printFizz.run();
                nSema.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i = i + 5) {
            if (i % 3 != 0) {
                bSema.acquire();
                printBuzz.run();
                nSema.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i = i + 15) {
            fbSema.acquire();
            printFizzBuzz.run();
            nSema.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            nSema.acquire();
            if (i % 3 == 0 && i % 5 == 0) {
                fbSema.release();
            } else if (i % 3 == 0) {
                fSema.release();
            } else if (i % 5 == 0) {
                bSema.release();
            } else {
                printNumber.accept(i);
                nSema.release();
            }
        }
    }
}
```

#### C++

```cpp
class FizzBuzz {
private:
    std::mutex mtx;
    atomic<int> index;
    int n;

    // 这里主要运用到了C++11中的RAII锁(lock_guard)的知识。
    // 需要强调的一点是，在进入循环后，要时刻不忘加入index <= n的逻辑
public:
    FizzBuzz(int n) {
        this->n = n;
        index = 1;
    }

    void fizz(function<void()> printFizz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 3 && 0 != index % 5 && index <= n) {
                printFizz();
                index++;
            }
        }
    }

    void buzz(function<void()> printBuzz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 5 && 0 != index % 3 && index <= n) {
                printBuzz();
                index++;
            }
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 == index % 15 && index <= n) {
                printFizzBuzz();
                index++;
            }
        }
    }

    void number(function<void(int)> printNumber) {
        while (index <= n) {
            std::lock_guard<std::mutex> lk(mtx);
            if (0 != index % 3 && 0 != index % 5 && index <= n) {
                printNumber(index);
                index++;
            }
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1196. 最多可以买到的苹果数量 🔒](https://leetcode.cn/problems/how-many-apples-can-you-put-into-the-basket){#1196}

{{< tabs "1196" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        weight.sort()
        s = 0
        for i, x in enumerate(weight):
            s += x
            if s > 5000:
                return i
        return len(weight)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNumberOfApples(int[] weight) {
        Arrays.sort(weight);
        int s = 0;
        for (int i = 0; i < weight.length; ++i) {
            s += weight[i];
            if (s > 5000) {
                return i;
            }
        }
        return weight.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int s = 0;
        for (int i = 0; i < weight.size(); ++i) {
            s += weight[i];
            if (s > 5000) {
                return i;
            }
        }
        return weight.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumberOfApples(weight []int) int {
	sort.Ints(weight)
	s := 0
	for i, x := range weight {
		s += x
		if s > 5000 {
			return i
		}
	}
	return len(weight)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumberOfApples(weight: number[]): number {
    weight.sort((a, b) => a - b);
    let s = 0;
    for (let i = 0; i < weight.length; ++i) {
        s += weight[i];
        if (s > 5000) {
            return i;
        }
    }
    return weight.length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一些苹果和一个可以承载 <code>5000</code> 单位重量的篮子。</p>

<p>给定一个整数数组 <code>weight</code> ，其中 <code>weight[i]</code> 是第 <code>i</code> 个苹果的重量，返回 <em>你可以放入篮子的最大苹果数量</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>weight = [100,200,150,1000]
<strong>输出：</strong>4
<strong>解释：</strong>所有 4 个苹果都可以装进去，因为它们的重量之和为 1450。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>weight = [900,950,800,1000,700,800]
<strong>输出：</strong>5
<strong>解释：</strong>6 个苹果的总重量超过了 5000，所以我们只能从中任选 5 个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= weight.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= weight[i] &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

要使得苹果数量最多，那么就要使得苹果的重量尽可能的小，因此我们可以对苹果的重量进行排序，然后从小到大依次放入篮子中，直到篮子的重量超过 $5000$ 为止，返回此时放入篮子的苹果数量。

如果所有的苹果都能放入篮子中，那么就返回苹果的数量。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是苹果的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        weight.sort()
        s = 0
        for i, x in enumerate(weight):
            s += x
            if s > 5000:
                return i
        return len(weight)
```

#### Java

```java
class Solution {
    public int maxNumberOfApples(int[] weight) {
        Arrays.sort(weight);
        int s = 0;
        for (int i = 0; i < weight.length; ++i) {
            s += weight[i];
            if (s > 5000) {
                return i;
            }
        }
        return weight.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int s = 0;
        for (int i = 0; i < weight.size(); ++i) {
            s += weight[i];
            if (s > 5000) {
                return i;
            }
        }
        return weight.size();
    }
};
```

#### Go

```go
func maxNumberOfApples(weight []int) int {
	sort.Ints(weight)
	s := 0
	for i, x := range weight {
		s += x
		if s > 5000 {
			return i
		}
	}
	return len(weight)
}
```

#### TypeScript

```ts
function maxNumberOfApples(weight: number[]): number {
    weight.sort((a, b) => a - b);
    let s = 0;
    for (let i = 0; i < weight.length; ++i) {
        s += weight[i];
        if (s > 5000) {
            return i;
        }
    }
    return weight.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1197. 进击的骑士 🔒](https://leetcode.cn/problems/minimum-knight-moves){#1197}

{{< tabs "1197" >}}

{{% tab "python" %}}
```python
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        def extend(m1, m2, q):
            for _ in range(len(q)):
                i, j = q.popleft()
                step = m1[(i, j)]
                for a, b in (
                    (-2, 1),
                    (-1, 2),
                    (1, 2),
                    (2, 1),
                    (2, -1),
                    (1, -2),
                    (-1, -2),
                    (-2, -1),
                ):
                    x, y = i + a, j + b
                    if (x, y) in m1:
                        continue
                    if (x, y) in m2:
                        return step + 1 + m2[(x, y)]
                    q.append((x, y))
                    m1[(x, y)] = step + 1
            return -1

        if (x, y) == (0, 0):
            return 0
        q1, q2 = deque([(0, 0)]), deque([(x, y)])
        m1, m2 = {(0, 0): 0}, {(x, y): 0}
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n = 700;

    public int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        x += 310;
        y += 310;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        m1.put(310 * n + 310, 0);
        m2.put(x * n + y, 0);
        Queue<int[]> q1 = new ArrayDeque<>();
        Queue<int[]> q2 = new ArrayDeque<>();
        q1.offer(new int[] {310, 310});
        q2.offer(new int[] {x, y});
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Queue<int[]> q) {
        int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = q.size(); k > 0; --k) {
            int[] p = q.poll();
            int step = m1.get(p[0] * n + p[1]);
            for (int[] dir : dirs) {
                int x = p[0] + dir[0];
                int y = p[1] + dir[1];
                if (m1.containsKey(x * n + y)) {
                    continue;
                }
                if (m2.containsKey(x * n + y)) {
                    return step + 1 + m2.get(x * n + y);
                }
                m1.put(x * n + y, step + 1);
                q.offer(new int[] {x, y});
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
typedef pair<int, int> PII;

class Solution {
public:
    int n = 700;

    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x += 310;
        y += 310;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[310 * n + 310] = 0;
        m2[x * n + y] = 0;
        queue<PII> q1;
        queue<PII> q2;
        q1.push({310, 310});
        q2.push({x, y});
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<PII>& q) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = q.size(); k > 0; --k) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            int step = m1[i * n + j];
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (m1.count(x * n + y)) continue;
                if (m2.count(x * n + y)) return step + 1 + m2[x * n + y];
                m1[x * n + y] = step + 1;
                q.push({x, y});
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minKnightMoves(x int, y int) int {
	if x == 0 && y == 0 {
		return 0
	}
	n := 700
	x, y = x+310, y+310
	q1, q2 := []int{310*700 + 310}, []int{x*n + y}
	m1, m2 := map[int]int{310*700 + 310: 0}, map[int]int{x*n + y: 0}
	dirs := [][]int{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}
	extend := func() int {
		for k := len(q1); k > 0; k-- {
			p := q1[0]
			q1 = q1[1:]
			i, j := p/n, p%n
			step := m1[i*n+j]
			for _, dir := range dirs {
				x, y := i+dir[0], j+dir[1]
				t := x*n + y
				if _, ok := m1[t]; ok {
					continue
				}
				if v, ok := m2[t]; ok {
					return step + 1 + v
				}
				m1[t] = step + 1
				q1 = append(q1, t)
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) <= len(q2) {
			q1, q2 = q2, q1
			m1, m2 = m2, m1
		}
		t := extend()
		if t != -1 {
			return t
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
use std::collections::VecDeque;

const DIR: [(i32, i32); 8] = [
    (-2, 1),
    (2, 1),
    (-1, 2),
    (1, 2),
    (2, -1),
    (-2, -1),
    (1, -2),
    (-1, -2),
];

impl Solution {
    #[allow(dead_code)]
    pub fn min_knight_moves(x: i32, y: i32) -> i32 {
        if x == 0 && y == 0 {
            return 0;
        }
        // Otherwise, let's shift <X, Y> from [-300, 300] -> [0, 600]
        let x = x + 300;
        let y = y + 300;
        let mut ret = -1;
        // Initialize the two hash map, used to track if a node has been visited
        let mut map_to: HashMap<i32, i32> = HashMap::new();
        let mut map_from: HashMap<i32, i32> = HashMap::new();
        // Input the original status
        map_to.insert(601 * 300 + 300, 0);
        map_from.insert(601 * x + y, 0);
        let mut q_to: VecDeque<(i32, i32)> = VecDeque::new();
        let mut q_from: VecDeque<(i32, i32)> = VecDeque::new();
        // Initialize the two queue
        q_to.push_back((300, 300));
        q_from.push_back((x, y));

        while !q_to.is_empty() && !q_from.is_empty() {
            let step = if q_to.len() < q_from.len() {
                Self::extend(&mut map_to, &mut map_from, &mut q_to)
            } else {
                Self::extend(&mut map_from, &mut map_to, &mut q_from)
            };
            if step != -1 {
                ret = step;
                break;
            }
        }

        ret
    }

    #[allow(dead_code)]
    fn extend(
        map_to: &mut HashMap<i32, i32>,
        map_from: &mut HashMap<i32, i32>,
        cur_q: &mut VecDeque<(i32, i32)>,
    ) -> i32 {
        let n = cur_q.len();
        for _ in 0..n {
            let (i, j) = cur_q.front().unwrap().clone();
            cur_q.pop_front();
            // The cur_step here must exist
            let cur_step = map_to.get(&(601 * i + j)).unwrap().clone();
            for (dx, dy) in DIR {
                let x = i + dx;
                let y = j + dy;
                // Check if this node has been visited
                if map_to.contains_key(&(601 * x + y)) {
                    // Just ignore this node
                    continue;
                }
                // Check if this node has been visited by the other side
                if map_from.contains_key(&(601 * x + y)) {
                    // We found the node
                    return (cur_step + 1 + map_from.get(&(601 * x + y)).unwrap().clone());
                }
                // Otherwise, update map_to and push the new node to queue
                map_to.insert(601 * x + y, cur_step + 1);
                cur_q.push_back((x, y));
            }
        }
        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个坐标可以从 <code>-infinity</code>&nbsp;延伸到&nbsp;<code>+infinity</code>&nbsp;的 <strong>无限大的</strong>&nbsp;棋盘上，你的 <strong>骑士&nbsp;</strong>驻扎在坐标为&nbsp;<code>[0, 0]</code>&nbsp;的方格里。</p>

<p>骑士的走法和中国象棋中的马相似，走 “日” 字：即先向左（或右）走 1 格，再向上（或下）走 2 格；或先向左（或右）走 2 格，再向上（或下）走 1 格。</p>

<p>每次移动，他都可以按图示八个方向之一前进。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1197.Minimum%20Knight%20Moves/images/knight.png" style="width: 250px; height: 250px;" /></p>

<p>返回 <em>骑士前去征服坐标为&nbsp;<code>[x, y]</code>&nbsp;的部落所需的最小移动次数</em> 。本题确保答案是一定存在的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 2, y = 1
<strong>输出：</strong>1
<strong>解释：</strong>[0, 0] → [2, 1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 5, y = 5
<strong>输出：</strong>4
<strong>解释：</strong>[0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-300 &lt;= x, y &lt;= 300</code></li>
	<li><code>0 &lt;= |x| + |y| &lt;= 300</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

BFS 最短路模型。本题搜索空间不大，可以直接使用朴素 BFS，以下题解中还提供了双向 BFS 的题解代码，仅供参考。

双向 BFS 是 BFS 常见的一个优化方法，主要实现思路如下：

1. 创建两个队列 q1, q2 分别用于“起点 -> 终点”、“终点 -> 起点”两个方向的搜索；
2. 创建两个哈希表 m1, m2 分别记录访问过的节点以及对应的扩展次数（步数）；
3. 每次搜索时，优先选择元素数量较少的队列进行搜索扩展，如果在扩展过程中，搜索到另一个方向已经访问过的节点，说明找到了最短路径；
4. 只要其中一个队列为空，说明当前方向的搜索已经进行不下去了，说明起点到终点不连通，无需继续搜索。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        q = deque([(0, 0)])
        ans = 0
        vis = {(0, 0)}
        dirs = ((-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1))
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if (i, j) == (x, y):
                    return ans
                for a, b in dirs:
                    c, d = i + a, j + b
                    if (c, d) not in vis:
                        vis.add((c, d))
                        q.append((c, d))
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int minKnightMoves(int x, int y) {
        x += 310;
        y += 310;
        int ans = 0;
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {310, 310});
        boolean[][] vis = new boolean[700][700];
        vis[310][310] = true;
        int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                if (p[0] == x && p[1] == y) {
                    return ans;
                }
                for (int[] dir : dirs) {
                    int c = p[0] + dir[0];
                    int d = p[1] + dir[1];
                    if (!vis[c][d]) {
                        vis[c][d] = true;
                        q.offer(new int[] {c, d});
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x += 310;
        y += 310;
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({310, 310});
        vector<vector<bool>> vis(700, vector<bool>(700));
        vis[310][310] = true;
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                auto p = q.front();
                q.pop();
                if (p.first == x && p.second == y) return ans;
                for (auto& dir : dirs) {
                    int c = p.first + dir[0], d = p.second + dir[1];
                    if (!vis[c][d]) {
                        vis[c][d] = true;
                        q.push({c, d});
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```

#### Go

```go
func minKnightMoves(x int, y int) int {
	x, y = x+310, y+310
	ans := 0
	q := [][]int{{310, 310}}
	vis := make([][]bool, 700)
	for i := range vis {
		vis[i] = make([]bool, 700)
	}
	dirs := [][]int{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			if p[0] == x && p[1] == y {
				return ans
			}
			for _, dir := range dirs {
				c, d := p[0]+dir[0], p[1]+dir[1]
				if !vis[c][d] {
					vis[c][d] = true
					q = append(q, []int{c, d})
				}
			}
		}
		ans++
	}
	return -1
}
```

#### Rust

```rust
use std::collections::VecDeque;

const DIR: [(i32, i32); 8] = [
    (-2, 1),
    (2, 1),
    (-1, 2),
    (1, 2),
    (2, -1),
    (-2, -1),
    (1, -2),
    (-1, -2),
];

impl Solution {
    #[allow(dead_code)]
    pub fn min_knight_moves(x: i32, y: i32) -> i32 {
        // The original x, y are from [-300, 300]
        // Let's shift them to [0, 600]
        let x: i32 = x + 300;
        let y: i32 = y + 300;
        let mut ret = -1;
        let mut vis: Vec<Vec<bool>> = vec![vec![false; 618]; 618];
        // <X, Y, Current Steps>
        let mut q: VecDeque<(i32, i32, i32)> = VecDeque::new();

        q.push_back((300, 300, 0));

        while !q.is_empty() {
            let (i, j, s) = q.front().unwrap().clone();
            q.pop_front();
            if i == x && j == y {
                ret = s;
                break;
            }
            Self::enqueue(&mut vis, &mut q, i, j, s);
        }

        ret
    }

    #[allow(dead_code)]
    fn enqueue(
        vis: &mut Vec<Vec<bool>>,
        q: &mut VecDeque<(i32, i32, i32)>,
        i: i32,
        j: i32,
        cur_step: i32,
    ) {
        let next_step = cur_step + 1;
        for (dx, dy) in DIR {
            let x = i + dx;
            let y = j + dy;
            if Self::check_bounds(x, y) || vis[x as usize][y as usize] {
                // This <X, Y> pair is either out of bound, or has been visited before
                // Just ignore this pair
                continue;
            }
            // Otherwise, add the pair to the queue
            // Also remember to update the vis vector
            vis[x as usize][y as usize] = true;
            q.push_back((x, y, next_step));
        }
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32) -> bool {
        i < 0 || i > 600 || j < 0 || j > 600
    }
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
    def minKnightMoves(self, x: int, y: int) -> int:
        def extend(m1, m2, q):
            for _ in range(len(q)):
                i, j = q.popleft()
                step = m1[(i, j)]
                for a, b in (
                    (-2, 1),
                    (-1, 2),
                    (1, 2),
                    (2, 1),
                    (2, -1),
                    (1, -2),
                    (-1, -2),
                    (-2, -1),
                ):
                    x, y = i + a, j + b
                    if (x, y) in m1:
                        continue
                    if (x, y) in m2:
                        return step + 1 + m2[(x, y)]
                    q.append((x, y))
                    m1[(x, y)] = step + 1
            return -1

        if (x, y) == (0, 0):
            return 0
        q1, q2 = deque([(0, 0)]), deque([(x, y)])
        m1, m2 = {(0, 0): 0}, {(x, y): 0}
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
```

#### Java

```java
class Solution {
    private int n = 700;

    public int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        x += 310;
        y += 310;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        m1.put(310 * n + 310, 0);
        m2.put(x * n + y, 0);
        Queue<int[]> q1 = new ArrayDeque<>();
        Queue<int[]> q2 = new ArrayDeque<>();
        q1.offer(new int[] {310, 310});
        q2.offer(new int[] {x, y});
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Queue<int[]> q) {
        int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = q.size(); k > 0; --k) {
            int[] p = q.poll();
            int step = m1.get(p[0] * n + p[1]);
            for (int[] dir : dirs) {
                int x = p[0] + dir[0];
                int y = p[1] + dir[1];
                if (m1.containsKey(x * n + y)) {
                    continue;
                }
                if (m2.containsKey(x * n + y)) {
                    return step + 1 + m2.get(x * n + y);
                }
                m1.put(x * n + y, step + 1);
                q.offer(new int[] {x, y});
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
typedef pair<int, int> PII;

class Solution {
public:
    int n = 700;

    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x += 310;
        y += 310;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[310 * n + 310] = 0;
        m2[x * n + y] = 0;
        queue<PII> q1;
        queue<PII> q2;
        q1.push({310, 310});
        q2.push({x, y});
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<PII>& q) {
        vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = q.size(); k > 0; --k) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            int step = m1[i * n + j];
            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (m1.count(x * n + y)) continue;
                if (m2.count(x * n + y)) return step + 1 + m2[x * n + y];
                m1[x * n + y] = step + 1;
                q.push({x, y});
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minKnightMoves(x int, y int) int {
	if x == 0 && y == 0 {
		return 0
	}
	n := 700
	x, y = x+310, y+310
	q1, q2 := []int{310*700 + 310}, []int{x*n + y}
	m1, m2 := map[int]int{310*700 + 310: 0}, map[int]int{x*n + y: 0}
	dirs := [][]int{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}
	extend := func() int {
		for k := len(q1); k > 0; k-- {
			p := q1[0]
			q1 = q1[1:]
			i, j := p/n, p%n
			step := m1[i*n+j]
			for _, dir := range dirs {
				x, y := i+dir[0], j+dir[1]
				t := x*n + y
				if _, ok := m1[t]; ok {
					continue
				}
				if v, ok := m2[t]; ok {
					return step + 1 + v
				}
				m1[t] = step + 1
				q1 = append(q1, t)
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) <= len(q2) {
			q1, q2 = q2, q1
			m1, m2 = m2, m1
		}
		t := extend()
		if t != -1 {
			return t
		}
	}
	return -1
}
```

#### Rust

```rust
use std::collections::HashMap;
use std::collections::VecDeque;

const DIR: [(i32, i32); 8] = [
    (-2, 1),
    (2, 1),
    (-1, 2),
    (1, 2),
    (2, -1),
    (-2, -1),
    (1, -2),
    (-1, -2),
];

impl Solution {
    #[allow(dead_code)]
    pub fn min_knight_moves(x: i32, y: i32) -> i32 {
        if x == 0 && y == 0 {
            return 0;
        }
        // Otherwise, let's shift <X, Y> from [-300, 300] -> [0, 600]
        let x = x + 300;
        let y = y + 300;
        let mut ret = -1;
        // Initialize the two hash map, used to track if a node has been visited
        let mut map_to: HashMap<i32, i32> = HashMap::new();
        let mut map_from: HashMap<i32, i32> = HashMap::new();
        // Input the original status
        map_to.insert(601 * 300 + 300, 0);
        map_from.insert(601 * x + y, 0);
        let mut q_to: VecDeque<(i32, i32)> = VecDeque::new();
        let mut q_from: VecDeque<(i32, i32)> = VecDeque::new();
        // Initialize the two queue
        q_to.push_back((300, 300));
        q_from.push_back((x, y));

        while !q_to.is_empty() && !q_from.is_empty() {
            let step = if q_to.len() < q_from.len() {
                Self::extend(&mut map_to, &mut map_from, &mut q_to)
            } else {
                Self::extend(&mut map_from, &mut map_to, &mut q_from)
            };
            if step != -1 {
                ret = step;
                break;
            }
        }

        ret
    }

    #[allow(dead_code)]
    fn extend(
        map_to: &mut HashMap<i32, i32>,
        map_from: &mut HashMap<i32, i32>,
        cur_q: &mut VecDeque<(i32, i32)>,
    ) -> i32 {
        let n = cur_q.len();
        for _ in 0..n {
            let (i, j) = cur_q.front().unwrap().clone();
            cur_q.pop_front();
            // The cur_step here must exist
            let cur_step = map_to.get(&(601 * i + j)).unwrap().clone();
            for (dx, dy) in DIR {
                let x = i + dx;
                let y = j + dy;
                // Check if this node has been visited
                if map_to.contains_key(&(601 * x + y)) {
                    // Just ignore this node
                    continue;
                }
                // Check if this node has been visited by the other side
                if map_from.contains_key(&(601 * x + y)) {
                    // We found the node
                    return (cur_step + 1 + map_from.get(&(601 * x + y)).unwrap().clone());
                }
                // Otherwise, update map_to and push the new node to queue
                map_to.insert(601 * x + y, cur_step + 1);
                cur_q.push_back((x, y));
            }
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1198. 找出所有行中最小公共元素 🔒](https://leetcode.cn/problems/find-smallest-common-element-in-all-rows){#1198}

{{< tabs "1198" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        cnt = Counter()
        for row in mat:
            for x in row:
                cnt[x] += 1
                if cnt[x] == len(mat):
                    return x
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestCommonElement(int[][] mat) {
        int[] cnt = new int[10001];
        for (var row : mat) {
            for (int x : row) {
                if (++cnt[x] == mat.length) {
                    return x;
                }
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int cnt[10001]{};
        for (auto& row : mat) {
            for (int x : row) {
                if (++cnt[x] == mat.size()) {
                    return x;
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestCommonElement(mat [][]int) int {
	cnt := [10001]int{}
	for _, row := range mat {
		for _, x := range row {
			cnt[x]++
			if cnt[x] == len(mat) {
				return x
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestCommonElement(mat: number[][]): number {
    const cnt: number[] = new Array(10001).fill(0);
    for (const row of mat) {
        for (const x of row) {
            if (++cnt[x] == mat.length) {
                return x;
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>mat</code>，其中每一行的元素均符合&nbsp;<strong>严格递增</strong> 。请返回 <em>所有行中的&nbsp;<strong>最小公共元素</strong>&nbsp;</em>。</p>

<p>如果矩阵中没有这样的公共元素，就请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
<strong>输出：</strong>5
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>mat = [[1,2,3],[2,3,4],[2,3,5]]
<strong>输出：</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i]</code>&nbsp;已按严格递增顺序排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用一个长度为 $10001$ 的数组 $cnt$ 统计每个数出现的次数。顺序遍历矩阵中的每个数，将其出现次数加一。当某个数的出现次数等于矩阵的行数时，说明该数在每一行都出现过，即为最小公共元素，返回该数即可。

若遍历结束后没有找到最小公共元素，则返回 $-1$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(10^4)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        cnt = Counter()
        for row in mat:
            for x in row:
                cnt[x] += 1
                if cnt[x] == len(mat):
                    return x
        return -1
```

#### Java

```java
class Solution {
    public int smallestCommonElement(int[][] mat) {
        int[] cnt = new int[10001];
        for (var row : mat) {
            for (int x : row) {
                if (++cnt[x] == mat.length) {
                    return x;
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int cnt[10001]{};
        for (auto& row : mat) {
            for (int x : row) {
                if (++cnt[x] == mat.size()) {
                    return x;
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func smallestCommonElement(mat [][]int) int {
	cnt := [10001]int{}
	for _, row := range mat {
		for _, x := range row {
			cnt[x]++
			if cnt[x] == len(mat) {
				return x
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function smallestCommonElement(mat: number[][]): number {
    const cnt: number[] = new Array(10001).fill(0);
    for (const row of mat) {
        for (const x of row) {
            if (++cnt[x] == mat.length) {
                return x;
            }
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1199. 建造街区的最短时间 🔒](https://leetcode.cn/problems/minimum-time-to-build-blocks){#1199}

{{< tabs "1199" >}}

{{% tab "python" %}}
```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapify(blocks)
        while len(blocks) > 1:
            heappop(blocks)
            heappush(blocks, heappop(blocks) + split)
        return blocks[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int x : blocks) {
            q.offer(x);
        }
        while (q.size() > 1) {
            q.poll();
            q.offer(q.poll() + split);
        }
        return q.poll();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int v : blocks) pq.push(v);
        while (pq.size() > 1) {
            pq.pop();
            int x = pq.top();
            pq.pop();
            pq.push(x + split);
        }
        return pq.top();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minBuildTime(blocks []int, split int) int {
	q := hp{}
	for _, v := range blocks {
		heap.Push(&q, v)
	}
	for q.Len() > 1 {
		heap.Pop(&q)
		heap.Push(&q, heap.Pop(&q).(int)+split)
	}
	return q.IntSlice[0]
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minBuildTime(blocks: number[], split: number): number {
    const pq = new MinPriorityQueue();
    for (const x of blocks) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        pq.dequeue()!;
        pq.enqueue(pq.dequeue()! + split);
    }
    return pq.dequeue()!;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_build_time(blocks: Vec<i32>, split: i32) -> i32 {
        let mut pq = BinaryHeap::new();

        for x in blocks {
            pq.push(Reverse(x));
        }

        while pq.len() > 1 {
            pq.pop();
            let new_element = pq.pop().unwrap().0 + split;
            pq.push(Reverse(new_element));
        }

        pq.pop().unwrap().0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是个城市规划工作者，手里负责管辖一系列的街区。在这个街区列表中&nbsp;<code>blocks[i] = t</code>&nbsp;意味着第 &nbsp;<code>i</code>&nbsp;个街区需要&nbsp;<code>t</code>&nbsp;个单位的时间来建造。</p>

<p>由于一个街区只能由一个工人来完成建造。</p>

<p>所以，一个工人要么需要再召唤一个工人（工人数增加 1）；要么建造完一个街区后回家。这两个决定都需要花费一定的时间。</p>

<p>一个工人再召唤一个工人所花费的时间由整数&nbsp;<code>split</code>&nbsp;给出。</p>

<p>注意：如果两个工人同时召唤别的工人，那么他们的行为是并行的，所以时间花费仍然是&nbsp;<code>split</code>。</p>

<p>最开始的时候只有&nbsp;<strong>一个&nbsp;</strong>工人，请你最后输出建造完所有街区所需要的最少时间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>blocks = [1], split = 1
<strong>输出：</strong>1
<strong>解释：</strong>我们使用 1 个工人在 1 个时间单位内来建完 1 个街区。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>blocks = [1,2], split = 5
<strong>输出：</strong>7
<strong>解释：</strong>我们用 5 个时间单位将这个工人分裂为 2 个工人，然后指派每个工人分别去建造街区，从而时间花费为 5 + max(1, 2) = 7
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>blocks = [1,2,3], split = 1
<strong>输出：</strong>4
<strong>解释：
</strong>将 1 个工人分裂为 2 个工人，然后指派第一个工人去建造最后一个街区，并将第二个工人分裂为 2 个工人。
然后，用这两个未分派的工人分别去建造前两个街区。
时间花费为 1 + max(3, 1 + max(1, 2)) = 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= blocks.length &lt;= 1000</code></li>
	<li><code>1 &lt;= blocks[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= split &lt;= 100</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

先考虑只有一个街区的情况，此时不需要分裂工人，直接让他去建造街区，时间花费为 $\textit{block}[0]$。

如果有两个街区，此时需要把工人分裂为两个，然后让他们分别去建造街区，时间花费为 $\textit{split} + \max(\textit{block}[0], \textit{block}[1])$。

如果有超过两个街区，此时每一步都需要考虑将几个工人进行分裂，正向思维不好处理。

我们不妨采用逆向思维，不分裂工人，而是将街区进行合并。我们选取任意两个街区 $i$, $j$ 进行合并，建造一个新的街区的时间为 $\textit{split} + \max(\textit{block}[i], \textit{block}[j])$。

为了让耗时长的街区尽可能少参与到合并中，我们可以每次贪心地选取耗时最小的两个街区进行合并。因此，我们可以维护一个小根堆，每次取出最小的两个街区进行合并，直到只剩下一个街区。最后剩下的这个街区的建造时间就是答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为街区的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapify(blocks)
        while len(blocks) > 1:
            heappop(blocks)
            heappush(blocks, heappop(blocks) + split)
        return blocks[0]
```

#### Java

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int x : blocks) {
            q.offer(x);
        }
        while (q.size() > 1) {
            q.poll();
            q.offer(q.poll() + split);
        }
        return q.poll();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int v : blocks) pq.push(v);
        while (pq.size() > 1) {
            pq.pop();
            int x = pq.top();
            pq.pop();
            pq.push(x + split);
        }
        return pq.top();
    }
};
```

#### Go

```go
func minBuildTime(blocks []int, split int) int {
	q := hp{}
	for _, v := range blocks {
		heap.Push(&q, v)
	}
	for q.Len() > 1 {
		heap.Pop(&q)
		heap.Push(&q, heap.Pop(&q).(int)+split)
	}
	return q.IntSlice[0]
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function minBuildTime(blocks: number[], split: number): number {
    const pq = new MinPriorityQueue();
    for (const x of blocks) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        pq.dequeue()!;
        pq.enqueue(pq.dequeue()! + split);
    }
    return pq.dequeue()!;
}
```

#### Rust

```rust
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_build_time(blocks: Vec<i32>, split: i32) -> i32 {
        let mut pq = BinaryHeap::new();

        for x in blocks {
            pq.push(Reverse(x));
        }

        while pq.len() > 1 {
            pq.pop();
            let new_element = pq.pop().unwrap().0 + split;
            pq.push(Reverse(new_element));
        }

        pq.pop().unwrap().0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
