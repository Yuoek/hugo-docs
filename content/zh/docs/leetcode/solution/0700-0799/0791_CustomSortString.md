---
title: "0791_CustomSortString"
date: 2025-10-06T00:42:37+08:00
weight: 0791
tags: [哈希表, 字符串, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [791. 自定义字符串排序](https://leetcode.cn/problems/custom-sort-string)

[English Version](../en/0791-91/0791_CustomSortString)

## 题目描述

<!-- description:start -->

<p>给定两个字符串 <code>order</code> 和 <code>s</code> 。<code>order</code> 的所有字母都是 <strong>唯一</strong> 的，并且以前按照一些自定义的顺序排序。</p>

<p>对 <code>s</code> 的字符进行置换，使其与排序的&nbsp;<code>order</code>&nbsp;相匹配。更具体地说，如果在&nbsp;<code>order</code>&nbsp;中的字符 <code>x</code> 出现字符 <code>y</code> 之前，那么在排列后的字符串中， <code>x</code>&nbsp;也应该出现在 <code>y</code> 之前。</p>

<p>返回 <em>满足这个性质的 <code>s</code> 的任意一种排列&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> order = "cba", s = "abcd"
<strong>输出:</strong> "cbad"
<strong>解释:</strong> 
"a"、"b"、"c"是按顺序出现的，所以"a"、"b"、"c"的顺序应该是"c"、"b"、"a"。
因为"d"不是按顺序出现的，所以它可以在返回的字符串中的任何位置。"dcba"、"cdba"、"cbda"也是有效的输出。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> order = "cbafg", s = "abcd"
<strong>输出:</strong> "cbad"
解释：字符 "b"、"c" 和 "a" 规定了 s 中字符的顺序。s 中的字符 "d" 没有在 order 中出现，所以它的位置是弹性的。

按照出现的顺序，s 中的 "b"、"c"、"a" 应排列为"b"、"c"、"a"。"d" 可以放在任何位置，因为它没有按顺序排列。输出 "bcad" 遵循这一规则。其他排序如 "dbca" 或 "bcda" 也是有效的，只要维持 "b"、"c"、"a" 的顺序。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= order.length &lt;= 26</code></li>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>order</code>&nbsp;和&nbsp;<code>s</code>&nbsp;由小写英文字母组成</li>
	<li><code>order</code>&nbsp;中的所有字符都 <strong>不同</strong></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：自定义排序

一种比较直接的思路是，用哈希表或数组 $d$ 记录字符串 $order$ 中每个字符的位置，然后对字符串 $s$ 中每个字符按照其在 $d$ 中的位置进行排序。如果某个字符不在 $d$ 中，我们可以将其位置置为 $0$。

时间复杂度 $O(m + n\times \log n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是字符串 $order$ 和 $s$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字符计数

我们还可以先统计 $s$ 中每个字符的出现次数，存储在 $cnt$ 数组中。

然后把字符串 $s$ 在 $order$ 中出现的字符按照 $order$ 中的顺序排序，添加到结果字符串中。最后把剩余的字符直接追加到结果字符串中。

时间复杂度 $O(m+n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是字符串 $order$ 和 $s$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        cnt = Counter(s)
        ans = []
        for c in order:
            ans.append(c * cnt[c])
            cnt[c] = 0
        for c, v in cnt.items():
            ans.append(c * v)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String customSortString(String order, String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < order.length(); ++i) {
            char c = order.charAt(i);
            while (cnt[c - 'a']-- > 0) {
                ans.append(c);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (cnt[i]-- > 0) {
                ans.append((char) ('a' + i));
            }
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
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        string ans;
        for (char& c : order)
            while (cnt[c - 'a']-- > 0) ans += c;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0) ans += string(cnt[i], i + 'a');
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func customSortString(order string, s string) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	ans := []rune{}
	for _, c := range order {
		for cnt[c-'a'] > 0 {
			ans = append(ans, c)
			cnt[c-'a']--
		}
	}
	for i, v := range cnt {
		for j := 0; j < v; j++ {
			ans = append(ans, rune('a'+i))
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function customSortString(order: string, s: string): string {
    const toIndex = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const count = new Array(26).fill(0);
    for (const c of s) {
        count[toIndex(c)]++;
    }
    const ans: string[] = [];
    for (const c of order) {
        const i = toIndex(c);
        ans.push(c.repeat(count[i]));
        count[i] = 0;
    }
    for (let i = 0; i < 26; i++) {
        if (!count[i]) continue;
        ans.push(String.fromCharCode('a'.charCodeAt(0) + i).repeat(count[i]));
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut count = [0; 26];
        for c in s.as_bytes() {
            count[(c - b'a') as usize] += 1;
        }
        let mut ans = String::new();
        for c in order.as_bytes() {
            for _ in 0..count[(c - b'a') as usize] {
                ans.push(char::from(*c));
            }
            count[(c - b'a') as usize] = 0;
        }
        for i in 0..count.len() {
            for _ in 0..count[i] {
                ans.push(char::from(b'a' + (i as u8)));
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        cnt = Counter(s)
        ans = []
        for c in order:
            ans.append(c * cnt[c])
            cnt[c] = 0
        for c, v in cnt.items():
            ans.append(c * v)
        return ''.join(ans)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String customSortString(String order, String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < order.length(); ++i) {
            char c = order.charAt(i);
            while (cnt[c - 'a']-- > 0) {
                ans.append(c);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (cnt[i]-- > 0) {
                ans.append((char) ('a' + i));
            }
        }
        return ans.toString();
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        string ans;
        for (char& c : order)
            while (cnt[c - 'a']-- > 0) ans += c;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0) ans += string(cnt[i], i + 'a');
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}