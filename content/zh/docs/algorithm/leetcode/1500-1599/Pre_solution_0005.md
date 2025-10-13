---
title: "1540_K 次操作转变字符串"
date: 2025-10-08T18:37:33+08:00
weight: 5
tags: [位运算, 前缀和, 动态规划, 哈希表, 图, 字符串, 排序, 数据库, 数组, 栈, 模拟, 贪心, 递归]
---

{{< markmap >}}
### [1540_K 次操作转变字符串](#1540)
#### [哈希表](#1540)
#### [字符串](#1540)
### [1541_平衡括号字符串的最少插入次数](#1541)
#### [栈](#1541)
#### [贪心](#1541)
#### [字符串](#1541)
### [1542_找出最长的超赞子字符串](#1542)
#### [位运算](#1542)
#### [哈希表](#1542)
#### [字符串](#1542)
### [1543_产品名称格式修复 🔒](#1543)
#### [数据库](#1543)
### [1544_整理字符串](#1544)
#### [栈](#1544)
#### [字符串](#1544)
### [1545_找出第 N 个二进制字符串中的第 K 位](#1545)
#### [递归](#1545)
#### [字符串](#1545)
#### [模拟](#1545)
### [1546_和为目标值且不重叠的非空子数组的最大数目](#1546)
#### [贪心](#1546)
#### [数组](#1546)
#### [哈希表](#1546)
#### [前缀和](#1546)
### [1547_切棍子的最小成本](#1547)
#### [数组](#1547)
#### [动态规划](#1547)
#### [排序](#1547)
### [1548_图中最相似的路径 🔒](#1548)
#### [图](#1548)
#### [动态规划](#1548)
### [1549_每件商品的最新订单 🔒](#1549)
#### [数据库](#1549)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1540_K 次操作转变字符串
___
#### 哈希表
___
#### 字符串
---
### 1541_平衡括号字符串的最少插入次数
___
#### 栈
___
#### 贪心
___
#### 字符串
---
### 1542_找出最长的超赞子字符串
___
#### 位运算
___
#### 哈希表
___
#### 字符串
---
### 1543_产品名称格式修复 🔒
___
#### 数据库
---
### 1544_整理字符串
___
#### 栈
___
#### 字符串
---
### 1545_找出第 N 个二进制字符串中的第 K 位
___
#### 递归
___
#### 字符串
___
#### 模拟
---
### 1546_和为目标值且不重叠的非空子数组的最大数目
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1547_切棍子的最小成本
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1548_图中最相似的路径 🔒
___
#### 图
___
#### 动态规划
---
### 1549_每件商品的最新订单 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 哈希表 | 图 | 字符串 |
| 排序 | 数据库 | 数组 |
| 栈 | 模拟 | 贪心 |
| 递归 |  |  |

# [1540. K 次操作转变字符串](https://leetcode.cn/problems/can-convert-string-in-k-moves){#1540}

{{< tabs "1540" >}}

{{% tab "python" %}}
```python
class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for a, b in zip(s, t):
            x = (ord(b) - ord(a) + 26) % 26
            cnt[x] += 1
        for i in range(1, 26):
            if i + 26 * (cnt[i] - 1) > k:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canConvertString(String s, String t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            int x = (t.charAt(i) - s.charAt(i) + 26) % 26;
            ++cnt[x];
        }
        for (int i = 1; i < 26; ++i) {
            if (i + 26 * (cnt[i] - 1) > k) {
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
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt[26]{};
        for (int i = 0; i < s.size(); ++i) {
            int x = (t[i] - s[i] + 26) % 26;
            ++cnt[x];
        }
        for (int i = 1; i < 26; ++i) {
            if (i + 26 * (cnt[i] - 1) > k) {
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
func canConvertString(s string, t string, k int) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := [26]int{}
	for i := range s {
		x := (t[i] - s[i] + 26) % 26
		cnt[x]++
	}
	for i := 1; i < 26; i++ {
		if i+26*(cnt[i]-1) > k {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;，你的目标是在 <code>k</code>&nbsp;次操作以内把字符串&nbsp;<code>s</code>&nbsp;转变成&nbsp;<code>t</code>&nbsp;。</p>

<p>在第 <code>i</code>&nbsp;次操作时（<code>1 &lt;= i &lt;= k</code>），你可以选择进行如下操作：</p>

<ul>
	<li>选择字符串 <code>s</code>&nbsp;中满足 <code>1 &lt;= j &lt;= s.length</code>&nbsp;且之前未被选过的任意下标 <code>j</code>&nbsp;（下标从 1 开始），并将此位置的字符切换 <code>i</code>&nbsp;次。</li>
	<li>不进行任何操作。</li>
</ul>

<p>切换 1 个字符的意思是用字母表中该字母的下一个字母替换它（字母表环状接起来，所以 <code>'z'</code>&nbsp;切换后会变成 <code>'a'</code>）。第 <code>i</code>&nbsp;次操作意味着该字符应切换&nbsp;<code>i</code>&nbsp;次</p>

<p>请记住任意一个下标 <code>j</code>&nbsp;最多只能被操作&nbsp;1 次。</p>

<p>如果在不超过 <code>k</code>&nbsp;次操作内可以把字符串 <code>s</code>&nbsp;转变成 <code>t</code>&nbsp;，那么请你返回&nbsp;<code>true</code>&nbsp;，否则请你返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "input", t = "ouput", k = 9
<strong>输出：</strong>true
<strong>解释：</strong>第 6 次操作时，我们将 'i' 切换 6 次得到 'o' 。第 7 次操作时，我们将 'n' 切换 7 次得到 'u' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", t = "bcd", k = 10
<strong>输出：</strong>false
<strong>解释：</strong>我们需要将每个字符切换 1 次才能得到 t 。我们可以在第 1 次操作时将 'a' 切换成 'b' ，但另外 2 个字母在剩余操作中无法再转变为 t 中对应字母。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "aab", t = "bbb", k = 27
<strong>输出：</strong>true
<strong>解释：</strong>第 1 次操作时，我们将第一个 'a' 切换 1 次得到 'b' 。在第 27 次操作时，我们将第二个字母 'a' 切换 27 次得到 'b' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= k &lt;= 10^9</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们首先判断字符串 $s$ 和字符串 $t$ 的长度是否相等，如果不相等，直接返回 `false`。

如果相等，我们可以统计每个位置的字符需要操作的最小次数，即 $cnt[x]$ 表示最小操作次数为 $x$ 的字符的个数。

如果有 $cnt[x]$ 个字符需要操作 $x$ 次，那么我们需要 $x + 26 \times (cnt[x] - 1)$ 次操作才能将这些字符转换为 $t$ 中对应的字符。因此，我们在 $[1,..25] 范围内枚举 $x$，如果 $x + 26 \times (cnt[x] - 1) \gt k$，说明我们无法将所有字符转换为 $t$ 中对应的字符，返回 `false`。

否则，枚举结束后，说明我们可以将所有字符转换为 $t$ 中对应的字符，返回 `true`。

时间复杂度 $O(n + C)$，空间复杂度 $O(C)$，其中 $n$ 为字符串 $s$ 和 $t$ 的长度；而 $C$ 为字符集大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for a, b in zip(s, t):
            x = (ord(b) - ord(a) + 26) % 26
            cnt[x] += 1
        for i in range(1, 26):
            if i + 26 * (cnt[i] - 1) > k:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean canConvertString(String s, String t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            int x = (t.charAt(i) - s.charAt(i) + 26) % 26;
            ++cnt[x];
        }
        for (int i = 1; i < 26; ++i) {
            if (i + 26 * (cnt[i] - 1) > k) {
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
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt[26]{};
        for (int i = 0; i < s.size(); ++i) {
            int x = (t[i] - s[i] + 26) % 26;
            ++cnt[x];
        }
        for (int i = 1; i < 26; ++i) {
            if (i + 26 * (cnt[i] - 1) > k) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canConvertString(s string, t string, k int) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := [26]int{}
	for i := range s {
		x := (t[i] - s[i] + 26) % 26
		cnt[x]++
	}
	for i := 1; i < 26; i++ {
		if i+26*(cnt[i]-1) > k {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1541. 平衡括号字符串的最少插入次数](https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string){#1541}

{{< tabs "1541" >}}

{{% tab "python" %}}
```python
class Solution:
    def minInsertions(self, s: str) -> int:
        ans = x = 0
        i, n = 0, len(s)
        while i < n:
            if s[i] == '(':
                # 待匹配的左括号加 1
                x += 1
            else:
                if i < n - 1 and s[i + 1] == ')':
                    # 有连续两个右括号，i 往后移动
                    i += 1
                else:
                    # 只有一个右括号，插入一个
                    ans += 1
                if x == 0:
                    # 无待匹配的左括号，插入一个
                    ans += 1
                else:
                    # 待匹配的左括号减 1
                    x -= 1
            i += 1
        # 遍历结束，仍有待匹配的左括号，说明右括号不足，插入 x << 1 个
        ans += x << 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minInsertions(String s) {
        int ans = 0, x = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                ++x;
            } else {
                if (i < n - 1 && s.charAt(i + 1) == ')') {
                    ++i;
                } else {
                    ++ans;
                }
                if (x == 0) {
                    ++ans;
                } else {
                    --x;
                }
            }
        }
        ans += x << 1;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, x = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++x;
            } else {
                if (i < n - 1 && s[i + 1] == ')') {
                    ++i;
                } else {
                    ++ans;
                }
                if (x == 0) {
                    ++ans;
                } else {
                    --x;
                }
            }
        }
        ans += x << 1;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minInsertions(s string) int {
	ans, x, n := 0, 0, len(s)
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			x++
		} else {
			if i < n-1 && s[i+1] == ')' {
				i++
			} else {
				ans++
			}
			if x == 0 {
				ans++
			} else {
				x--
			}
		}
	}
	ans += x << 1
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个括号字符串&nbsp;<code>s</code>&nbsp;，它只包含字符&nbsp;<code>&#39;(&#39;</code> 和&nbsp;<code>&#39;)&#39;</code>&nbsp;。一个括号字符串被称为平衡的当它满足：</p>

<ul>
	<li>任何左括号&nbsp;<code>&#39;(&#39;</code>&nbsp;必须对应两个连续的右括号&nbsp;<code>&#39;))&#39;</code>&nbsp;。</li>
	<li>左括号&nbsp;<code>&#39;(&#39;</code>&nbsp;必须在对应的连续两个右括号&nbsp;<code>&#39;))&#39;</code>&nbsp;之前。</li>
</ul>

<p>比方说&nbsp;<code>&quot;())&quot;</code>，&nbsp;<code>&quot;())(())))&quot;</code> 和&nbsp;<code>&quot;(())())))&quot;</code>&nbsp;都是平衡的，&nbsp;<code>&quot;)()&quot;</code>，&nbsp;<code>&quot;()))&quot;</code> 和&nbsp;<code>&quot;(()))&quot;</code>&nbsp;都是不平衡的。</p>

<p>你可以在任意位置插入字符 &#39;(&#39; 和 &#39;)&#39; 使字符串平衡。</p>

<p>请你返回让 <code>s</code>&nbsp;平衡的最少插入次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;(()))&quot;
<strong>输出：</strong>1
<strong>解释：</strong>第二个左括号有与之匹配的两个右括号，但是第一个左括号只有一个右括号。我们需要在字符串结尾额外增加一个 &#39;)&#39; 使字符串变成平衡字符串 &quot;(())))&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;())&quot;
<strong>输出：</strong>0
<strong>解释：</strong>字符串已经平衡了。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;))())(&quot;
<strong>输出：</strong>3
<strong>解释：</strong>添加 &#39;(&#39; 去匹配最开头的 &#39;))&#39; ，然后添加 &#39;))&#39; 去匹配最后一个 &#39;(&#39; 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;((((((&quot;
<strong>输出：</strong>12
<strong>解释：</strong>添加 12 个 &#39;)&#39; 得到平衡字符串。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;)))))))&quot;
<strong>输出：</strong>5
<strong>解释：</strong>在字符串开头添加 4 个 &#39;(&#39; 并在结尾添加 1 个 &#39;)&#39; ，字符串变成平衡字符串 &quot;(((())))))))&quot; 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code>&nbsp;只包含&nbsp;<code>&#39;(&#39;</code> 和&nbsp;<code>&#39;)&#39;</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用 $x$ 表示字符串中待匹配的左括号的数量，初始时为 $0$。遍历字符串 $s$：

如果遇到左括号，则 $x$ 的值加 $1$；如果遇到右括号，我们分情况讨论：

-   如果有两个连续的右括号，那么我们先让指针往后移动一位；否则，我们需要插入一个右括号，使得出现两个连续的右括号，因此插入次数加 $1$；
-   如果 $x = 0$，说明当前没有待匹配的左括号，我们需要插入一个左括号，用于匹配上面准备好的两个连续的右括号，因此插入次数加 $1$；否则，我们让 $x$ 的值减 $1$。

然后指针往后移动一位，继续下一次遍历。

遍历结束后，如果 $x = 0$，说明字符串已经平衡，返回插入次数；否则，说明字符串中有待匹配的左括号，我们需要再插入 $2 \times x$ 个右括号，使得字符串变成平衡字符串，返回插入次数。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minInsertions(self, s: str) -> int:
        ans = x = 0
        i, n = 0, len(s)
        while i < n:
            if s[i] == '(':
                # 待匹配的左括号加 1
                x += 1
            else:
                if i < n - 1 and s[i + 1] == ')':
                    # 有连续两个右括号，i 往后移动
                    i += 1
                else:
                    # 只有一个右括号，插入一个
                    ans += 1
                if x == 0:
                    # 无待匹配的左括号，插入一个
                    ans += 1
                else:
                    # 待匹配的左括号减 1
                    x -= 1
            i += 1
        # 遍历结束，仍有待匹配的左括号，说明右括号不足，插入 x << 1 个
        ans += x << 1
        return ans
```

#### Java

```java
class Solution {
    public int minInsertions(String s) {
        int ans = 0, x = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                ++x;
            } else {
                if (i < n - 1 && s.charAt(i + 1) == ')') {
                    ++i;
                } else {
                    ++ans;
                }
                if (x == 0) {
                    ++ans;
                } else {
                    --x;
                }
            }
        }
        ans += x << 1;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, x = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++x;
            } else {
                if (i < n - 1 && s[i + 1] == ')') {
                    ++i;
                } else {
                    ++ans;
                }
                if (x == 0) {
                    ++ans;
                } else {
                    --x;
                }
            }
        }
        ans += x << 1;
        return ans;
    }
};
```

#### Go

```go
func minInsertions(s string) int {
	ans, x, n := 0, 0, len(s)
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			x++
		} else {
			if i < n-1 && s[i+1] == ')' {
				i++
			} else {
				ans++
			}
			if x == 0 {
				ans++
			} else {
				x--
			}
		}
	}
	ans += x << 1
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1542. 找出最长的超赞子字符串](https://leetcode.cn/problems/find-longest-awesome-substring){#1542}

{{< tabs "1542" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestAwesome(self, s: str) -> int:
        st = 0
        d = {0: -1}
        ans = 1
        for i, c in enumerate(s):
            v = int(c)
            st ^= 1 << v
            if st in d:
                ans = max(ans, i - d[st])
            else:
                d[st] = i
            for v in range(10):
                if st ^ (1 << v) in d:
                    ans = max(ans, i - d[st ^ (1 << v)])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestAwesome(String s) {
        int[] d = new int[1024];
        int st = 0, ans = 1;
        Arrays.fill(d, -1);
        d[0] = 0;
        for (int i = 1; i <= s.length(); ++i) {
            int v = s.charAt(i - 1) - '0';
            st ^= 1 << v;
            if (d[st] >= 0) {
                ans = Math.max(ans, i - d[st]);
            } else {
                d[st] = i;
            }
            for (v = 0; v < 10; ++v) {
                if (d[st ^ (1 << v)] >= 0) {
                    ans = Math.max(ans, i - d[st ^ (1 << v)]);
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
    int longestAwesome(string s) {
        vector<int> d(1024, -1);
        d[0] = 0;
        int st = 0, ans = 1;
        for (int i = 1; i <= s.size(); ++i) {
            int v = s[i - 1] - '0';
            st ^= 1 << v;
            if (~d[st]) {
                ans = max(ans, i - d[st]);
            } else {
                d[st] = i;
            }
            for (v = 0; v < 10; ++v) {
                if (~d[st ^ (1 << v)]) {
                    ans = max(ans, i - d[st ^ (1 << v)]);
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
func longestAwesome(s string) int {
	d := [1024]int{}
	d[0] = 1
	st, ans := 0, 1
	for i, c := range s {
		i += 2
		st ^= 1 << (c - '0')
		if d[st] > 0 {
			ans = max(ans, i-d[st])
		} else {
			d[st] = i
		}
		for v := 0; v < 10; v++ {
			if d[st^(1<<v)] > 0 {
				ans = max(ans, i-d[st^(1<<v)])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestAwesome(s: string): number {
    const d: number[] = Array(1024).fill(-1);
    let [st, ans] = [0, 1];
    d[0] = 0;

    for (let i = 1; i <= s.length; ++i) {
        const v = s.charCodeAt(i - 1) - '0'.charCodeAt(0);
        st ^= 1 << v;

        if (d[st] >= 0) {
            ans = Math.max(ans, i - d[st]);
        } else {
            d[st] = i;
        }

        for (let v = 0; v < 10; ++v) {
            if (d[st ^ (1 << v)] >= 0) {
                ans = Math.max(ans, i - d[st ^ (1 << v)]);
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

<p>给你一个字符串 <code>s</code> 。请返回 <code>s</code> 中最长的 <strong>超赞子字符串</strong> 的长度。</p>

<p>「超赞子字符串」需满足满足下述两个条件：</p>

<ul>
	<li>该字符串是 <code>s</code> 的一个非空子字符串</li>
	<li>进行任意次数的字符交换后，该字符串可以变成一个回文字符串</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;3242415&quot;
<strong>输出：</strong>5
<strong>解释：</strong>&quot;24241&quot; 是最长的超赞子字符串，交换其中的字符后，可以得到回文 &quot;24142&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;12345678&quot;
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;213123&quot;
<strong>输出：</strong>6
<strong>解释：</strong>&quot;213123&quot; 是最长的超赞子字符串，交换其中的字符后，可以得到回文 &quot;231132&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;00&quot;
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> 仅由数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 前缀和思想

根据题目描述，“超赞子字符串”中的字符可以通过交换得到回文字符串，因此，“超赞子字符串”中最多有一个数字字符出现奇数次，其余数字字符出现偶数次。

我们可以用一个整数 $st$ 来表示当前前缀字符串中数字字符出现的奇偶性，其中 $st$ 的第 $i$ 位表示数字字符 $i$ 出现的奇偶性，即 $st$ 的第 $i$ 位为 $1$ 表示数字字符 $i$ 出现奇数次，为 $0$ 表示数字字符 $i$ 出现偶数次。

而如果子字符串 $s[j,..i]$ 是“超赞字符串”，那么前缀字符串 $s[0,..i]$ 的状态 $st$ 与前缀字符串 $s[0,..j-1]$ 的状态 $st'$ 的二进制位中，最多只有一位不同。这是因为，二进制位不同，表示奇偶性不同，而奇偶性不同，就意味着子字符串 $s[j,..i]$ 中该数字出现的次数为奇数次。

所以，我们可以用哈希表或数组记录所有状态 $st$ 第一次出现的位置。若当前前缀字符串的状态 $st$ 在哈希表中已经存在，那么说明当前前缀字符串的状态 $st$ 与前缀字符串 $s[0,..j-1]$ 的状态 $st'$ 的二进制位中，所有位都相同，即子字符串 $s[j,..i]$ 是“超赞字符串”，更新答案的最大值。或者，我们可以枚举每一位，将当前前缀字符串的状态 $st$ 的第 $i$ 位取反，即 $st \oplus 2^i$，然后判断 $st \oplus 2^i$ 是否在哈希表中，若在，那么说明当前前缀字符串的状态 $st$ 与前缀字符串 $s[0,..j-1]$ 的状态 $st' \oplus 2^i$ 的二进制位中，只有第 $i$ 位不同，即子字符串 $s[j,..i]$ 是“超赞字符串”，更新答案的最大值。

最后，返回答案即可。

时间复杂度 $O(n \times C)$，空间复杂度 $O(2^C)$。其中 $n$ 和 $C$ 分别为字符串 $s$ 的长度和数字字符的种类数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestAwesome(self, s: str) -> int:
        st = 0
        d = {0: -1}
        ans = 1
        for i, c in enumerate(s):
            v = int(c)
            st ^= 1 << v
            if st in d:
                ans = max(ans, i - d[st])
            else:
                d[st] = i
            for v in range(10):
                if st ^ (1 << v) in d:
                    ans = max(ans, i - d[st ^ (1 << v)])
        return ans
```

#### Java

```java
class Solution {
    public int longestAwesome(String s) {
        int[] d = new int[1024];
        int st = 0, ans = 1;
        Arrays.fill(d, -1);
        d[0] = 0;
        for (int i = 1; i <= s.length(); ++i) {
            int v = s.charAt(i - 1) - '0';
            st ^= 1 << v;
            if (d[st] >= 0) {
                ans = Math.max(ans, i - d[st]);
            } else {
                d[st] = i;
            }
            for (v = 0; v < 10; ++v) {
                if (d[st ^ (1 << v)] >= 0) {
                    ans = Math.max(ans, i - d[st ^ (1 << v)]);
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
    int longestAwesome(string s) {
        vector<int> d(1024, -1);
        d[0] = 0;
        int st = 0, ans = 1;
        for (int i = 1; i <= s.size(); ++i) {
            int v = s[i - 1] - '0';
            st ^= 1 << v;
            if (~d[st]) {
                ans = max(ans, i - d[st]);
            } else {
                d[st] = i;
            }
            for (v = 0; v < 10; ++v) {
                if (~d[st ^ (1 << v)]) {
                    ans = max(ans, i - d[st ^ (1 << v)]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestAwesome(s string) int {
	d := [1024]int{}
	d[0] = 1
	st, ans := 0, 1
	for i, c := range s {
		i += 2
		st ^= 1 << (c - '0')
		if d[st] > 0 {
			ans = max(ans, i-d[st])
		} else {
			d[st] = i
		}
		for v := 0; v < 10; v++ {
			if d[st^(1<<v)] > 0 {
				ans = max(ans, i-d[st^(1<<v)])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestAwesome(s: string): number {
    const d: number[] = Array(1024).fill(-1);
    let [st, ans] = [0, 1];
    d[0] = 0;

    for (let i = 1; i <= s.length; ++i) {
        const v = s.charCodeAt(i - 1) - '0'.charCodeAt(0);
        st ^= 1 << v;

        if (d[st] >= 0) {
            ans = Math.max(ans, i - d[st]);
        } else {
            d[st] = i;
        }

        for (let v = 0; v < 10; ++v) {
            if (d[st ^ (1 << v)] >= 0) {
                ans = Math.max(ans, i - d[st ^ (1 << v)]);
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

# [1543. 产品名称格式修复 🔒](https://leetcode.cn/problems/fix-product-name-format){#1543}

{{< tabs "1543" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            LOWER(TRIM(product_name)) AS product_name,
            DATE_FORMAT(sale_date, '%Y-%m') AS sale_date
        FROM Sales
    )
SELECT product_name, sale_date, COUNT(1) AS total
FROM t
GROUP BY 1, 2
ORDER BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Sales</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| sale_id      | int     |
| product_name | varchar |
| sale_date    | date    |
+--------------+---------+
sale_id 是该表具有唯一值的列
该表的每一行包含了产品的名称及其销售日期
</pre>

<p>&nbsp;</p>

<p>因为在 2000 年该表是手工填写的，<code>product_name</code>&nbsp;可能包含前后空格，而且包含大小写。</p>

<p>编写一个解决方案报告每个月的销售情况：</p>

<ul>
	<li><code>product_name</code>&nbsp;是小写字母且不包含前后空格</li>
	<li><code>sale_date</code>&nbsp;格式为&nbsp;<code>('YYYY-MM')</code>&nbsp;</li>
	<li><code>total</code>&nbsp;是产品在本月销售的次数</li>
</ul>

<p>返回结果以&nbsp;<code>product_name</code>&nbsp;<strong>升序</strong> 排列，如果有排名相同，再以&nbsp;<code>sale_date</code> <strong>升序 </strong>排列。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Sales</code> 表：
+---------+--------------+------------+
| sale_id | product_name | sale_date  |
+---------+--------------+------------+
| 1       | LCPHONE      | 2000-01-16 |
| 2       | LCPhone      | 2000-01-17 |
| 3       | LcPhOnE      | 2000-02-18 |
| 4       | LCKeyCHAiN   | 2000-02-19 |
| 5       | LCKeyChain   | 2000-02-28 |
| 6       | Matryoshka   | 2000-03-31 |
+---------+--------------+------------+
<strong>输出：</strong>
+--------------+-----------+-------+
| product_name | sale_date | total |
+--------------+-----------+-------+
| lckeychain   | 2000-02   | 2     |
| lcphone      | 2000-01   | 2     |
| lcphone      | 2000-02   | 1     |
| matryoshka   | 2000-03   | 1     |
+--------------+-----------+-------+
<strong>解释：</strong>
一月份售出 2 部 LcPhones。请注意，产品名称不区分大小写，且可能包含空格。 
二月份售出 2 个 LCKeychains 和 1 部 LCPhone。 
三月份售出 1 个 Matryoshka。</pre>

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
            LOWER(TRIM(product_name)) AS product_name,
            DATE_FORMAT(sale_date, '%Y-%m') AS sale_date
        FROM Sales
    )
SELECT product_name, sale_date, COUNT(1) AS total
FROM t
GROUP BY 1, 2
ORDER BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1544. 整理字符串](https://leetcode.cn/problems/make-the-string-great){#1544}

{{< tabs "1544" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeGood(self, s: str) -> str:
        stk = []
        for c in s:
            if not stk or abs(ord(stk[-1]) - ord(c)) != 32:
                stk.append(c)
            else:
                stk.pop()
        return "".join(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (sb.length() == 0 || Math.abs(sb.charAt(sb.length() - 1) - c) != 32) {
                sb.append(c);
            } else {
                sb.deleteCharAt(sb.length() - 1);
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
    string makeGood(string s) {
        string stk;
        for (char c : s) {
            if (stk.empty() || abs(stk.back() - c) != 32) {
                stk += c;
            } else {
                stk.pop_back();
            }
        }
        return stk;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeGood(s string) string {
	stk := []rune{}
	for _, c := range s {
		if len(stk) == 0 || abs(int(stk[len(stk)-1]-c)) != 32 {
			stk = append(stk, c)
		} else {
			stk = stk[:len(stk)-1]
		}
	}
	return string(stk)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由大小写英文字母组成的字符串 <code>s</code> 。</p>

<p>一个整理好的字符串中，两个相邻字符 <code>s[i]</code> 和 <code>s[i+1]</code>，其中 <code>0<= i <= s.length-2</code> ，要满足如下条件:</p>

<ul>
	<li>若 <code>s[i]</code> 是小写字符，则 <code>s[i+1]</code> 不可以是相同的大写字符。</li>
	<li>若 <code>s[i]</code> 是大写字符，则 <code>s[i+1]</code> 不可以是相同的小写字符。</li>
</ul>

<p>请你将字符串整理好，每次你都可以从字符串中选出满足上述条件的 <strong>两个相邻</strong> 字符并删除，直到字符串整理好为止。</p>

<p>请返回整理好的 <strong>字符串</strong> 。题目保证在给出的约束条件下，测试样例对应的答案是唯一的。</p>

<p><strong>注意：</strong>空字符串也属于整理好的字符串，尽管其中没有任何字符。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leEeetcode"
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>无论你第一次选的是 i = 1 还是 i = 2，都会使 "leEeetcode" 缩减为 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abBAcC"
<strong>输出：</strong>""
<strong>解释：</strong>存在多种不同情况，但所有的情况都会导致相同的结果。例如：
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "s"
<strong>输出：</strong>"s"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s</code> 只包含小写和大写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈模拟

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeGood(self, s: str) -> str:
        stk = []
        for c in s:
            if not stk or abs(ord(stk[-1]) - ord(c)) != 32:
                stk.append(c)
            else:
                stk.pop()
        return "".join(stk)
```

#### Java

```java
class Solution {
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (sb.length() == 0 || Math.abs(sb.charAt(sb.length() - 1) - c) != 32) {
                sb.append(c);
            } else {
                sb.deleteCharAt(sb.length() - 1);
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
    string makeGood(string s) {
        string stk;
        for (char c : s) {
            if (stk.empty() || abs(stk.back() - c) != 32) {
                stk += c;
            } else {
                stk.pop_back();
            }
        }
        return stk;
    }
};
```

#### Go

```go
func makeGood(s string) string {
	stk := []rune{}
	for _, c := range s {
		if len(stk) == 0 || abs(int(stk[len(stk)-1]-c)) != 32 {
			stk = append(stk, c)
		} else {
			stk = stk[:len(stk)-1]
		}
	}
	return string(stk)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1545. 找出第 N 个二进制字符串中的第 K 位](https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string){#1545}

{{< tabs "1545" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        def dfs(n: int, k: int) -> int:
            if k == 1:
                return 0
            if (k & (k - 1)) == 0:
                return 1
            m = 1 << n
            if k * 2 < m - 1:
                return dfs(n - 1, k)
            return dfs(n - 1, m - k) ^ 1

        return str(dfs(n, k))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char findKthBit(int n, int k) {
        return (char) ('0' + dfs(n, k));
    }

    private int dfs(int n, int k) {
        if (k == 1) {
            return 0;
        }
        if ((k & (k - 1)) == 0) {
            return 1;
        }
        int m = 1 << n;
        if (k * 2 < m - 1) {
            return dfs(n - 1, k);
        }
        return dfs(n - 1, m - k) ^ 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        function<int(int, int)> dfs = [&](int n, int k) {
            if (k == 1) {
                return 0;
            }
            if ((k & (k - 1)) == 0) {
                return 1;
            }
            int m = 1 << n;
            if (k * 2 < m - 1) {
                return dfs(n - 1, k);
            }
            return dfs(n - 1, m - k) ^ 1;
        };
        return '0' + dfs(n, k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthBit(n int, k int) byte {
	var dfs func(n, k int) int
	dfs = func(n, k int) int {
		if k == 1 {
			return 0
		}
		if k&(k-1) == 0 {
			return 1
		}
		m := 1 << n
		if k*2 < m-1 {
			return dfs(n-1, k)
		}
		return dfs(n-1, m-k) ^ 1
	}
	return byte('0' + dfs(n, k))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const findKthBit = (n: number, k: number): string =>
    String((((k / (k & -k)) >> 1) & 1) ^ (k & 1) ^ 1);
```
{{% /tab %}}
{{% tab "js" %}}
```js
const findKthBit = (n, k) => String((((k / (k & -k)) >> 1) & 1) ^ (k & 1) ^ 1);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>n</code> 和 <code>k</code>，二进制字符串  <code>S<sub>n</sub></code> 的形成规则如下：</p>

<ul>
	<li><code>S<sub>1</sub> = "0"</code></li>
	<li>当 <code>i > 1</code> 时，<code>S<sub>i</sub> = S<sub>i-1</sub> + "1" + reverse(invert(S<sub>i-1</sub>))</code></li>
</ul>

<p>其中 <code>+</code> 表示串联操作，<code>reverse(x)</code> 返回反转 <code>x</code> 后得到的字符串，而 <code>invert(x)</code> 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）。</p>

<p>例如，符合上述描述的序列的前 4 个字符串依次是：</p>

<ul>
	<li><code>S<sub>1 </sub>= "0"</code></li>
	<li><code>S<sub>2 </sub>= "0<strong>1</strong>1"</code></li>
	<li><code>S<sub>3 </sub>= "011<strong>1</strong>001"</code></li>
	<li><code>S<sub>4</sub> = "0111001<strong>1</strong>0110001"</code></li>
</ul>

<p>请你返回  <code>S<sub>n</sub></code> 的 <strong>第 <code>k</code> 位字符</strong> ，题目数据保证 <code>k</code> 一定在 <code>S<sub>n</sub></code> 长度范围以内。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>"0"
<strong>解释：</strong>S<sub>3</sub> 为 "<strong>0</strong>111001"，其第 1 位为 "0" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 11
<strong>输出：</strong>"1"
<strong>解释：</strong>S<sub>4</sub> 为 "0111001101<strong>1</strong>0001"，其第 11 位为 "1" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>"0"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 3
<strong>输出：</strong>"1"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= k <= 2<sup>n</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论 + 递归

我们可以发现，对于 $S_n$，其前半部分和 $S_{n-1}$ 是一样的，而后半部分是 $S_{n-1}$ 的反转取反。因此我们可以设计一个函数 $dfs(n, k)$，表示第 $n$ 个字符串的第 $k$ 位字符。答案即为 $dfs(n, k)$。

函数 $dfs(n, k)$ 的计算过程如下：

-   如果 $k = 1$，那么答案为 $0$；
-   如果 $k$ 是 $2$ 的幂次方，那么答案为 $1$；
-   如果 $k \times 2 \lt 2^n - 1$，说明 $k$ 在前半部分，答案为 $dfs(n - 1, k)$；
-   否则，答案为 $dfs(n - 1, 2^n - k) \oplus 1$，其中 $\oplus$ 表示异或运算。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为题目给定的 $n$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        def dfs(n: int, k: int) -> int:
            if k == 1:
                return 0
            if (k & (k - 1)) == 0:
                return 1
            m = 1 << n
            if k * 2 < m - 1:
                return dfs(n - 1, k)
            return dfs(n - 1, m - k) ^ 1

        return str(dfs(n, k))
```

#### Java

```java
class Solution {
    public char findKthBit(int n, int k) {
        return (char) ('0' + dfs(n, k));
    }

    private int dfs(int n, int k) {
        if (k == 1) {
            return 0;
        }
        if ((k & (k - 1)) == 0) {
            return 1;
        }
        int m = 1 << n;
        if (k * 2 < m - 1) {
            return dfs(n - 1, k);
        }
        return dfs(n - 1, m - k) ^ 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        function<int(int, int)> dfs = [&](int n, int k) {
            if (k == 1) {
                return 0;
            }
            if ((k & (k - 1)) == 0) {
                return 1;
            }
            int m = 1 << n;
            if (k * 2 < m - 1) {
                return dfs(n - 1, k);
            }
            return dfs(n - 1, m - k) ^ 1;
        };
        return '0' + dfs(n, k);
    }
};
```

#### Go

```go
func findKthBit(n int, k int) byte {
	var dfs func(n, k int) int
	dfs = func(n, k int) int {
		if k == 1 {
			return 0
		}
		if k&(k-1) == 0 {
			return 1
		}
		m := 1 << n
		if k*2 < m-1 {
			return dfs(n-1, k)
		}
		return dfs(n-1, m-k) ^ 1
	}
	return byte('0' + dfs(n, k))
}
```

#### TypeScript

```ts
function findKthBit(n: number, k: number): string {
    const dfs = (n: number, k: number): number => {
        if (k === 1) {
            return 0;
        }
        if ((k & (k - 1)) === 0) {
            return 1;
        }
        const m = 1 << n;
        if (k * 2 < m - 1) {
            return dfs(n - 1, k);
        }
        return dfs(n - 1, m - k) ^ 1;
    };
    return dfs(n, k).toString();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

<!-- tabs:start -->

#### TypeScript

```ts
const findKthBit = (n: number, k: number): string =>
    String((((k / (k & -k)) >> 1) & 1) ^ (k & 1) ^ 1);
```

#### JavaScript

```js
const findKthBit = (n, k) => String((((k / (k & -k)) >> 1) & 1) ^ (k & 1) ^ 1);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1546. 和为目标值且不重叠的非空子数组的最大数目](https://leetcode.cn/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target){#1546}

{{< tabs "1546" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        ans = 0
        i, n = 0, len(nums)
        while i < n:
            s = 0
            vis = {0}
            while i < n:
                s += nums[i]
                if s - target in vis:
                    ans += 1
                    break
                i += 1
                vis.add(s)
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            Set<Integer> vis = new HashSet<>();
            int s = 0;
            vis.add(0);
            while (i < n) {
                s += nums[i];
                if (vis.contains(s - target)) {
                    ++ans;
                    break;
                }
                ++i;
                vis.add(s);
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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> vis{{0}};
            int s = 0;
            while (i < n) {
                s += nums[i];
                if (vis.count(s - target)) {
                    ++ans;
                    break;
                }
                ++i;
                vis.insert(s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNonOverlapping(nums []int, target int) (ans int) {
	n := len(nums)
	for i := 0; i < n; i++ {
		s := 0
		vis := map[int]bool{0: true}
		for ; i < n; i++ {
			s += nums[i]
			if vis[s-target] {
				ans++
				break
			}
			vis[s] = true
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNonOverlapping(nums: number[], target: number): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = 0;
        const vis: Set<number> = new Set();
        vis.add(0);
        for (; i < n; ++i) {
            s += nums[i];
            if (vis.has(s - target)) {
                ++ans;
                break;
            }
            vis.add(s);
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

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;。</p>

<p>请你返回&nbsp;<strong>非空不重叠</strong>&nbsp;子数组的最大数目，且每个子数组中数字和都为 <code>target</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1,1], target = 2
<strong>输出：</strong>2
<strong>解释：</strong>总共有 2 个不重叠子数组（加粗数字表示） [<strong>1,1</strong>,1,<strong>1,1</strong>] ，它们的和为目标值 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-1,3,5,1,4,2,-9], target = 6
<strong>输出：</strong>2
<strong>解释：</strong>总共有 3 个子数组和为 6 。
([5,1], [4,2], [3,5,1,4,2,-9]) 但只有前 2 个是不重叠的。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [-2,6,6,3,5,4,1,2,8], target = 10
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [0,0,0], target = 0
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;=&nbsp;10^5</code></li>
	<li><code>-10^4 &lt;= nums[i] &lt;=&nbsp;10^4</code></li>
	<li><code>0 &lt;= target &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 前缀和 + 哈希表

我们遍历数组 $nums$，利用前缀和 + 哈希表的方法，寻找和为 $target$ 的子数组，若找到，则答案加一，然后我们将前缀和置为 $0$，继续遍历数组 $nums$，直到遍历完整个数组。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        ans = 0
        i, n = 0, len(nums)
        while i < n:
            s = 0
            vis = {0}
            while i < n:
                s += nums[i]
                if s - target in vis:
                    ans += 1
                    break
                i += 1
                vis.add(s)
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            Set<Integer> vis = new HashSet<>();
            int s = 0;
            vis.add(0);
            while (i < n) {
                s += nums[i];
                if (vis.contains(s - target)) {
                    ++ans;
                    break;
                }
                ++i;
                vis.add(s);
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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> vis{{0}};
            int s = 0;
            while (i < n) {
                s += nums[i];
                if (vis.count(s - target)) {
                    ++ans;
                    break;
                }
                ++i;
                vis.insert(s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxNonOverlapping(nums []int, target int) (ans int) {
	n := len(nums)
	for i := 0; i < n; i++ {
		s := 0
		vis := map[int]bool{0: true}
		for ; i < n; i++ {
			s += nums[i]
			if vis[s-target] {
				ans++
				break
			}
			vis[s] = true
		}
	}
	return
}
```

#### TypeScript

```ts
function maxNonOverlapping(nums: number[], target: number): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = 0;
        const vis: Set<number> = new Set();
        vis.add(0);
        for (; i < n; ++i) {
            s += nums[i];
            if (vis.has(s - target)) {
                ++ans;
                break;
            }
            vis.add(s);
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

# [1547. 切棍子的最小成本](https://leetcode.cn/problems/minimum-cost-to-cut-a-stick){#1547}

{{< tabs "1547" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.extend([0, n])
        cuts.sort()
        m = len(cuts)
        f = [[0] * m for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(i + 2, m):
                f[i][j] = inf
                for k in range(i + 1, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i])
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(int n, int[] cuts) {
        List<Integer> nums = new ArrayList<>();
        for (int x : cuts) {
            nums.add(x);
        }
        nums.add(0);
        nums.add(n);
        Collections.sort(nums);
        int m = nums.size();
        int[][] f = new int[m][m];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i + 2; j < m; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + nums.get(j) - nums.get(i));
                }
            }
        }
        return f[0][m - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        int f[110][110]{};
        for (int i = m - 1; ~i; --i) {
            for (int j = i + 2; j < m; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return f[0][m - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(n int, cuts []int) int {
	cuts = append(cuts, []int{0, n}...)
	sort.Ints(cuts)
	m := len(cuts)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
	}
	for i := m - 1; i >= 0; i-- {
		for j := i + 2; j < m; j++ {
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+cuts[j]-cuts[i])
			}
		}
	}
	return f[0][m-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(n: number, cuts: number[]): number {
    cuts.push(0);
    cuts.push(n);
    cuts.sort((a, b) => a - b);
    const m = cuts.length;
    const f: number[][] = Array.from({ length: m }, () => Array(m).fill(0));
    for (let i = m - 2; i >= 0; --i) {
        for (let j = i + 2; j < m; ++j) {
            f[i][j] = 1 << 30;
            for (let k = i + 1; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return f[0][m - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一根长度为 <code>n</code> 个单位的木棍，棍上从 <code>0</code> 到 <code>n</code> 标记了若干位置。例如，长度为 <strong>6</strong> 的棍子可以标记如下：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1547.Minimum%20Cost%20to%20Cut%20a%20Stick/images/statement.jpg" style="height: 111px; width: 521px;" /></p>

<p>给你一个整数数组 <code>cuts</code> ，其中 <code>cuts[i]</code> 表示你需要将棍子切开的位置。</p>

<p>你可以按顺序完成切割，也可以根据需要更改切割的顺序。</p>

<p>每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。</p>

<p>返回切棍子的 <strong>最小总成本</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1547.Minimum%20Cost%20to%20Cut%20a%20Stick/images/e1.jpg" style="height: 284px; width: 350px;" /></p>

<pre>
<strong>输入：</strong>n = 7, cuts = [1,3,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>按 [1, 3, 4, 5] 的顺序切割的情况如下所示：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1547.Minimum%20Cost%20to%20Cut%20a%20Stick/images/e11.jpg" style="height: 284px; width: 350px;" />
第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4 的棍子，最后切割长度为 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2 = 16）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 9, cuts = [5,6,1,4,2]
<strong>输出：</strong>22
<strong>解释：</strong>如果按给定的顺序切割，则总成本为 25 。总成本 <= 25 的切割顺序很多，例如，[4, 6, 5, 2, 1] 的总成本 = 22，是所有可能方案中成本最小的。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10^6</code></li>
	<li><code>1 <= cuts.length <= min(n - 1, 100)</code></li>
	<li><code>1 <= cuts[i] <= n - 1</code></li>
	<li><code>cuts</code> 数组中的所有整数都 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（区间 DP）

我们可以往切割点数组 $\textit{cuts}$ 中添加两个元素，分别是 $0$ 和 $n$，表示棍子的两端。然后我们对 $\textit{cuts}$ 数组进行排序，这样我们就可以将整个棍子切割为若干个区间，每个区间都有两个切割点。不妨设此时 $\textit{cuts}$ 数组的长度为 $m$。

接下来，我们定义 $\textit{f}[i][j]$ 表示切割区间 $[\textit{cuts}[i],..\textit{cuts}[j]]$ 的最小成本。

如果一个区间只有两个切割点，也就是说，我们无需切割这个区间，那么 $\textit{f}[i][j] = 0$。

否则，我们枚举区间的长度 $l$，其中 $l$ 等于切割点的数量减去 $1$。然后我们枚举区间的左端点 $i$，右端点 $j$ 可以由 $i + l$ 得到。对于每个区间，我们枚举它的切割点 $k$，其中 $i \lt k \lt j$，那么我们可以将区间 $[i, j]$ 切割为 $[i, k]$ 和 $[k, j]$，此时的成本为 $\textit{f}[i][k] + \textit{f}[k][j] + \textit{cuts}[j] - \textit{cuts}[i]$，我们取所有可能的 $k$ 中的最小值，即为 $\textit{f}[i][j]$ 的值。

最后，我们返回 $\textit{f}[0][m - 1]$。

时间复杂度 $O(m^3)$，空间复杂度 $O(m^2)$。其中 $m$ 为修改后的 $\textit{cuts}$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.extend([0, n])
        cuts.sort()
        m = len(cuts)
        f = [[0] * m for _ in range(m)]
        for l in range(2, m):
            for i in range(m - l):
                j = i + l
                f[i][j] = inf
                for k in range(i + 1, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i])
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int minCost(int n, int[] cuts) {
        List<Integer> nums = new ArrayList<>();
        for (int x : cuts) {
            nums.add(x);
        }
        nums.add(0);
        nums.add(n);
        Collections.sort(nums);
        int m = nums.size();
        int[][] f = new int[m][m];
        for (int l = 2; l < m; ++l) {
            for (int i = 0; i + l < m; ++i) {
                int j = i + l;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + nums.get(j) - nums.get(i));
                }
            }
        }
        return f[0][m - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        int f[110][110]{};
        for (int l = 2; l < m; ++l) {
            for (int i = 0; i + l < m; ++i) {
                int j = i + l;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return f[0][m - 1];
    }
};
```

#### Go

```go
func minCost(n int, cuts []int) int {
	cuts = append(cuts, []int{0, n}...)
	sort.Ints(cuts)
	m := len(cuts)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
	}
	for l := 2; l < m; l++ {
		for i := 0; i+l < m; i++ {
			j := i + l
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+cuts[j]-cuts[i])
			}
		}
	}
	return f[0][m-1]
}
```

#### TypeScript

```ts
function minCost(n: number, cuts: number[]): number {
    cuts.push(0, n);
    cuts.sort((a, b) => a - b);
    const m = cuts.length;
    const f: number[][] = Array.from({ length: m }, () => Array(m).fill(0));
    for (let l = 2; l < m; l++) {
        for (let i = 0; i < m - l; i++) {
            const j = i + l;
            f[i][j] = Infinity;
            for (let k = i + 1; k < j; k++) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return f[0][m - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（另一种枚举方式）

我们也可以从大到小枚举 $i$，从小到大枚举 $j$，这样可以保证在计算 $f[i][j]$ 时，状态 $f[i][k]$ 和 $f[k][j]$ 都已经被计算过了，其中 $i \lt k \lt j$。

时间复杂度 $O(m^3)$，空间复杂度 $O(m^2)$。其中 $m$ 为修改后的 $\textit{cuts}$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.extend([0, n])
        cuts.sort()
        m = len(cuts)
        f = [[0] * m for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(i + 2, m):
                f[i][j] = inf
                for k in range(i + 1, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i])
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int minCost(int n, int[] cuts) {
        List<Integer> nums = new ArrayList<>();
        for (int x : cuts) {
            nums.add(x);
        }
        nums.add(0);
        nums.add(n);
        Collections.sort(nums);
        int m = nums.size();
        int[][] f = new int[m][m];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i + 2; j < m; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + nums.get(j) - nums.get(i));
                }
            }
        }
        return f[0][m - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        int f[110][110]{};
        for (int i = m - 1; ~i; --i) {
            for (int j = i + 2; j < m; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return f[0][m - 1];
    }
};
```

#### Go

```go
func minCost(n int, cuts []int) int {
	cuts = append(cuts, []int{0, n}...)
	sort.Ints(cuts)
	m := len(cuts)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
	}
	for i := m - 1; i >= 0; i-- {
		for j := i + 2; j < m; j++ {
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+cuts[j]-cuts[i])
			}
		}
	}
	return f[0][m-1]
}
```

#### TypeScript

```ts
function minCost(n: number, cuts: number[]): number {
    cuts.push(0);
    cuts.push(n);
    cuts.sort((a, b) => a - b);
    const m = cuts.length;
    const f: number[][] = Array.from({ length: m }, () => Array(m).fill(0));
    for (let i = m - 2; i >= 0; --i) {
        for (let j = i + 2; j < m; ++j) {
            f[i][j] = 1 << 30;
            for (let k = i + 1; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return f[0][m - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1548. 图中最相似的路径 🔒](https://leetcode.cn/problems/the-most-similar-path-in-a-graph){#1548}

{{< tabs "1548" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostSimilar(
        self, n: int, roads: List[List[int]], names: List[str], targetPath: List[str]
    ) -> List[int]:
        g = [[] for _ in range(n)]
        for a, b in roads:
            g[a].append(b)
            g[b].append(a)
        m = len(targetPath)
        f = [[inf] * n for _ in range(m)]
        pre = [[-1] * n for _ in range(m)]
        for j, s in enumerate(names):
            f[0][j] = targetPath[0] != s
        for i in range(1, m):
            for j in range(n):
                for k in g[j]:
                    if (t := f[i - 1][k] + (targetPath[i] != names[j])) < f[i][j]:
                        f[i][j] = t
                        pre[i][j] = k
        k = 0
        mi = inf
        for j in range(n):
            if f[-1][j] < mi:
                mi = f[-1][j]
                k = j
        ans = [0] * m
        for i in range(m - 1, -1, -1):
            ans[i] = k
            k = pre[i][k]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> mostSimilar(int n, int[][] roads, String[] names, String[] targetPath) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] r : roads) {
            int a = r[0], b = r[1];
            g[a].add(b);
            g[b].add(a);
        }
        int m = targetPath.length;
        final int inf = 1 << 30;
        int[][] f = new int[m][n];
        int[][] pre = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(f[i], inf);
            Arrays.fill(pre[i], -1);
        }
        for (int j = 0; j < n; ++j) {
            f[0][j] = targetPath[0].equals(names[j]) ? 0 : 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    int t = f[i - 1][k] + (targetPath[i].equals(names[j]) ? 0 : 1);
                    if (t < f[i][j]) {
                        f[i][j] = t;
                        pre[i][j] = k;
                    }
                }
            }
        }
        int mi = inf, k = 0;
        for (int j = 0; j < n; ++j) {
            if (f[m - 1][j] < mi) {
                mi = f[m - 1][j];
                k = j;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = m - 1; i >= 0; --i) {
            ans.add(k);
            k = pre[i][k];
        }
        Collections.reverse(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<int> g[n];
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int m = targetPath.size();
        int f[m][n];
        int pre[m][n];
        memset(f, 0x3f, sizeof(f));
        memset(pre, -1, sizeof(pre));
        for (int j = 0; j < n; ++j) {
            f[0][j] = targetPath[0] != names[j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    int t = f[i - 1][k] + (targetPath[i] != names[j]);
                    if (t < f[i][j]) {
                        f[i][j] = t;
                        pre[i][j] = k;
                    }
                }
            }
        }
        int k = 0;
        int mi = 1 << 30;
        for (int j = 0; j < n; ++j) {
            if (f[m - 1][j] < mi) {
                mi = f[m - 1][j];
                k = j;
            }
        }
        vector<int> ans(m);
        for (int i = m - 1; ~i; --i) {
            ans[i] = k;
            k = pre[i][k];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostSimilar(n int, roads [][]int, names []string, targetPath []string) []int {
	g := make([][]int, n)
	for _, r := range roads {
		a, b := r[0], r[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	m := len(targetPath)
	const inf = 1 << 30
	f := make([][]int, m)
	pre := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		pre[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = inf
			pre[i][j] = -1
		}
	}
	for j, s := range names {
		if targetPath[0] != s {
			f[0][j] = 1
		} else {
			f[0][j] = 0
		}
	}
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			for _, k := range g[j] {
				t := f[i-1][k]
				if targetPath[i] != names[j] {
					t++
				}
				if t < f[i][j] {
					f[i][j] = t
					pre[i][j] = k
				}
			}
		}
	}
	mi, k := inf, 0
	for j := 0; j < n; j++ {
		if f[m-1][j] < mi {
			mi = f[m-1][j]
			k = j
		}
	}
	ans := make([]int, m)
	for i := m - 1; i >= 0; i-- {
		ans[i] = k
		k = pre[i][k]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostSimilar(
    n: number,
    roads: number[][],
    names: string[],
    targetPath: string[],
): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of roads) {
        g[a].push(b);
        g[b].push(a);
    }
    const m = targetPath.length;
    const f = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    const pre: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => -1));
    for (let j = 0; j < n; ++j) {
        f[0][j] = names[j] === targetPath[0] ? 0 : 1;
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (const k of g[j]) {
                const t = f[i - 1][k] + (names[j] === targetPath[i] ? 0 : 1);
                if (t < f[i][j]) {
                    f[i][j] = t;
                    pre[i][j] = k;
                }
            }
        }
    }
    let k = 0;
    let mi = Infinity;
    for (let j = 0; j < n; ++j) {
        if (f[m - 1][j] < mi) {
            mi = f[m - 1][j];
            k = j;
        }
    }
    const ans: number[] = Array(m).fill(0);
    for (let i = m - 1; ~i; --i) {
        ans[i] = k;
        k = pre[i][k];
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

<p>我们有&nbsp;<code>n</code>&nbsp;座城市和&nbsp;<code>m</code>&nbsp;条双向道路&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;连接城市&nbsp;<code>a<sub>i</sub></code>&nbsp;和城市&nbsp;<code>b<sub>i</sub></code>。每个城市的名称由字符串数组&nbsp;<code>names</code>&nbsp;中给出的三个大写英文字母组成。从任意城市&nbsp;<code>x</code>&nbsp;出发，你可以到达任意城市&nbsp;<code>y</code> ，其中&nbsp;<code>y != x</code>&nbsp;（即：城市和道路形成一张无向连通图）。</p>

<p>给定一个字符串数组&nbsp;<code>targetPath</code>，你需要找出图中与&nbsp;<code>targetPath</code>&nbsp;的<strong> 长度相同</strong> 且<strong> 编辑距离</strong><strong>最小</strong> 的路径。</p>

<p>你需要返回<em> </em><strong>编辑距离最小的路径中节点的顺序</strong><em> </em>。该路径应当与&nbsp;<code>targetPath</code>&nbsp;的长度相等，且路径需有效（即：&nbsp;<code>ans[i]</code>&nbsp;和&nbsp;<code>ans[i + 1]</code>&nbsp;间应存在直接连通的道路）。如果有多个答案，返回任意一个。</p>

<p><strong>编辑距离</strong> 的定义如下：</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1548.The%20Most%20Similar%20Path%20in%20a%20Graph/images/edit.jpg" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1548.The%20Most%20Similar%20Path%20in%20a%20Graph/images/e1.jpg" style="height: 300px; width: 213px;" /></p>

<pre>
<strong>输入：</strong>n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
<strong>输出：</strong>[0,2,4,2]
<strong>解释：</strong>[0,2,4,2], [0,3,0,2] 和 [0,3,1,2] 都是正确答案。
[0,2,4,2] 等价于 ["ATL","LAX","HND","LAX"] ，与 targetPath 的编辑距离 = 1。
[0,3,0,2] 等价于 ["ATL","DXB","ATL","LAX"] ，与 targetPath 的编辑距离 = 1。
[0,3,1,2] 等价于 ["ATL","DXB","PEK","LAX"] ，与 targetPath 的编辑距离 = 1。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1548.The%20Most%20Similar%20Path%20in%20a%20Graph/images/e2.jpg" style="height: 200px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
<strong>输出：</strong>[0,1,0,1,0,1,0,1]
<strong>解释：</strong>任意路径与 targetPath 的编辑距离都等于 8。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1548.The%20Most%20Similar%20Path%20in%20a%20Graph/images/e3.jpg" style="height: 106px; width: 600px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
<strong>输出：</strong>[3,4,5,4,3,2,1]
<strong>解释：</strong>[3,4,5,4,3,2,1] 是唯一与 targetPath 的编辑距离 = 0 的路径。
该路径等价于 ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>m == roads.length</code></li>
	<li><code>n - 1 &lt;= m &lt;= (n * (n - 1) / 2)</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub>&nbsp;</code></li>
	<li>给定的图保证是<strong>连通</strong>的，任意两个节点<strong>至多有一个</strong>直接连通的道路。</li>
	<li><code>names.length == n</code></li>
	<li><code>names[i].length == 3</code></li>
	<li><code>names[i]</code>&nbsp;包含大写英文字母。</li>
	<li>可能有两个名称<strong>相同</strong>的城市。</li>
	<li><code>1 &lt;= targetPath.length &lt;= 100</code></li>
	<li><code>targetPath[i].length == 3</code></li>
	<li><code>targetPath[i]</code> 由大写英文字母组成。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果路径中每个节点只可访问一次，你该如何修改你的答案？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们先根据给定的道路构建一个邻接表 $g$，其中 $g[i]$ 表示与城市 $i$ 直接相连的城市列表。

然后我们定义 $f[i][j]$ 表示 $targetPath$ 的第 $i$ 个城市与 $names$ 的第 $j$ 个城市匹配时，前 $i$ 个城市的最小编辑距离。

那么我们可以得到状态转移方程：

$$
f[i][j] = \min_{k \in g[j]} f[i - 1][k] + (targetPath[i] \neq names[j])
$$

在状态转移的过程中，我们记录下每个状态的前驱城市，最后根据前驱城市数组 $pre$ 从后往前还原出最优路径。

时间复杂度 $O(m \times n^2)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是 $targetPath$ 和 $names$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostSimilar(
        self, n: int, roads: List[List[int]], names: List[str], targetPath: List[str]
    ) -> List[int]:
        g = [[] for _ in range(n)]
        for a, b in roads:
            g[a].append(b)
            g[b].append(a)
        m = len(targetPath)
        f = [[inf] * n for _ in range(m)]
        pre = [[-1] * n for _ in range(m)]
        for j, s in enumerate(names):
            f[0][j] = targetPath[0] != s
        for i in range(1, m):
            for j in range(n):
                for k in g[j]:
                    if (t := f[i - 1][k] + (targetPath[i] != names[j])) < f[i][j]:
                        f[i][j] = t
                        pre[i][j] = k
        k = 0
        mi = inf
        for j in range(n):
            if f[-1][j] < mi:
                mi = f[-1][j]
                k = j
        ans = [0] * m
        for i in range(m - 1, -1, -1):
            ans[i] = k
            k = pre[i][k]
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> mostSimilar(int n, int[][] roads, String[] names, String[] targetPath) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] r : roads) {
            int a = r[0], b = r[1];
            g[a].add(b);
            g[b].add(a);
        }
        int m = targetPath.length;
        final int inf = 1 << 30;
        int[][] f = new int[m][n];
        int[][] pre = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(f[i], inf);
            Arrays.fill(pre[i], -1);
        }
        for (int j = 0; j < n; ++j) {
            f[0][j] = targetPath[0].equals(names[j]) ? 0 : 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    int t = f[i - 1][k] + (targetPath[i].equals(names[j]) ? 0 : 1);
                    if (t < f[i][j]) {
                        f[i][j] = t;
                        pre[i][j] = k;
                    }
                }
            }
        }
        int mi = inf, k = 0;
        for (int j = 0; j < n; ++j) {
            if (f[m - 1][j] < mi) {
                mi = f[m - 1][j];
                k = j;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = m - 1; i >= 0; --i) {
            ans.add(k);
            k = pre[i][k];
        }
        Collections.reverse(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<int> g[n];
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int m = targetPath.size();
        int f[m][n];
        int pre[m][n];
        memset(f, 0x3f, sizeof(f));
        memset(pre, -1, sizeof(pre));
        for (int j = 0; j < n; ++j) {
            f[0][j] = targetPath[0] != names[j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    int t = f[i - 1][k] + (targetPath[i] != names[j]);
                    if (t < f[i][j]) {
                        f[i][j] = t;
                        pre[i][j] = k;
                    }
                }
            }
        }
        int k = 0;
        int mi = 1 << 30;
        for (int j = 0; j < n; ++j) {
            if (f[m - 1][j] < mi) {
                mi = f[m - 1][j];
                k = j;
            }
        }
        vector<int> ans(m);
        for (int i = m - 1; ~i; --i) {
            ans[i] = k;
            k = pre[i][k];
        }
        return ans;
    }
};
```

#### Go

```go
func mostSimilar(n int, roads [][]int, names []string, targetPath []string) []int {
	g := make([][]int, n)
	for _, r := range roads {
		a, b := r[0], r[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	m := len(targetPath)
	const inf = 1 << 30
	f := make([][]int, m)
	pre := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		pre[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = inf
			pre[i][j] = -1
		}
	}
	for j, s := range names {
		if targetPath[0] != s {
			f[0][j] = 1
		} else {
			f[0][j] = 0
		}
	}
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			for _, k := range g[j] {
				t := f[i-1][k]
				if targetPath[i] != names[j] {
					t++
				}
				if t < f[i][j] {
					f[i][j] = t
					pre[i][j] = k
				}
			}
		}
	}
	mi, k := inf, 0
	for j := 0; j < n; j++ {
		if f[m-1][j] < mi {
			mi = f[m-1][j]
			k = j
		}
	}
	ans := make([]int, m)
	for i := m - 1; i >= 0; i-- {
		ans[i] = k
		k = pre[i][k]
	}
	return ans
}
```

#### TypeScript

```ts
function mostSimilar(
    n: number,
    roads: number[][],
    names: string[],
    targetPath: string[],
): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of roads) {
        g[a].push(b);
        g[b].push(a);
    }
    const m = targetPath.length;
    const f = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    const pre: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => -1));
    for (let j = 0; j < n; ++j) {
        f[0][j] = names[j] === targetPath[0] ? 0 : 1;
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (const k of g[j]) {
                const t = f[i - 1][k] + (names[j] === targetPath[i] ? 0 : 1);
                if (t < f[i][j]) {
                    f[i][j] = t;
                    pre[i][j] = k;
                }
            }
        }
    }
    let k = 0;
    let mi = Infinity;
    for (let j = 0; j < n; ++j) {
        if (f[m - 1][j] < mi) {
            mi = f[m - 1][j];
            k = j;
        }
    }
    const ans: number[] = Array(m).fill(0);
    for (let i = m - 1; ~i; --i) {
        ans[i] = k;
        k = pre[i][k];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1549. 每件商品的最新订单 🔒](https://leetcode.cn/problems/the-most-recent-orders-for-each-product){#1549}

{{< tabs "1549" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY order_date DESC
            ) AS rk
        FROM
            Orders
            JOIN Products USING (product_id)
    )
SELECT product_name, product_id, order_id, order_date
FROM T
WHERE rk = 1
ORDER BY 1, 2, 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id 是该表主键.
该表包含消费者的信息.
</pre>

<p>&nbsp;</p>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| product_id    | int     |
+---------------+---------+
order_id 是该表主键.
该表包含消费者customer_id产生的订单.
不会有商品被相同的用户在一天内下单<strong>超过一次</strong>.</pre>

<p>&nbsp;</p>

<p>表: <code>Products</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id 是该表主键.
该表包含所有商品的信息.
</pre>

<p>&nbsp;</p>

<p>写一个解决方案,&nbsp;找到每件商品的最新订单(可能有多个).</p>

<p>返回的结果以&nbsp;<code>product_name</code> <strong>升序排列</strong>,&nbsp;如果有排序相同,&nbsp;再以&nbsp;<code>product_id</code> <strong>升序</strong>排列.&nbsp;如果还有排序相同,&nbsp;再以&nbsp;<code>order_id</code> <strong>升序</strong>排列.</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong>
<code>Customers表：</code>
+-------------+-----------+
| customer_id | name      |
+-------------+-----------+
| 1           | Winston   |
| 2           | Jonathan  |
| 3           | Annabelle |
| 4           | Marwan    |
| 5           | Khaled    |
+-------------+-----------+
<code>Orders表：</code>
+----------+------------+-------------+------------+
| order_id | order_date | customer_id | product_id |
+----------+------------+-------------+------------+
| 1        | 2020-07-31 | 1           | 1          |
| 2        | 2020-07-30 | 2           | 2          |
| 3        | 2020-08-29 | 3           | 3          |
| 4        | 2020-07-29 | 4           | 1          |
| 5        | 2020-06-10 | 1           | 2          |
| 6        | 2020-08-01 | 2           | 1          |
| 7        | 2020-08-01 | 3           | 1          |
| 8        | 2020-08-03 | 1           | 2          |
| 9        | 2020-08-07 | 2           | 3          |
| 10       | 2020-07-15 | 1           | 2          |
+----------+------------+-------------+------------+
<code>Products表：</code>
+------------+--------------+-------+
| product_id | product_name | price |
+------------+--------------+-------+
| 1          | keyboard     | 120   |
| 2          | mouse        | 80    |
| 3          | screen       | 600   |
| 4          | hard disk    | 450   |
+------------+--------------+-------+
<strong>输出：</strong>
+--------------+------------+----------+------------+
| product_name | product_id | order_id | order_date |
+--------------+------------+----------+------------+
| keyboard     | 1          | 6        | 2020-08-01 |
| keyboard     | 1          | 7        | 2020-08-01 |
| mouse        | 2          | 8        | 2020-08-03 |
| screen       | 3          | 3        | 2020-08-29 |
+--------------+------------+----------+------------+
<strong>解释：</strong>
keyboard 的最新订单在2020-08-01, 在这天有两次下单.
mouse 的最新订单在2020-08-03, 在这天只有一次下单.
screen 的最新订单在2020-08-29, 在这天只有一次下单.
hard disk 没有被下单, 我们不把它包含在结果表中.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 窗口函数

我们可以使用等值连接，将 `Orders` 表和 `Products` 表按照 `product_id` 连接起来，然后使用窗口函数 `rank()`，对 `Orders` 表中的每个 `product_id` 进行分组，按照 `order_date` 降序排列，然后取出每个分组中排名第一的记录。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY order_date DESC
            ) AS rk
        FROM
            Orders
            JOIN Products USING (product_id)
    )
SELECT product_name, product_id, order_id, order_date
FROM T
WHERE rk = 1
ORDER BY 1, 2, 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
