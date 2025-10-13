---
title: "1370_上升下降字符串"
date: 2025-10-08T18:37:12+08:00
weight: 8
tags: [二叉搜索树, 二叉树, 位运算, 前缀和, 动态规划, 哈希表, 图, 字符串, 广度优先搜索, 数据库, 数组, 树, 深度优先搜索, 计数]
---

{{< markmap >}}
### [1370_上升下降字符串](#1370)
#### [哈希表](#1370)
#### [字符串](#1370)
#### [计数](#1370)
### [1371_每个元音包含偶数次的最长子字符串](#1371)
#### [位运算](#1371)
#### [哈希表](#1371)
#### [字符串](#1371)
#### [前缀和](#1371)
### [1372_二叉树中的最长交错路径](#1372)
#### [树](#1372)
#### [深度优先搜索](#1372)
#### [动态规划](#1372)
#### [二叉树](#1372)
### [1373_二叉搜索子树的最大键值和](#1373)
#### [树](#1373)
#### [深度优先搜索](#1373)
#### [二叉搜索树](#1373)
#### [动态规划](#1373)
#### [二叉树](#1373)
### [1374_生成每种字符都是奇数个的字符串](#1374)
#### [字符串](#1374)
### [1375_二进制字符串前缀一致的次数](#1375)
#### [数组](#1375)
### [1376_通知所有员工所需的时间](#1376)
#### [树](#1376)
#### [深度优先搜索](#1376)
#### [广度优先搜索](#1376)
### [1377_T 秒后青蛙的位置](#1377)
#### [树](#1377)
#### [深度优先搜索](#1377)
#### [广度优先搜索](#1377)
#### [图](#1377)
### [1378_使用唯一标识码替换员工ID](#1378)
#### [数据库](#1378)
### [1379_找出克隆二叉树中的相同节点](#1379)
#### [树](#1379)
#### [深度优先搜索](#1379)
#### [广度优先搜索](#1379)
#### [二叉树](#1379)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1370_上升下降字符串
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1371_每个元音包含偶数次的最长子字符串
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 前缀和
---
### 1372_二叉树中的最长交错路径
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 二叉树
---
### 1373_二叉搜索子树的最大键值和
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 动态规划
___
#### 二叉树
---
### 1374_生成每种字符都是奇数个的字符串
___
#### 字符串
---
### 1375_二进制字符串前缀一致的次数
___
#### 数组
---
### 1376_通知所有员工所需的时间
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
---
### 1377_T 秒后青蛙的位置
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 1378_使用唯一标识码替换员工ID
___
#### 数据库
---
### 1379_找出克隆二叉树中的相同节点
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 哈希表 |
| 图 | 字符串 | 广度优先搜索 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 | 计数 |  |

# [1370. 上升下降字符串](https://leetcode.cn/problems/increasing-decreasing-string){#1370}

{{< tabs "1370" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortString(self, s: str) -> str:
        cnt = Counter(s)
        cs = ascii_lowercase + ascii_lowercase[::-1]
        ans = []
        while len(ans) < len(s):
            for c in cs:
                if cnt[c]:
                    ans.append(c)
                    cnt[c] -= 1
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String sortString(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt[s.charAt(i) - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        while (sb.length() < n) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i));
                    --cnt[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i));
                    --cnt[i];
                }
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
    string sortString(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        string ans;
        while (ans.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    ans += i + 'a';
                    --cnt[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i]) {
                    ans += i + 'a';
                    --cnt[i];
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
func sortString(s string) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	n := len(s)
	ans := make([]byte, 0, n)
	for len(ans) < n {
		for i := 0; i < 26; i++ {
			if cnt[i] > 0 {
				ans = append(ans, byte(i)+'a')
				cnt[i]--
			}
		}
		for i := 25; i >= 0; i-- {
			if cnt[i] > 0 {
				ans = append(ans, byte(i)+'a')
				cnt[i]--
			}
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortString(s: string): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const ans: string[] = [];
    while (ans.length < s.length) {
        for (let i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
        for (let i = 25; i >= 0; --i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
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
var sortString = function (s) {
    const cnt = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const ans = [];
    while (ans.length < s.length) {
        for (let i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
        for (let i = 25; i >= 0; --i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你根据下面的算法重新构造字符串：</p>

<ol>
	<li>从 <code>s</code>&nbsp;中选出 <strong>最小</strong>&nbsp;的字符，将它 <strong>接在</strong>&nbsp;结果字符串的后面。</li>
	<li>从 <code>s</code> 剩余字符中选出比上一个添加字符更大的 <strong>最小</strong> 字符，将它 <strong>接在</strong>&nbsp;结果字符串后面。</li>
	<li>重复步骤 2 ，直到你没法从 <code>s</code>&nbsp;中选择字符。</li>
	<li>从 <code>s</code>&nbsp;中选出 <strong>最大</strong>&nbsp;的字符，将它 <strong>接在</strong>&nbsp;结果字符串的后面。</li>
	<li>从 <code>s</code> 剩余字符中选出比上一个添加字符更小的 <strong>最大</strong>&nbsp;字符，将它 <strong>接在</strong>&nbsp;结果字符串后面。</li>
	<li>重复步骤 5&nbsp;，直到你没法从 <code>s</code>&nbsp;中选择字符。</li>
	<li>重复步骤 1 到 6 ，直到 <code>s</code>&nbsp;中所有字符都已经被选过。</li>
</ol>

<p>在任何一步中，如果最小或者最大字符不止一个&nbsp;，你可以选择其中任意一个，并将其添加到结果字符串。</p>

<p>请你返回将&nbsp;<code>s</code>&nbsp;中字符重新排序后的 <strong>结果字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaabbbbcccc"
<strong>输出：</strong>"abccbaabccba"
<strong>解释：</strong>第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "rat"
<strong>输出：</strong>"art"
<strong>解释：</strong>单词 "rat" 在上述算法重排序以后变成 "art"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 模拟

我们先用一个哈希表或者一个长度为 $26$ 的数组 $cnt$ 统计字符串 $s$ 中每个字符出现的次数。

然后，我们枚举字母 $[a,...,z]$，对于当前枚举到的字母 $c$，如果 $cnt[c] \gt 0$，我们就将字母 $c$ 接在答案字符串的末尾，并将 $cnt[c]$ 减一。我们重复这一步骤，直到 $cnt[c]=0$。随后我们逆序枚举字母 $[z,...,a]$，执行类似的操作。如果答案字符串的长度等于 $s$ 的长度，那么我们就完成了所有的拼接操作。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度，而 $\Sigma$ 是字符集，本题中字符集为所有小写字母，因此 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortString(self, s: str) -> str:
        cnt = Counter(s)
        cs = ascii_lowercase + ascii_lowercase[::-1]
        ans = []
        while len(ans) < len(s):
            for c in cs:
                if cnt[c]:
                    ans.append(c)
                    cnt[c] -= 1
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String sortString(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt[s.charAt(i) - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        while (sb.length() < n) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i));
                    --cnt[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i] > 0) {
                    sb.append((char) ('a' + i));
                    --cnt[i];
                }
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
    string sortString(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        string ans;
        while (ans.size() < s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    ans += i + 'a';
                    --cnt[i];
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i]) {
                    ans += i + 'a';
                    --cnt[i];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sortString(s string) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	n := len(s)
	ans := make([]byte, 0, n)
	for len(ans) < n {
		for i := 0; i < 26; i++ {
			if cnt[i] > 0 {
				ans = append(ans, byte(i)+'a')
				cnt[i]--
			}
		}
		for i := 25; i >= 0; i-- {
			if cnt[i] > 0 {
				ans = append(ans, byte(i)+'a')
				cnt[i]--
			}
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function sortString(s: string): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const ans: string[] = [];
    while (ans.length < s.length) {
        for (let i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
        for (let i = 25; i >= 0; --i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
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
var sortString = function (s) {
    const cnt = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    const ans = [];
    while (ans.length < s.length) {
        for (let i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
        for (let i = 25; i >= 0; --i) {
            if (cnt[i]) {
                ans.push(String.fromCharCode(i + 'a'.charCodeAt(0)));
                --cnt[i];
            }
        }
    }
    return ans.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1371. 每个元音包含偶数次的最长子字符串](https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts){#1371}

{{< tabs "1371" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        d = {0: -1}
        ans = mask = 0
        for i, c in enumerate(s):
            if c in "aeiou":
                mask ^= 1 << (ord(c) - ord("a"))
            if mask in d:
                j = d[mask]
                ans = max(ans, i - j)
            else:
                d[mask] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheLongestSubstring(String s) {
        String vowels = "aeiou";
        int[] d = new int[32];
        Arrays.fill(d, 1 << 29);
        d[0] = 0;
        int ans = 0, mask = 0;
        for (int i = 1; i <= s.length(); ++i) {
            char c = s.charAt(i - 1);
            for (int j = 0; j < 5; ++j) {
                if (c == vowels.charAt(j)) {
                    mask ^= 1 << j;
                    break;
                }
            }
            ans = Math.max(ans, i - d[mask]);
            d[mask] = Math.min(d[mask], i);
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
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        vector<int> d(32, INT_MAX);
        d[0] = 0;
        int ans = 0, mask = 0;
        for (int i = 1; i <= s.length(); ++i) {
            char c = s[i - 1];
            for (int j = 0; j < 5; ++j) {
                if (c == vowels[j]) {
                    mask ^= 1 << j;
                    break;
                }
            }
            ans = max(ans, i - d[mask]);
            d[mask] = min(d[mask], i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheLongestSubstring(s string) (ans int) {
    vowels := "aeiou"
    d := [32]int{}
    for i := range d {
        d[i] = 1 << 29
    }
    d[0] = 0
    mask := 0
    for i := 1; i <= len(s); i++ {
        c := s[i-1]
        for j := 0; j < 5; j++ {
            if c == vowels[j] {
                mask ^= 1 << j
                break
            }
        }
        ans = max(ans, i-d[mask])
        d[mask] = min(d[mask], i)
    }
    return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheLongestSubstring(s: string): number {
    const vowels = 'aeiou';
    const d: number[] = Array(32).fill(1 << 29);
    d[0] = 0;
    let [ans, mask] = [0, 0];
    for (let i = 1; i <= s.length; i++) {
        const c = s[i - 1];
        for (let j = 0; j < 5; j++) {
            if (c === vowels[j]) {
                mask ^= 1 << j;
                break;
            }
        }
        ans = Math.max(ans, i - d[mask]);
        d[mask] = Math.min(d[mask], i);
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即&nbsp;&#39;a&#39;，&#39;e&#39;，&#39;i&#39;，&#39;o&#39;，&#39;u&#39; ，在子字符串中都恰好出现了偶数次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;eleetminicoworoep&quot;
<strong>输出：</strong>13
<strong>解释：</strong>最长子字符串是 &quot;leetminicowor&quot; ，它包含 <strong>e，i，o</strong>&nbsp;各 2 个，以及 0 个 <strong>a</strong>，<strong>u </strong>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;leetcodeisgreat&quot;
<strong>输出：</strong>5
<strong>解释：</strong>最长子字符串是 &quot;leetc&quot; ，其中包含 2 个 <strong>e</strong> 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;bcbcbc&quot;
<strong>输出：</strong>6
<strong>解释：</strong>这个示例中，字符串 &quot;bcbcbc&quot; 本身就是最长的，因为所有的元音 <strong>a，</strong><strong>e，</strong><strong>i，</strong><strong>o，</strong><strong>u</strong> 都出现了 0 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 x 10^5</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀异或 + 数组或哈希表

根据题目描述，如果我们用一个数字表示字符串 $\textit{s}$ 的某个前缀中每个元音字母出现的次数的奇偶性，那么当两个前缀的这个数字相同时，这两个前缀的交集就是一个符合条件的子字符串。

我们可以用一个二进制数的低五位分别表示五个元音字母的奇偶性，其中第 $i$ 位为 $1$ 表示该元音字母在子字符串中出现了奇数次，为 $0$ 表示该元音字母在子字符串中出现了偶数次。

我们用 $\textit{mask}$ 表示这个二进制数，用一个数组或哈希表 $\textit{d}$ 记录每个 $\textit{mask}$ 第一次出现的位置。初始时，我们将 $\textit{d}[0] = -1$，表示空字符串的开始位置为 $-1$。

遍历字符串 $\textit{s}$，如果遇到元音字母，就将 $\textit{mask}$ 的对应位取反。接下来，我们判断 $\textit{mask}$ 是否在之前出现过，如果出现过，那么我们就找到了一个符合条件的子字符串，其长度为当前位置减去 $\textit{mask}$ 上一次出现的位置。否则，我们将 $\textit{mask}$ 的当前位置存入 $\textit{d}$。

遍历结束后，我们就找到了最长的符合条件的子字符串。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        d = {0: -1}
        ans = mask = 0
        for i, c in enumerate(s):
            if c in "aeiou":
                mask ^= 1 << (ord(c) - ord("a"))
            if mask in d:
                j = d[mask]
                ans = max(ans, i - j)
            else:
                d[mask] = i
        return ans
```

#### Java

```java
class Solution {
    public int findTheLongestSubstring(String s) {
        String vowels = "aeiou";
        int[] d = new int[32];
        Arrays.fill(d, 1 << 29);
        d[0] = 0;
        int ans = 0, mask = 0;
        for (int i = 1; i <= s.length(); ++i) {
            char c = s.charAt(i - 1);
            for (int j = 0; j < 5; ++j) {
                if (c == vowels.charAt(j)) {
                    mask ^= 1 << j;
                    break;
                }
            }
            ans = Math.max(ans, i - d[mask]);
            d[mask] = Math.min(d[mask], i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        vector<int> d(32, INT_MAX);
        d[0] = 0;
        int ans = 0, mask = 0;
        for (int i = 1; i <= s.length(); ++i) {
            char c = s[i - 1];
            for (int j = 0; j < 5; ++j) {
                if (c == vowels[j]) {
                    mask ^= 1 << j;
                    break;
                }
            }
            ans = max(ans, i - d[mask]);
            d[mask] = min(d[mask], i);
        }
        return ans;
    }
};
```

#### Go

```go
func findTheLongestSubstring(s string) (ans int) {
    vowels := "aeiou"
    d := [32]int{}
    for i := range d {
        d[i] = 1 << 29
    }
    d[0] = 0
    mask := 0
    for i := 1; i <= len(s); i++ {
        c := s[i-1]
        for j := 0; j < 5; j++ {
            if c == vowels[j] {
                mask ^= 1 << j
                break
            }
        }
        ans = max(ans, i-d[mask])
        d[mask] = min(d[mask], i)
    }
    return
}
```

#### TypeScript

```ts
function findTheLongestSubstring(s: string): number {
    const vowels = 'aeiou';
    const d: number[] = Array(32).fill(1 << 29);
    d[0] = 0;
    let [ans, mask] = [0, 0];
    for (let i = 1; i <= s.length; i++) {
        const c = s[i - 1];
        for (let j = 0; j < 5; j++) {
            if (c === vowels[j]) {
                mask ^= 1 << j;
                break;
            }
        }
        ans = Math.max(ans, i - d[mask]);
        d[mask] = Math.min(d[mask], i);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1372. 二叉树中的最长交错路径](https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree){#1372}

{{< tabs "1372" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        def dfs(root, l, r):
            if root is None:
                return
            nonlocal ans
            ans = max(ans, l, r)
            dfs(root.left, r + 1, 0)
            dfs(root.right, 0, l + 1)

        ans = 0
        dfs(root, 0, 0)
        return ans
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
    private int ans;

    public int longestZigZag(TreeNode root) {
        dfs(root, 0, 0);
        return ans;
    }

    private void dfs(TreeNode root, int l, int r) {
        if (root == null) {
            return;
        }
        ans = Math.max(ans, Math.max(l, r));
        dfs(root.left, r + 1, 0);
        dfs(root.right, 0, l + 1);
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
    int ans = 0;

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }

    void dfs(TreeNode* root, int l, int r) {
        if (!root) return;
        ans = max(ans, max(l, r));
        dfs(root->left, r + 1, 0);
        dfs(root->right, 0, l + 1);
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
func longestZigZag(root *TreeNode) int {
	ans := 0
	var dfs func(root *TreeNode, l, r int)
	dfs = func(root *TreeNode, l, r int) {
		if root == nil {
			return
		}
		ans = max(ans, max(l, r))
		dfs(root.Left, r+1, 0)
		dfs(root.Right, 0, l+1)
	}
	dfs(root, 0, 0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵以&nbsp;<code>root</code>&nbsp;为根的二叉树，二叉树中的交错路径定义如下：</p>

<ul>
	<li>选择二叉树中 <strong>任意</strong>&nbsp;节点和一个方向（左或者右）。</li>
	<li>如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。</li>
	<li>改变前进方向：左变右或者右变左。</li>
	<li>重复第二步和第三步，直到你在树中无法继续移动。</li>
</ul>

<p>交错路径的长度定义为：<strong>访问过的节点数目 - 1</strong>（单个节点的路径长度为 0 ）。</p>

<p>请你返回给定树中最长 <strong>交错路径</strong>&nbsp;的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1372.Longest%20ZigZag%20Path%20in%20a%20Binary%20Tree/images/sample_1_1702.png" style="height: 283px; width: 151px;"></strong></p>

<pre><strong>输入：</strong>root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
<strong>输出：</strong>3
<strong>解释：</strong>蓝色节点为树中最长交错路径（右 -&gt; 左 -&gt; 右）。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1372.Longest%20ZigZag%20Path%20in%20a%20Binary%20Tree/images/sample_2_1702.png" style="height: 253px; width: 120px;"></strong></p>

<pre><strong>输入：</strong>root = [1,1,1,null,1,null,null,1,1,null,1]
<strong>输出：</strong>4
<strong>解释：</strong>蓝色节点为树中最长交错路径（左 -&gt; 右 -&gt; 左 -&gt; 右）。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树最多有&nbsp;<code>50000</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[1, 100]</code> 之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

时间复杂度 $O(n)$，其中 $n$ 是树中节点的个数。

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
    def longestZigZag(self, root: TreeNode) -> int:
        def dfs(root, l, r):
            if root is None:
                return
            nonlocal ans
            ans = max(ans, l, r)
            dfs(root.left, r + 1, 0)
            dfs(root.right, 0, l + 1)

        ans = 0
        dfs(root, 0, 0)
        return ans
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
    private int ans;

    public int longestZigZag(TreeNode root) {
        dfs(root, 0, 0);
        return ans;
    }

    private void dfs(TreeNode root, int l, int r) {
        if (root == null) {
            return;
        }
        ans = Math.max(ans, Math.max(l, r));
        dfs(root.left, r + 1, 0);
        dfs(root.right, 0, l + 1);
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
    int ans = 0;

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }

    void dfs(TreeNode* root, int l, int r) {
        if (!root) return;
        ans = max(ans, max(l, r));
        dfs(root->left, r + 1, 0);
        dfs(root->right, 0, l + 1);
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
func longestZigZag(root *TreeNode) int {
	ans := 0
	var dfs func(root *TreeNode, l, r int)
	dfs = func(root *TreeNode, l, r int) {
		if root == nil {
			return
		}
		ans = max(ans, max(l, r))
		dfs(root.Left, r+1, 0)
		dfs(root.Right, 0, l+1)
	}
	dfs(root, 0, 0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1373. 二叉搜索子树的最大键值和](https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree){#1373}

{{< tabs "1373" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> tuple:
            if root is None:
                return 1, inf, -inf, 0
            lbst, lmi, lmx, ls = dfs(root.left)
            rbst, rmi, rmx, rs = dfs(root.right)
            if lbst and rbst and lmx < root.val < rmi:
                nonlocal ans
                s = ls + rs + root.val
                ans = max(ans, s)
                return 1, min(lmi, root.val), max(rmx, root.val), s
            return 0, 0, 0, 0

        ans = 0
        dfs(root)
        return ans
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
    private int ans;
    private final int inf = 1 << 30;

    public int maxSumBST(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1, inf, -inf, 0};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int v = root.val;
        if (l[0] == 1 && r[0] == 1 && l[2] < v && r[1] > v) {
            int s = v + l[3] + r[3];
            ans = Math.max(ans, s);
            return new int[] {1, Math.min(l[1], v), Math.max(r[2], v), s};
        }
        return new int[4];
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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        const int inf = 1 << 30;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> array<int, 4> {
            if (!root) {
                return {1, inf, -inf, 0};
            }
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            int v = root->val;
            if (l[0] && r[0] && l[2] < v && v < r[1]) {
                int s = l[3] + r[3] + v;
                ans = max(ans, s);
                return {1, min(l[1], v), max(r[2], v), s};
            }
            return {0};
        };
        dfs(root);
        return ans;
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
func maxSumBST(root *TreeNode) (ans int) {
	const inf = 1 << 30
	var dfs func(root *TreeNode) [4]int
	dfs = func(root *TreeNode) [4]int {
		if root == nil {
			return [4]int{1, inf, -inf, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if l[0] == 1 && r[0] == 1 && l[2] < root.Val && root.Val < r[1] {
			s := l[3] + r[3] + root.Val
			ans = max(ans, s)
			return [4]int{1, min(l[1], root.Val), max(r[2], root.Val), s}
		}
		return [4]int{}
	}
	dfs(root)
	return
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

function maxSumBST(root: TreeNode | null): number {
    const inf = 1 << 30;
    let ans = 0;
    const dfs = (root: TreeNode | null): [boolean, number, number, number] => {
        if (!root) {
            return [true, inf, -inf, 0];
        }
        const [lbst, lmi, lmx, ls] = dfs(root.left);
        const [rbst, rmi, rmx, rs] = dfs(root.right);
        if (lbst && rbst && lmx < root.val && root.val < rmi) {
            const s = ls + rs + root.val;
            ans = Math.max(ans, s);
            return [true, Math.min(lmi, root.val), Math.max(rmx, root.val), s];
        }
        return [false, 0, 0, 0];
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵以 <code>root</code> 为根的 <strong>二叉树</strong> ，请你返回 <strong>任意</strong> 二叉搜索子树的最大键值和。</p>

<p>二叉搜索树的定义如下：</p>

<ul>
	<li>任意节点的左子树中的键值都 <strong>小于</strong> 此节点的键值。</li>
	<li>任意节点的右子树中的键值都 <strong>大于</strong> 此节点的键值。</li>
	<li>任意节点的左子树和右子树都是二叉搜索树。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1373.Maximum%20Sum%20BST%20in%20Binary%20Tree/images/sample_1_1709.png" style="height: 250px; width: 320px;" /></p>

<pre>
<strong>输入：</strong>root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
<strong>输出：</strong>20
<strong>解释：</strong>键值为 3 的子树是和最大的二叉搜索树。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1373.Maximum%20Sum%20BST%20in%20Binary%20Tree/images/sample_2_1709.png" style="height: 180px; width: 134px;" /></p>

<pre>
<strong>输入：</strong>root = [4,3,null,1,2]
<strong>输出：</strong>2
<strong>解释：</strong>键值为 2 的单节点子树是和最大的二叉搜索树。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [-4,-2,-5]
<strong>输出：</strong>0
<strong>解释：</strong>所有节点键值都为负数，和最大的二叉搜索树为空。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>6
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>root = [5,4,8,3,null,6,3]
<strong>输出：</strong>7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树有 <code>1</code> 到 <code>40000</code> 个节点。</li>
	<li>每个节点的键值在 <code>[-4 * 10^4 , 4 * 10^4]</code> 之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

判断一棵树是否是二叉搜索树，需要满足以下四个条件：

-   左子树是二叉搜索树；
-   右子树是二叉搜索树；
-   左子树的最大值小于根节点的值；
-   右子树的最小值大于根节点的值。

因此，我们设计一个函数 $dfs(root)$，函数的返回值是一个四元组 $(bst, mi, mx, s)$，其中：

-   数字 $bst$ 表示以 $root$ 为根的树是否是二叉搜索树。如果是二叉搜索树，则 $bst = 1$；否则 $bst = 0$；
-   数字 $mi$ 表示以 $root$ 为根的树的最小值；
-   数字 $mx$ 表示以 $root$ 为根的树的最大值；
-   数字 $s$ 表示以 $root$ 为根的树的所有节点的和。

函数 $dfs(root)$ 的执行逻辑如下：

如果 $root$ 为空节点，则返回 $(1, +\infty, -\infty, 0)$，表示空树是二叉搜索树，最小值和最大值分别为正无穷和负无穷，节点和为 $0$。

否则，递归计算 $root$ 的左子树和右子树，分别得到 $(lbst, lmi, lmx, ls)$ 和 $(rbst, rmi, rmx, rs)$，然后判断 $root$ 节点是否满足二叉搜索树的条件。

如果满足 $lbst = 1$ 且 $rbst = 1$ 且 $lmx \lt root.val \lt rmi$，则以 $root$ 为根的树是二叉搜索树，节点和 $s= ls + rs + root.val$。我们更新答案 $ans = \max(ans, s)$，并返回 $(1, \min(lmi, root.val), \max(rmx, root.val), s)$。

否则，以 $root$ 为根的树不是二叉搜索树，我们返回 $(0, 0, 0, 0)$。

我们在主函数中调用 $dfs(root)$，执行完毕后，答案即为 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> tuple:
            if root is None:
                return 1, inf, -inf, 0
            lbst, lmi, lmx, ls = dfs(root.left)
            rbst, rmi, rmx, rs = dfs(root.right)
            if lbst and rbst and lmx < root.val < rmi:
                nonlocal ans
                s = ls + rs + root.val
                ans = max(ans, s)
                return 1, min(lmi, root.val), max(rmx, root.val), s
            return 0, 0, 0, 0

        ans = 0
        dfs(root)
        return ans
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
    private int ans;
    private final int inf = 1 << 30;

    public int maxSumBST(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1, inf, -inf, 0};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int v = root.val;
        if (l[0] == 1 && r[0] == 1 && l[2] < v && r[1] > v) {
            int s = v + l[3] + r[3];
            ans = Math.max(ans, s);
            return new int[] {1, Math.min(l[1], v), Math.max(r[2], v), s};
        }
        return new int[4];
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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        const int inf = 1 << 30;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> array<int, 4> {
            if (!root) {
                return {1, inf, -inf, 0};
            }
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            int v = root->val;
            if (l[0] && r[0] && l[2] < v && v < r[1]) {
                int s = l[3] + r[3] + v;
                ans = max(ans, s);
                return {1, min(l[1], v), max(r[2], v), s};
            }
            return {0};
        };
        dfs(root);
        return ans;
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
func maxSumBST(root *TreeNode) (ans int) {
	const inf = 1 << 30
	var dfs func(root *TreeNode) [4]int
	dfs = func(root *TreeNode) [4]int {
		if root == nil {
			return [4]int{1, inf, -inf, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if l[0] == 1 && r[0] == 1 && l[2] < root.Val && root.Val < r[1] {
			s := l[3] + r[3] + root.Val
			ans = max(ans, s)
			return [4]int{1, min(l[1], root.Val), max(r[2], root.Val), s}
		}
		return [4]int{}
	}
	dfs(root)
	return
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

function maxSumBST(root: TreeNode | null): number {
    const inf = 1 << 30;
    let ans = 0;
    const dfs = (root: TreeNode | null): [boolean, number, number, number] => {
        if (!root) {
            return [true, inf, -inf, 0];
        }
        const [lbst, lmi, lmx, ls] = dfs(root.left);
        const [rbst, rmi, rmx, rs] = dfs(root.right);
        if (lbst && rbst && lmx < root.val && root.val < rmi) {
            const s = ls + rs + root.val;
            ans = Math.max(ans, s);
            return [true, Math.min(lmi, root.val), Math.max(rmx, root.val), s];
        }
        return [false, 0, 0, 0];
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1374. 生成每种字符都是奇数个的字符串](https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts){#1374}

{{< tabs "1374" >}}

{{% tab "python" %}}
```python
class Solution:
    def generateTheString(self, n: int) -> str:
        return 'a' * n if n & 1 else 'a' * (n - 1) + 'b'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String generateTheString(int n) {
        return (n % 2 == 1) ? "a".repeat(n) : "a".repeat(n - 1) + "b";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string generateTheString(int n) {
        string ans(n, 'a');
        if (n % 2 == 0) {
            ans[0] = 'b';
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generateTheString(n int) string {
	ans := strings.Repeat("a", n-1)
	if n%2 == 0 {
		ans += "b"
	} else {
		ans += "a"
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generateTheString(n: number): string {
    const ans = Array(n).fill('a');
    if (n % 2 === 0) {
        ans[0] = 'b';
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，请你返回一个含<em> <code>n</code> </em>个字符的字符串，其中每种字符在该字符串中都恰好出现 <strong>奇数次</strong> <em><strong>。</strong></em></p>

<p>返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>&quot;pppz&quot;
<strong>解释：</strong>&quot;pppz&quot; 是一个满足题目要求的字符串，因为 &#39;p&#39; 出现 3 次，且 &#39;z&#39; 出现 1 次。当然，还有很多其他字符串也满足题目要求，比如：&quot;ohhh&quot; 和 &quot;love&quot;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>&quot;xy&quot;
<strong>解释：</strong>&quot;xy&quot; 是一个满足题目要求的字符串，因为 &#39;x&#39; 和 &#39;y&#39; 各出现 1 次。当然，还有很多其他字符串也满足题目要求，比如：&quot;ag&quot; 和 &quot;ur&quot;。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>&quot;holasss&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：构造

如果 $n$ 为奇数，那么直接构造 $n$ 个 `'a'` 即可。

如果 $n$ 为偶数，那么构造 $n-1$ 个 `'a'` 和 $1$ 个 `'b'` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateTheString(self, n: int) -> str:
        return 'a' * n if n & 1 else 'a' * (n - 1) + 'b'
```

#### Java

```java
class Solution {
    public String generateTheString(int n) {
        return (n % 2 == 1) ? "a".repeat(n) : "a".repeat(n - 1) + "b";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string generateTheString(int n) {
        string ans(n, 'a');
        if (n % 2 == 0) {
            ans[0] = 'b';
        }
        return ans;
    }
};
```

#### Go

```go
func generateTheString(n int) string {
	ans := strings.Repeat("a", n-1)
	if n%2 == 0 {
		ans += "b"
	} else {
		ans += "a"
	}
	return ans
}
```

#### TypeScript

```ts
function generateTheString(n: number): string {
    const ans = Array(n).fill('a');
    if (n % 2 === 0) {
        ans[0] = 'b';
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1375. 二进制字符串前缀一致的次数](https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned){#1375}

{{< tabs "1375" >}}

{{% tab "python" %}}
```python
class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        ans = mx = 0
        for i, x in enumerate(flips, 1):
            mx = max(mx, x)
            ans += mx == i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numTimesAllBlue(int[] flips) {
        int ans = 0, mx = 0;
        for (int i = 1; i <= flips.length; ++i) {
            mx = Math.max(mx, flips[i - 1]);
            if (mx == i) {
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
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, mx = 0;
        for (int i = 1; i <= flips.size(); ++i) {
            mx = max(mx, flips[i - 1]);
            ans += mx == i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numTimesAllBlue(flips []int) (ans int) {
	mx := 0
	for i, x := range flips {
		mx = max(mx, x)
		if mx == i+1 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numTimesAllBlue(flips: number[]): number {
    let ans = 0;
    let mx = 0;
    for (let i = 1; i <= flips.length; ++i) {
        mx = Math.max(mx, flips[i - 1]);
        if (mx === i) {
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

<p>给你一个长度为 <code>n</code> 、下标从 <strong>1</strong> 开始的二进制字符串，所有位最开始都是 <code>0</code> 。我们会按步翻转该二进制字符串的所有位（即，将 <code>0</code> 变为 <code>1</code>）。</p>

<p>给你一个下标从 <strong>1</strong> 开始的整数数组 <code>flips</code> ，其中 <code>flips[i]</code> 表示对应下标 <code>i</code> 的位将会在第 <code>i</code> 步翻转。</p>

<p>二进制字符串 <strong>前缀一致</strong> 需满足：在第 <code>i</code> 步之后，在 <strong>闭</strong> 区间&nbsp;<code>[1, i]</code> 内的所有位都是 1 ，而其他位都是 0 。</p>

<p>返回二进制字符串在翻转过程中 <strong>前缀一致</strong> 的次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>flips = [3,2,4,1,5]
<strong>输出：</strong>2
<strong>解释：</strong>二进制字符串最开始是 "00000" 。
执行第 1 步：字符串变为 "00100" ，不属于前缀一致的情况。
执行第 2 步：字符串变为 "01100" ，不属于前缀一致的情况。
执行第 3 步：字符串变为 "01110" ，不属于前缀一致的情况。
执行第 4 步：字符串变为 "11110" ，属于前缀一致的情况。
执行第 5 步：字符串变为 "11111" ，属于前缀一致的情况。
在翻转过程中，前缀一致的次数为 2 ，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>flips = [4,1,2,3]
<strong>输出：</strong>1
<strong>解释：</strong>二进制字符串最开始是 "0000" 。
执行第 1 步：字符串变为 "0001" ，不属于前缀一致的情况。
执行第 2 步：字符串变为 "1001" ，不属于前缀一致的情况。
执行第 3 步：字符串变为 "1101" ，不属于前缀一致的情况。
执行第 4 步：字符串变为 "1111" ，属于前缀一致的情况。
在翻转过程中，前缀一致的次数为 1 ，所以返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == flips.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flips</code> 是范围 <code>[1, n]</code> 中所有整数构成的一个排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们可以遍历数组 $flips$，记录当前遍历过的元素的最大值 $mx$，若 $mx$ 等于当前遍历到的下标 $i$，则说明前 $i$ 个元素都被翻转过了，即前缀一致，答案累加。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $flips$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        ans = mx = 0
        for i, x in enumerate(flips, 1):
            mx = max(mx, x)
            ans += mx == i
        return ans
```

#### Java

```java
class Solution {
    public int numTimesAllBlue(int[] flips) {
        int ans = 0, mx = 0;
        for (int i = 1; i <= flips.length; ++i) {
            mx = Math.max(mx, flips[i - 1]);
            if (mx == i) {
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
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, mx = 0;
        for (int i = 1; i <= flips.size(); ++i) {
            mx = max(mx, flips[i - 1]);
            ans += mx == i;
        }
        return ans;
    }
};
```

#### Go

```go
func numTimesAllBlue(flips []int) (ans int) {
	mx := 0
	for i, x := range flips {
		mx = max(mx, x)
		if mx == i+1 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numTimesAllBlue(flips: number[]): number {
    let ans = 0;
    let mx = 0;
    for (let i = 1; i <= flips.length; ++i) {
        mx = Math.max(mx, flips[i - 1]);
        if (mx === i) {
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

# [1376. 通知所有员工所需的时间](https://leetcode.cn/problems/time-needed-to-inform-all-employees){#1376}

{{< tabs "1376" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfMinutes(
        self, n: int, headID: int, manager: List[int], informTime: List[int]
    ) -> int:
        def dfs(i: int) -> int:
            ans = 0
            for j in g[i]:
                ans = max(ans, dfs(j) + informTime[i])
            return ans

        g = defaultdict(list)
        for i, x in enumerate(manager):
            g[x].append(i)
        return dfs(headID)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] informTime;

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        this.informTime = informTime;
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                g[manager[i]].add(i);
            }
        }
        return dfs(headID);
    }

    private int dfs(int i) {
        int ans = 0;
        for (int j : g[i]) {
            ans = Math.max(ans, dfs(j) + informTime[i]);
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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                g[manager[i]].push_back(i);
            }
        }
        function<int(int)> dfs = [&](int i) -> int {
            int ans = 0;
            for (int j : g[i]) {
                ans = max(ans, dfs(j) + informTime[i]);
            }
            return ans;
        };
        return dfs(headID);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
	g := make([][]int, n)
	for i, x := range manager {
		if x != -1 {
			g[x] = append(g[x], i)
		}
	}
	var dfs func(int) int
	dfs = func(i int) (ans int) {
		for _, j := range g[i] {
			ans = max(ans, dfs(j)+informTime[i])
		}
		return
	}
	return dfs(headID)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfMinutes(n: number, headID: number, manager: number[], informTime: number[]): number {
    const g: number[][] = new Array(n).fill(0).map(() => []);
    for (let i = 0; i < n; ++i) {
        if (manager[i] !== -1) {
            g[manager[i]].push(i);
        }
    }
    const dfs = (i: number): number => {
        let ans = 0;
        for (const j of g[i]) {
            ans = Math.max(ans, dfs(j) + informTime[i]);
        }
        return ans;
    };
    return dfs(headID);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<int>[] g;
    private int[] informTime;

    public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
        }
        this.informTime = informTime;
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                g[manager[i]].Add(i);
            }
        }
        return dfs(headID);
    }

    private int dfs(int i) {
        int ans = 0;
        foreach (int j in g[i]) {
            ans = Math.Max(ans, dfs(j) + informTime[i]);
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

<p>公司里有 <code>n</code> 名员工，每个员工的 ID 都是独一无二的，编号从 <code>0</code> 到 <code>n - 1</code>。公司的总负责人通过 <code>headID</code> 进行标识。</p>

<p>在 <code>manager</code> 数组中，每个员工都有一个直属负责人，其中 <code>manager[i]</code> 是第 <code>i</code> 名员工的直属负责人。对于总负责人，<code>manager[headID] = -1</code>。题目保证从属关系可以用树结构显示。</p>

<p>公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。</p>

<p>第 <code>i</code> 名员工需要 <code>informTime[i]</code> 分钟来通知它的所有直属下属（也就是说在 <code>informTime[i]</code> 分钟后，他的所有直属下属都可以开始传播这一消息）。</p>

<p>返回通知所有员工这一紧急消息所需要的 <strong>分钟数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, headID = 0, manager = [-1], informTime = [0]
<strong>输出：</strong>0
<strong>解释：</strong>公司总负责人是该公司的唯一一名员工。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1376.Time%20Needed%20to%20Inform%20All%20Employees/images/graph.png" style="height: 174px; width: 404px;" /></p>

<pre>
<strong>输入：</strong>n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>id = 2 的员工是公司的总负责人，也是其他所有员工的直属负责人，他需要 1 分钟来通知所有员工。
上图显示了公司员工的树结构。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>0 &lt;= headID &lt; n</code></li>
	<li><code>manager.length == n</code></li>
	<li><code>0 &lt;= manager[i] &lt; n</code></li>
	<li><code>manager[headID] == -1</code></li>
	<li><code>informTime.length&nbsp;== n</code></li>
	<li><code>0 &lt;= informTime[i] &lt;= 1000</code></li>
	<li>如果员工 <code>i</code> 没有下属，<code>informTime[i] == 0</code> 。</li>
	<li>题目 <strong>保证</strong> 所有员工都可以收到通知。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据 $manager$ 数组构建邻接表 $g$，其中 $g[i]$ 表示员工 $i$ 的所有直接下属。

接下来，我们设计一个函数 $dfs(i)$，表示从员工 $i$ 开始，将消息通知给他的所有下属（包括直接下属、间接下属）所需要的时间，那么答案就是 $dfs(headID)$。

在函数 $dfs(i)$ 中，我们需要遍历 $i$ 的所有直接下属 $j$，对于每个下属，员工 $i$ 需要将消息通知给他，这需要花费 $informTime[i]$ 的时间，而他的所有下属需要将消息通知给他们的下属，这需要花费 $dfs(j)$ 的时间，取 $informTime[i] + dfs(j)$ 的最大值作为函数 $dfs(i)$ 的返回值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为员工数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfMinutes(
        self, n: int, headID: int, manager: List[int], informTime: List[int]
    ) -> int:
        def dfs(i: int) -> int:
            ans = 0
            for j in g[i]:
                ans = max(ans, dfs(j) + informTime[i])
            return ans

        g = defaultdict(list)
        for i, x in enumerate(manager):
            g[x].append(i)
        return dfs(headID)
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] informTime;

    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        this.informTime = informTime;
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                g[manager[i]].add(i);
            }
        }
        return dfs(headID);
    }

    private int dfs(int i) {
        int ans = 0;
        for (int j : g[i]) {
            ans = Math.max(ans, dfs(j) + informTime[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                g[manager[i]].push_back(i);
            }
        }
        function<int(int)> dfs = [&](int i) -> int {
            int ans = 0;
            for (int j : g[i]) {
                ans = max(ans, dfs(j) + informTime[i]);
            }
            return ans;
        };
        return dfs(headID);
    }
};
```

#### Go

```go
func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
	g := make([][]int, n)
	for i, x := range manager {
		if x != -1 {
			g[x] = append(g[x], i)
		}
	}
	var dfs func(int) int
	dfs = func(i int) (ans int) {
		for _, j := range g[i] {
			ans = max(ans, dfs(j)+informTime[i])
		}
		return
	}
	return dfs(headID)
}
```

#### TypeScript

```ts
function numOfMinutes(n: number, headID: number, manager: number[], informTime: number[]): number {
    const g: number[][] = new Array(n).fill(0).map(() => []);
    for (let i = 0; i < n; ++i) {
        if (manager[i] !== -1) {
            g[manager[i]].push(i);
        }
    }
    const dfs = (i: number): number => {
        let ans = 0;
        for (const j of g[i]) {
            ans = Math.max(ans, dfs(j) + informTime[i]);
        }
        return ans;
    };
    return dfs(headID);
}
```

#### C#

```cs
public class Solution {
    private List<int>[] g;
    private int[] informTime;

    public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
        }
        this.informTime = informTime;
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                g[manager[i]].Add(i);
            }
        }
        return dfs(headID);
    }

    private int dfs(int i) {
        int ans = 0;
        foreach (int j in g[i]) {
            ans = Math.Max(ans, dfs(j) + informTime[i]);
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1377. T 秒后青蛙的位置](https://leetcode.cn/problems/frog-position-after-t-seconds){#1377}

{{< tabs "1377" >}}

{{% tab "python" %}}
```python
class Solution:
    def frogPosition(
        self, n: int, edges: List[List[int]], t: int, target: int
    ) -> float:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        q = deque([(1, 1.0)])
        vis = [False] * (n + 1)
        vis[1] = True
        while q and t >= 0:
            for _ in range(len(q)):
                u, p = q.popleft()
                cnt = len(g[u]) - int(u != 1)
                if u == target:
                    return p if cnt * t == 0 else 0
                for v in g[u]:
                    if not vis[v]:
                        vis[v] = True
                        q.append((v, p / cnt))
            t -= 1
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<Pair<Integer, Double>> q = new ArrayDeque<>();
        q.offer(new Pair<>(1, 1.0));
        boolean[] vis = new boolean[n + 1];
        vis[1] = true;
        for (; !q.isEmpty() && t >= 0; --t) {
            for (int k = q.size(); k > 0; --k) {
                var x = q.poll();
                int u = x.getKey();
                double p = x.getValue();
                int cnt = g[u].size() - (u == 1 ? 0 : 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(new Pair<>(v, p / cnt));
                    }
                }
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<pair<int, double>> q{{{1, 1.0}}};
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        vis[1] = true;
        for (; q.size() && t >= 0; --t) {
            for (int k = q.size(); k; --k) {
                auto [u, p] = q.front();
                q.pop();
                int cnt = g[u].size() - (u != 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push({v, p / cnt});
                    }
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func frogPosition(n int, edges [][]int, t int, target int) float64 {
	g := make([][]int, n+1)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	type pair struct {
		u int
		p float64
	}
	q := []pair{{1, 1}}
	vis := make([]bool, n+1)
	vis[1] = true
	for ; len(q) > 0 && t >= 0; t-- {
		for k := len(q); k > 0; k-- {
			u, p := q[0].u, q[0].p
			q = q[1:]
			cnt := len(g[u])
			if u != 1 {
				cnt--
			}
			if u == target {
				if cnt*t == 0 {
					return p
				}
				return 0
			}
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, pair{v, p / float64(cnt)})
				}
			}
		}
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function frogPosition(n: number, edges: number[][], t: number, target: number): number {
    const g: number[][] = Array.from({ length: n + 1 }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const q: number[][] = [[1, 1]];
    const vis: boolean[] = Array.from({ length: n + 1 }, () => false);
    vis[1] = true;
    for (; q.length > 0 && t >= 0; --t) {
        for (let k = q.length; k > 0; --k) {
            const [u, p] = q.shift()!;
            const cnt = g[u].length - (u === 1 ? 0 : 1);
            if (u === target) {
                return cnt * t === 0 ? p : 0;
            }
            for (const v of g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push([v, p / cnt]);
                }
            }
        }
    }
    return 0;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public double FrogPosition(int n, int[][] edges, int t, int target) {
        List<int>[] g = new List<int>[n + 1];
        for (int i = 0; i < n + 1; i++) {
            g[i] = new List<int>();
        }
        foreach (int[] e in edges) {
            int u = e[0], v = e[1];
            g[u].Add(v);
            g[v].Add(u);
        }
        Queue<Tuple<int, double>> q = new Queue<Tuple<int, double>>();
        q.Enqueue(new Tuple<int, double>(1, 1.0));
        bool[] vis = new bool[n + 1];
        vis[1] = true;
        for (; q.Count > 0 && t >= 0; --t) {
            for (int k = q.Count; k > 0; --k) {
                (var u, var p) = q.Dequeue();
                int cnt = g[u].Count - (u == 1 ? 0 : 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                foreach (int v in g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.Enqueue(new Tuple<int, double>(v, p / cnt));
                    }
                }
            }
        }
        return 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵由 <code>n</code> 个顶点组成的无向树，顶点编号从 <code>1</code> 到 <code>n</code>。青蛙从 <strong>顶点 1</strong> 开始起跳。规则如下：</p>

<ul>
	<li>在一秒内，青蛙从它所在的当前顶点跳到另一个 <strong>未访问</strong> 过的顶点（如果它们直接相连）。</li>
	<li>青蛙无法跳回已经访问过的顶点。</li>
	<li>如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。</li>
	<li>如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。</li>
</ul>

<p>无向树的边用数组 <code>edges</code> 描述，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 意味着存在一条直接连通 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 两个顶点的边。</p>

<p>返回青蛙在 <em><code>t</code></em> 秒后位于目标顶点 <em><code>target</code> </em>上的概率。与实际答案相差不超过 <code>10<sup>-5</sup></code> 的结果将被视为正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1377.Frog%20Position%20After%20T%20Seconds/images/frog1.jpg" /></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
<strong>输出：</strong>0.16666666666666666 
<strong>解释：</strong>上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，第 <strong>1 秒</strong> 有 1/3 的概率跳到顶点 2 ，然后第 <strong>2 秒</strong> 有 1/2 的概率跳到顶点 4，因此青蛙在 2 秒后位于顶点 4 的概率是 1/3 * 1/2 = 1/6 = 0.16666666666666666 。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1377.Frog%20Position%20After%20T%20Seconds/images/frog2.jpg" /></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
<strong>输出：</strong>0.3333333333333333
<strong>解释：</strong>上图显示了青蛙的跳跃路径。青蛙从顶点 1 起跳，有 1/3 = 0.3333333333333333 的概率能够 <strong>1 秒</strong> 后跳到顶点 7 。 
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt;= n</code></li>
	<li><code>1 &lt;= t &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们先根据题目给出的无向树的边，建立一个邻接表 $g$，其中 $g[u]$ 表示顶点 $u$ 的所有相邻顶点。

然后，我们定义以下数据结构：

-   队列 $q$，用于存储每一轮搜索的顶点及其概率，初始时 $q = [(1, 1.0)]$，表示青蛙在顶点 $1$ 的概率为 $1.0$；
-   数组 $vis$，用于记录每个顶点是否被访问过，初始时 $vis[1] = true$，其余元素均为 $false$。

接下来，我们开始进行广度优先搜索。

在每一轮搜索中，我们每次取出队首元素 $(u, p)$，其中 $u$ 和 $p$ 分别表示当前顶点及其概率。当前顶点 $u$ 的相邻顶点中未被访问过的顶点的个数记为 $cnt$。

-   如果 $u = target$，说明青蛙已经到达目标顶点，此时我们判断青蛙是否在 $t$ 秒到达目标顶点，或者不到 $t$ 秒到达目标顶点但是无法再跳跃到其它顶点（即 $t=0$ 或者 $cnt=0$）。如果是，则返回 $p$，否则返回 $0$。
-   如果 $u \neq target$，那么我们将概率 $p$ 均分给 $u$ 的所有未被访问过的相邻顶点，然后将这些顶点加入队列 $q$ 中，并且将这些顶点标记为已访问。

在一轮搜索结束后，我们将 $t$ 减少 $1$，然后继续进行下一轮搜索，直到队列为空或者 $t \lt 0$。

最后，若青蛙仍然没有到达目标顶点，那么我们返回 $0$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是无向树的顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def frogPosition(
        self, n: int, edges: List[List[int]], t: int, target: int
    ) -> float:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        q = deque([(1, 1.0)])
        vis = [False] * (n + 1)
        vis[1] = True
        while q and t >= 0:
            for _ in range(len(q)):
                u, p = q.popleft()
                cnt = len(g[u]) - int(u != 1)
                if u == target:
                    return p if cnt * t == 0 else 0
                for v in g[u]:
                    if not vis[v]:
                        vis[v] = True
                        q.append((v, p / cnt))
            t -= 1
        return 0
```

#### Java

```java
class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<Pair<Integer, Double>> q = new ArrayDeque<>();
        q.offer(new Pair<>(1, 1.0));
        boolean[] vis = new boolean[n + 1];
        vis[1] = true;
        for (; !q.isEmpty() && t >= 0; --t) {
            for (int k = q.size(); k > 0; --k) {
                var x = q.poll();
                int u = x.getKey();
                double p = x.getValue();
                int cnt = g[u].size() - (u == 1 ? 0 : 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(new Pair<>(v, p / cnt));
                    }
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<pair<int, double>> q{{{1, 1.0}}};
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        vis[1] = true;
        for (; q.size() && t >= 0; --t) {
            for (int k = q.size(); k; --k) {
                auto [u, p] = q.front();
                q.pop();
                int cnt = g[u].size() - (u != 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push({v, p / cnt});
                    }
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func frogPosition(n int, edges [][]int, t int, target int) float64 {
	g := make([][]int, n+1)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	type pair struct {
		u int
		p float64
	}
	q := []pair{{1, 1}}
	vis := make([]bool, n+1)
	vis[1] = true
	for ; len(q) > 0 && t >= 0; t-- {
		for k := len(q); k > 0; k-- {
			u, p := q[0].u, q[0].p
			q = q[1:]
			cnt := len(g[u])
			if u != 1 {
				cnt--
			}
			if u == target {
				if cnt*t == 0 {
					return p
				}
				return 0
			}
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, pair{v, p / float64(cnt)})
				}
			}
		}
	}
	return 0
}
```

#### TypeScript

```ts
function frogPosition(n: number, edges: number[][], t: number, target: number): number {
    const g: number[][] = Array.from({ length: n + 1 }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const q: number[][] = [[1, 1]];
    const vis: boolean[] = Array.from({ length: n + 1 }, () => false);
    vis[1] = true;
    for (; q.length > 0 && t >= 0; --t) {
        for (let k = q.length; k > 0; --k) {
            const [u, p] = q.shift()!;
            const cnt = g[u].length - (u === 1 ? 0 : 1);
            if (u === target) {
                return cnt * t === 0 ? p : 0;
            }
            for (const v of g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push([v, p / cnt]);
                }
            }
        }
    }
    return 0;
}
```

#### C#

```cs
public class Solution {
    public double FrogPosition(int n, int[][] edges, int t, int target) {
        List<int>[] g = new List<int>[n + 1];
        for (int i = 0; i < n + 1; i++) {
            g[i] = new List<int>();
        }
        foreach (int[] e in edges) {
            int u = e[0], v = e[1];
            g[u].Add(v);
            g[v].Add(u);
        }
        Queue<Tuple<int, double>> q = new Queue<Tuple<int, double>>();
        q.Enqueue(new Tuple<int, double>(1, 1.0));
        bool[] vis = new bool[n + 1];
        vis[1] = true;
        for (; q.Count > 0 && t >= 0; --t) {
            for (int k = q.Count; k > 0; --k) {
                (var u, var p) = q.Dequeue();
                int cnt = g[u].Count - (u == 1 ? 0 : 1);
                if (u == target) {
                    return cnt * t == 0 ? p : 0;
                }
                foreach (int v in g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.Enqueue(new Tuple<int, double>(v, p / cnt));
                    }
                }
            }
        }
        return 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1378. 使用唯一标识码替换员工ID](https://leetcode.cn/problems/replace-employee-id-with-the-unique-identifier){#1378}

{{< tabs "1378" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT unique_id, name
FROM
    Employees
    LEFT JOIN EmployeeUNI USING (id);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Employees</code> 表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
在 SQL 中，id 是这张表的主键。
这张表的每一行分别代表了某公司其中一位员工的名字和 ID 。
</pre>

<p>&nbsp;</p>

<p><code>EmployeeUNI</code>&nbsp;表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| unique_id     | int     |
+---------------+---------+
在 SQL 中，(id, unique_id) 是这张表的主键。
这张表的每一行包含了该公司某位员工的 ID 和他的唯一标识码（unique ID）。
</pre>

<p>&nbsp;</p>

<p>展示每位用户的<strong> 唯一标识码（unique ID ）</strong>；如果某位员工没有唯一标识码，使用 null 填充即可。</p>

<p>你可以以<strong> 任意</strong> 顺序返回结果表。</p>

<p>返回结果的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Employees</code> 表:
+----+----------+
| id | name     |
+----+----------+
| 1  | Alice    |
| 7  | Bob      |
| 11 | Meir     |
| 90 | Winston  |
| 3  | Jonathan |
+----+----------+
<code>EmployeeUNI</code> 表:
+----+-----------+
| id | unique_id |
+----+-----------+
| 3  | 1         |
| 11 | 2         |
| 90 | 3         |
+----+-----------+
<strong>输出：</strong>
+-----------+----------+
| unique_id | name     |
+-----------+----------+
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
+-----------+----------+
<strong>解释：</strong>
Alice and Bob 没有唯一标识码, 因此我们使用 null 替代。
Meir 的唯一标识码是 2 。
Winston 的唯一标识码是 3 。
Jonathan 唯一标识码是 1 。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：LEFT JOIN

我们可以使用 `LEFT JOIN` 来连接 `Employees` 和 `EmployeeUNI` 表，然后使用 `SELECT` 语句来选择 `unique_id` 和 `name` 列。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT unique_id, name
FROM
    Employees
    LEFT JOIN EmployeeUNI USING (id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1379. 找出克隆二叉树中的相同节点](https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree){#1379}

{{< tabs "1379" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def getTargetCopy(
        self, original: TreeNode, cloned: TreeNode, target: TreeNode
    ) -> TreeNode:
        def dfs(root1: TreeNode, root2: TreeNode) -> TreeNode:
            if root1 is None:
                return None
            if root1 == target:
                return root2
            return dfs(root1.left, root2.left) or dfs(root1.right, root2.right)

        return dfs(original, cloned)
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
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    private TreeNode target;

    public final TreeNode getTargetCopy(
        final TreeNode original, final TreeNode cloned, final TreeNode target) {
        this.target = target;
        return dfs(original, cloned);
    }

    private TreeNode dfs(TreeNode root1, TreeNode root2) {
        if (root1 == null) {
            return null;
        }
        if (root1 == target) {
            return root2;
        }
        TreeNode res = dfs(root1.left, root2.left);
        return res == null ? dfs(root1.right, root2.right) : res;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        function<TreeNode*(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root1, TreeNode* root2) -> TreeNode* {
            if (root1 == nullptr) {
                return nullptr;
            }
            if (root1 == target) {
                return root2;
            }
            TreeNode* left = dfs(root1->left, root2->left);
            return left == nullptr ? dfs(root1->right, root2->right) : left;
        };
        return dfs(original, cloned);
    }
};
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

function getTargetCopy(
    original: TreeNode | null,
    cloned: TreeNode | null,
    target: TreeNode | null,
): TreeNode | null {
    const dfs = (root1: TreeNode | null, root2: TreeNode | null): TreeNode | null => {
        if (!root1) {
            return null;
        }
        if (root1 === target) {
            return root2;
        }
        return dfs(root1.left, root2.left) || dfs(root1.right, root2.right);
    };
    return dfs(original, cloned);
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
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    private TreeNode target;

    public TreeNode GetTargetCopy(TreeNode original, TreeNode cloned, TreeNode target) {
        this.target = target;
        return dfs(original, cloned);
    }

    private TreeNode dfs(TreeNode original, TreeNode cloned) {
        if (original == null) {
            return null;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode left = dfs(original.left, cloned.left);
        return left == null ? dfs(original.right, cloned.right) : left;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两棵二叉树，原始树 <code>original</code> 和克隆树 <code>cloned</code>，以及一个位于原始树 <code>original</code>&nbsp;中的目标节点&nbsp;<code>target</code>。</p>

<p>其中，克隆树 <code>cloned</code>&nbsp;是原始树 <code>original</code>&nbsp;的一个<strong> 副本 </strong>。</p>

<p>请找出在树&nbsp;<code>cloned</code>&nbsp;中，与&nbsp;<code>target</code>&nbsp;<strong>相同&nbsp;</strong>的节点，并返回对该节点的引用（在 C/C++ 等有指针的语言中返回 节点指针，其他语言返回节点本身）。</p>

<p>&nbsp;</p>

<p><strong>注意：</strong>你 <strong>不能</strong> 对两棵二叉树，以及 <code>target</code>&nbsp;节点进行更改。<strong>只能</strong> 返回对克隆树&nbsp;<code>cloned</code>&nbsp;中已有的节点的引用。</p>

<ul>
</ul>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1379.Find%20a%20Corresponding%20Node%20of%20a%20Binary%20Tree%20in%20a%20Clone%20of%20That%20Tree/images/e1.png" /></p>

<pre>
<strong>输入:</strong> tree = [7,4,3,null,null,6,19], target = 3
<strong>输出:</strong> 3
<strong>解释:</strong> 上图画出了树 original 和 cloned。target 节点在树 original 中，用绿色标记。答案是树 cloned 中的黄颜色的节点（其他示例类似）。</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1379.Find%20a%20Corresponding%20Node%20of%20a%20Binary%20Tree%20in%20a%20Clone%20of%20That%20Tree/images/e2.png" /></p>

<pre>
<strong>输入:</strong> tree = [7], target =  7
<strong>输出:</strong> 7
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1379.Find%20a%20Corresponding%20Node%20of%20a%20Binary%20Tree%20in%20a%20Clone%20of%20That%20Tree/images/e3.png" /></p>

<pre>
<strong>输入:</strong> tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量范围为<meta charset="UTF-8" />&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;。</li>
	<li>同一棵树中，没有值相同的节点。</li>
	<li><code>target</code>&nbsp;节点是树&nbsp;<code>original</code>&nbsp;中的一个节点，并且不会是&nbsp;<code>null</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果树中允许出现值相同的节点，将如何解答？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root1, root2)$，它会在树 $root1$ 和 $root2$ 中同时进行 DFS 遍历，当遍历到某个节点时，如果这个节点恰好为 $target$，那么我们就返回 $root2$ 中对应的节点。否则，我们递归地在 $root1$ 和 $root2$ 的左右子树中寻找 $target$，并返回找到的结果中不为空的那一个。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中节点的数量。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def getTargetCopy(
        self, original: TreeNode, cloned: TreeNode, target: TreeNode
    ) -> TreeNode:
        def dfs(root1: TreeNode, root2: TreeNode) -> TreeNode:
            if root1 is None:
                return None
            if root1 == target:
                return root2
            return dfs(root1.left, root2.left) or dfs(root1.right, root2.right)

        return dfs(original, cloned)
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    private TreeNode target;

    public final TreeNode getTargetCopy(
        final TreeNode original, final TreeNode cloned, final TreeNode target) {
        this.target = target;
        return dfs(original, cloned);
    }

    private TreeNode dfs(TreeNode root1, TreeNode root2) {
        if (root1 == null) {
            return null;
        }
        if (root1 == target) {
            return root2;
        }
        TreeNode res = dfs(root1.left, root2.left);
        return res == null ? dfs(root1.right, root2.right) : res;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        function<TreeNode*(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root1, TreeNode* root2) -> TreeNode* {
            if (root1 == nullptr) {
                return nullptr;
            }
            if (root1 == target) {
                return root2;
            }
            TreeNode* left = dfs(root1->left, root2->left);
            return left == nullptr ? dfs(root1->right, root2->right) : left;
        };
        return dfs(original, cloned);
    }
};
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

function getTargetCopy(
    original: TreeNode | null,
    cloned: TreeNode | null,
    target: TreeNode | null,
): TreeNode | null {
    const dfs = (root1: TreeNode | null, root2: TreeNode | null): TreeNode | null => {
        if (!root1) {
            return null;
        }
        if (root1 === target) {
            return root2;
        }
        return dfs(root1.left, root2.left) || dfs(root1.right, root2.right);
    };
    return dfs(original, cloned);
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
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    private TreeNode target;

    public TreeNode GetTargetCopy(TreeNode original, TreeNode cloned, TreeNode target) {
        this.target = target;
        return dfs(original, cloned);
    }

    private TreeNode dfs(TreeNode original, TreeNode cloned) {
        if (original == null) {
            return null;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode left = dfs(original.left, cloned.left);
        return left == null ? dfs(original.right, cloned.right) : left;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
